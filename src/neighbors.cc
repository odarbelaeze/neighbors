#include <iostream>
#include <fstream>
#include <map>

#include "json/json.h"

#include "Coordinate.h"
#include "Logger.h"
#include "Node.h"
#include "NodeRepo.h"

struct Interaction
{
    double cut;
    double exchange;
};

int main(int argc, char *argv[])
{
    // Set up the "singleton"

    auto logger = Logger();

    // Read the configuration file

    Json::Value root;
    Json::Reader reader;

    {
        std::ifstream conf("neighbors.json");
        bool success = reader.parse(conf, root);
        if (!success)
        {
            logger.error("Failed to parse configuration")
                  .error(reader.getFormattedErrorMessages());
            return 1;
        }
    }

    // gather the interactions from the configuration file

    std::map<std::string, Interaction> interactions;

    for (auto&& interaction : root["interactions"].getMemberNames())
    {
        interactions[interaction] = Interaction {
            root["interactions"][interaction].get("cut", 0.0).asDouble(),
            root["interactions"][interaction].get("exchange", 0.0).asDouble(),
        };
    }

    // Define the max_cut of the interactions

    double max_cut = 0.0;  // Can't have negative values

    for (auto&& interaction : interactions)
    {
        if (interaction.second.cut > max_cut)
        {
            max_cut = interaction.second.cut;
        }
    }

    logger.info("Max cut", max_cut);

    // Take in the inputs and store the in the node repo

    NodeRepo repo;

    {
        std::ifstream input(root.get("input", "input").asString());
        size_t id = 0;
        double x, y, z;
        std::string type;
        while (input >> x >> y >> z >> type)
        {
            repo.insert(Node(id++, type, {x, y, z}));
        }
    }

    repo.optimize();

    size_t interaction_id = 0;

    for (auto&& node : repo)
    {
        auto around = repo.findWithinSphere(node, max_cut);
        for (auto&& other : around)
        {
            if (node == other) continue;
            std::string key = node.data()->type() + "-" + other.data()->type();
            bool interact = interactions.find(key) != interactions.end();
            if (interact)
            {
                auto interaction = interactions.at(key);
                if (node.distanceTo(other) <= interaction.cut) {
                    logger.log(interaction_id++, node.id(), other.id(), interaction.exchange);
                }
            }
        }
    }

    return 0;
}


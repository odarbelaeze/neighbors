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
            logger.error("Failed to parse configuration");
            logger.error( reader.getFormattedErrorMessages());
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

    std::cout << "Max cut " << max_cut << std::endl;

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

    return 0;
}


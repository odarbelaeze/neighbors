#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <valarray>

#include "Logger.h"
#include "Node.h"
#include "NodeRepo.h"

int main(int argc, char *argv[])
{
    NodeRepo repo;
    Logger logger;

    logger.log("Hola que hace");
    logger.info("Hola que hace");
    logger.error("Hola que hace");
    logger.warning("Hola que hace");

    return 0;
}


#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <valarray>

#include "Logger.h"

int main(int argc, char *argv[])
{
    Logger logger;

    logger.log("Hola que hace");
    logger.info("Hola que hace");
    logger.error("Hola que hace");
    logger.warning("Hola que hace");

    return 0;
}


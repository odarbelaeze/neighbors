#include "Logger.h"

Logger::Logger(std::ostream& target, std::string separator)
    : _target(target), _sep(separator)
{}


Logger::~Logger()
{}


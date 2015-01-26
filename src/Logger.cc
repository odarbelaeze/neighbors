#include "Logger.h"

Logger::Logger(std::ostream& target)
    : target(target)
{}


Logger::~Logger()
{}


Logger& Logger::log(const std::string& message)
{
    target << message
           << std::endl;
    return *this;
}


Logger& Logger::info(const std::string& message)
{
    target << termcolor::green
           << message
           << termcolor::reset
           << std::endl;
    return *this;
}


Logger& Logger::warming(const std::string& message)
{
    target << termcolor::grey
           << termcolor::on_yellow
           << message
           << termcolor::reset
           << std::endl;
    return *this;
}


Logger& Logger::error(const std::string& message)
{
    target << termcolor::white
           << termcolor::on_red
           << message
           << termcolor::reset
           << std::endl;
    return *this;
}


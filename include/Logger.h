/**
 * @file Logger.h
 * @brief Defines a Logger class
 * @author Oscar David Arbeláez
 * @version 0.0.1
 * @date 2015-01-23
 */

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <iostream>
#include <ostream>

#include "termcolor/include/termcolor/termcolor.hpp"

/**
 * @brief Prints formated text to the console according to the meaning
 */
class Logger
{
public:
    /**
     * @brief Creates a Logger instance given an ostream target
     *
     * @param target
     */
    Logger (std::ostream& target=std::cout);

    virtual ~Logger ();

    /**
     * @brief Logs the message to the target without accent.
     *
     * @param message
     *
     * @return this logger instance for a fluent API
     */
    Logger& log(const std::string& message);

    /**
     * @brief Logs the message to the target with information accent.
     *
     * @param message
     *
     * @return this logger instance for a fluent API
     */
    Logger& info(const std::string& message);

    /**
     * @brief Logs the message to the target with warning accent.
     *
     * @param message
     *
     * @return this logger instance for a fluent API
     */
    Logger& warning(const std::string& message);

    /**
     * @brief Logs the message to the target with error accent.
     *
     * @param message
     *
     * @return this logger instance for a fluent API
     */
    Logger& error(const std::string& message);

protected:
    std::ostream& target;

};

#endif

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
#include <string>
#include <ostream>

#include "termcolor/termcolor.hpp"

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
         * @param separator
         */
        Logger (std::ostream& target=std::cout, std::string separator = " ");

        /**
         * @brief Destroys the logger
         */
        virtual ~Logger ();

        /**
         * @brief Logs the message to the target without accent.
         *
         * @param message
         * @return this logger instance for a fluent API
         */
        template<typename Type>
        Logger& log(Type message)
        {
            _target << message << std::endl;
            return *this;
        }

        /**
         * @brief Logs the message to the target
         *
         * @param message
         * @param messages
         *
         * @return This Logger instance for a fluent API
         */
        template<typename Head, typename ...Tail>
        Logger& log(Head message, Tail... messages)
        {
            _target << message << _sep;
            return log<Tail...>(messages...);
        }

        /**
         * @brief Logs the message to the target with information accent.
         *
         * @param message
         * @return this logger instance for a fluent API
         */
        template<typename Type>
        Logger& info(Type message)
        {
            _target << message
                   << termcolor::reset
                   << std::endl;
            return *this;
        }

        /**
         * @brief Logs the message to the target with information accent.
         *
         * @param message
         * @param messages
         *
         * @return This Logger instance for a fluent API
         */
        template<typename Head, typename ...Tail>
        Logger& info(Head message, Tail... messages)
        {
            _target << termcolor::green
                    << message << _sep;
            return info<Tail...>(messages...);
        }

        /**
         * @brief Logs the message to the target with warning accent.
         *
         * @param message
         * @return this logger instance for a fluent API
         */
        template<typename Type>
        Logger& warning(Type message)
        {
            _target << message
                   << termcolor::reset
                   << std::endl;
            return *this;
        }

        /**
         * @brief Logs the message to the target with warning accent.
         *
         * @param message
         * @param messages
         *
         * @return This Logger instance for a fluent API
         */
        template<typename Head, typename ...Tail>
        Logger& warnin(Head message, Tail... messages)
        {
            _target << termcolor::grey
                    << termcolor::on_yellow
                    << message << _sep;
            return warning<Tail...>(messages...);
        }

        /**
         * @brief Logs the message to the target with error accent.
         *
         * @param message
         * @return this logger instance for a fluent API
         */
        template<typename Type>
        Logger& error(Type message)
        {
            _target << message
                   << termcolor::reset
                   << std::endl;
            return *this;
        }

        /**
         * @brief Logs the message to the target with warning accent.
         *
         * @param message
         * @param messages
         *
         * @return This Logger instance for a fluent API
         */
        template<typename Head, typename ...Tail>
        Logger& error(Head message, Tail... messages)
        {
            _target << termcolor::white
                    << termcolor::on_red
                    << message << _sep;
            return error<Tail...>(messages...);
        }

    protected:
        /**
         * @brief std::ostream reference of where to log
         */
        std::ostream& _target;

        /**
         * @brief String that separates two adjacent registers
         */
        std::string _sep;

};

#endif

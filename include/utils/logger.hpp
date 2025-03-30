#ifndef PROJEKT_LOGGER_HPP
#define PROJEKT_LOGGER_HPP

#include <string>

class Logger {
public:
    enum class Level {
        INFO,
        WARNING,
        ERROR
    };

    static void log(Level level, const std::string& message);
};

#endif // PROJEKT_LOGGER_HPP
#ifndef PROJEKT_LOGGER_HPP
#define PROJEKT_LOGGER_HPP

// Logger class for logging messages with different severity levels
class Logger {
public:
    // Enum class for log levels
    enum class Level {
        INFO,       // Informational messages
        WARNING,    // Warning messages
        ERROR       // Error messages
    };

    // Static method to log a message with a specified log level
    static void log(Level level, const char* message);
};

#endif // PROJEKT_LOGGER_HPP
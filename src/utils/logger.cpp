#include "utils/logger.h"
#include <iostream>

// Method to log messages with different severity levels
void Logger::log(Level level, const char* message) {
    switch (level) {
        case Level::INFO:
            //std::cout << "[INFO] " << message << std::endl; // Log informational messages
            break;
        case Level::WARNING:
            //std::cout << "[WARNING] " << message << std::endl; // Log warning messages
            break;
        case Level::ERROR:
            std::cerr << "[ERROR] " << message << std::endl; // Log error messages
            break;
    }
}
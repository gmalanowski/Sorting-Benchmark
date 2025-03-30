#include "../../include/utils/logger.hpp"
#include <iostream>

void Logger::log(Level level, const std::string& message) {
    switch (level) {
        case Level::INFO:
            std::cout << "[INFO] " << message << std::endl;
            break;
        case Level::WARNING:
            std::cout << "[WARNING] " << message << std::endl;
            break;
        case Level::ERROR:
            std::cerr << "[ERROR] " << message << std::endl;
            break;
    }
}
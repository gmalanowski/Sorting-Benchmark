#include <iostream>
#include <string>
#include "../include/utils/helpers.hpp"
#include "../include/utils/logger.hpp"
#include "../include/data/board_game.hpp"

int main(int argc, char* argv[]) {
    Logger::log(Logger::Level::INFO, "Program started");

    if (argc < 2) {
        Logger::log(Logger::Level::WARNING, "Not enough arguments provided");
        printHelp();
        return 1;
    }

    std::string mode = argv[1];
    if (mode == "--help") {
        printHelp();
        return 0;
    } else if (mode == "--file") {
        if (argc < 5) {
            Logger::log(Logger::Level::WARNING, "Not enough arguments for file mode");
            printHelp();
            return 1;
        }

        int algorithm = std::stoi(argv[2]);
        int type = std::stoi(argv[3]);
        std::string inputFile = argv[4];
        std::string outputFile = (argc == 6) ? argv[5] : "";

        switch (type) {
            case 0:
                handleFileMode<int>(algorithm, inputFile, outputFile);
                break;
            case 1:
                handleFileMode<float>(algorithm, inputFile, outputFile);
                break;
            case 2:
                handleFileMode<double>(algorithm, inputFile, outputFile);
                break;
            case 3:
                handleFileMode<char>(algorithm, inputFile, outputFile);
                break;
            case 4:
                handleFileMode<BoardGame>(algorithm, inputFile, outputFile);
                break;
            default:
                Logger::log(Logger::Level::ERROR, "Unknown type: " + std::to_string(type));
                std::cerr << "Unknown type: " << type << std::endl;
                return 1;
        }
    } else if (mode == "--test") {
        if (argc < 6) {
            Logger::log(Logger::Level::WARNING, "Not enough arguments for test mode");
            printHelp();
            return 1;
        }

        int algorithm = std::stoi(argv[2]);
        int type = std::stoi(argv[3]);
        size_t size = std::stoul(argv[4]);
        std::string outputFile = argv[5];

        switch (type) {
            case 0:
                handleTestMode<int>(algorithm, size, outputFile);
                break;
            case 1:
                handleTestMode<float>(algorithm, size, outputFile);
                break;
            case 2:
                handleTestMode<double>(algorithm, size, outputFile);
                break;
            case 3:
                handleTestMode<char>(algorithm, size, outputFile);
                break;
            case 4:
                handleTestMode<BoardGame>(algorithm, size, outputFile);
                break;
            default:
                Logger::log(Logger::Level::ERROR, "Unknown type: " + std::to_string(type));
                std::cerr << "Unknown type: " << type << std::endl;
                return 1;
        }
    } else {
        Logger::log(Logger::Level::WARNING, "Unknown mode: " + mode);
        printHelp();
        return 1;
    }

    Logger::log(Logger::Level::INFO, "Program finished successfully");
    return 0;
}
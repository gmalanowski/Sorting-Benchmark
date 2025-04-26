#include <iostream>
#include "utils/helpers.h"
#include "utils/logger.h"
#include "data/board_game.h"

int main(int argc, char* argv[]) {
    Logger::log(Logger::Level::INFO, "Program started"); // Log the start of the program

    if (argc < 2) {
        Logger::log(Logger::Level::WARNING, "Not enough arguments provided"); // Log a warning if not enough arguments are provided
        printHelp(); // Print the help message
        return 1;
    }

    std::string mode = argv[1];
    if (mode == "--help") {
        printHelp(); // Print the help message if the mode is --help
        return 0;
    } else if (mode == "--file") {
        if (argc < 6) {
            Logger::log(Logger::Level::WARNING, "Not enough arguments for file mode"); // Log a warning if not enough arguments for file mode
            printHelp(); // Print the help message
            return 1;
        }

        int algorithm = std::stoi(argv[2]); // Parse the algorithm argument
        int type = std::stoi(argv[3]); // Parse the type argument
        const char* inputFile = argv[4]; // Get the input file name
        const char* outputFile = argv[5]; // Get the output file name if provided
        int optional = (argc >= 7) ? std::stoi(argv[6]) : 0; // Get the optional level if provided
        const int iterations = (argc >= 8) ? std::stoi(argv[7]) : 100; // Get the number of interations if provited

        switch (type) {
            case 0:
                handleFileMode<int>(algorithm, inputFile, outputFile, optional, iterations); // Handle file mode for int type
                break;
            case 1:
                handleFileMode<float>(algorithm, inputFile, outputFile, optional, iterations); // Handle file mode for float type
                break;
            case 2:
                handleFileMode<double>(algorithm, inputFile, outputFile, optional, iterations); // Handle file mode for double type
                break;
            case 3:
                handleFileMode<char>(algorithm, inputFile, outputFile, optional, iterations); // Handle file mode for char type
                break;
            case 4:
                handleFileMode<BoardGame>(algorithm, inputFile, outputFile, optional, iterations); // Handle file mode for BoardGame type
                break;
            default:
                Logger::log(Logger::Level::ERROR, ("Unknown type: " + std::to_string(type)).c_str()); // Log an error if the type is unknown
                std::cerr << "Unknown type: " << type << std::endl;
                return 1;
        }
    } else if (mode == "--test") {
        if (argc < 6) {
            Logger::log(Logger::Level::WARNING, "Not enough arguments for test mode"); // Log a warning if not enough arguments for test mode
            printHelp(); // Print the help message
            return 1;
        }

        int algorithm = std::stoi(argv[2]); // Parse the algorithm argument
        int type = std::stoi(argv[3]); // Parse the type argument
        size_t size = std::stoul(argv[4]); // Parse the size argument
        const char* outputFile = argv[5]; // Get the output file name
        int optional = (argc >= 7) ? std::stoi(argv[6]) : 0; // Get the drunkenness level if provided
        const int iterations = (argc >= 8) ? std::stoi(argv[7]) : 100; // Get the number of interations if provited

        switch (type) {
            case 0:
                handleTestMode<int>(algorithm, size, outputFile, optional, iterations); // Handle test mode for int type
                break;
            case 1:
                handleTestMode<float>(algorithm, size, outputFile, optional, iterations); // Handle test mode for float type
                break;
            case 2:
                handleTestMode<double>(algorithm, size, outputFile, optional, iterations); // Handle test mode for double type
                break;
            case 3:
                handleTestMode<char>(algorithm, size, outputFile, optional, iterations); // Handle test mode for char type
                break;
            case 4:
                handleTestMode<BoardGame>(algorithm, size, outputFile, optional, iterations); // Handle test mode for BoardGame type
                break;
            default:
                Logger::log(Logger::Level::ERROR, ("Unknown type: " + std::to_string(type)).c_str()); // Log an error if the type is unknown
                std::cerr << "Unknown type: " << type << std::endl;
                return 1;
        }
    } else {
        Logger::log(Logger::Level::WARNING, ("Unknown mode: " + mode).c_str()); // Log a warning if the mode is unknown
        printHelp(); // Print the help message
        return 1;
    }

    Logger::log(Logger::Level::INFO, "Program finished successfully"); // Log the successful completion of the program
    return 0;
}
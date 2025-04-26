#include "utils/helpers.h"
#include "utils/Timer.h"
#include "utils/file_manager.h"
#include "utils/logger.h"
#include "sort_factory.h"
#include "sort/heap_sort.h"
#include "sort/insertion_sort.h"
#include "sort/quick_sort.h"
#include "sort/shell_sort.h"
#include "sort/drunk_insertion_sort.h"
#include "data/board_game.h"
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

// Function to print the help message
void printHelp() {
    Logger::log(Logger::Level::INFO, "Displaying help message");
    std::cout << "FILE TEST MODE:\n"
              << "\tUsage:\n"
              << "\t\t./sorter --file <algorithm> <type> <inputFile> [outputFile] [option]\n"
              << "\t<algorithm>\t Sorting algorithm to use (e.g., 0 - Heap, 1 - Insertion, 2 - Quick, 3 - Shell, 4 - Drunk Insertion).\n"
              << "\t<type>\t Data type to load (e.g., 0 - int, 1 - float, 2 - double, 3 - char, 4 - BoardGame).\n"
              << "\t<inputFile>\t Input file containing the data to be sorted.\n"
              << "\t<outputFile>\t The sorted values will be saved to this file.\n"
              << "\t[option]\t Optional parameter: drunkenness level for Drunk Insertion Sort (0 - 100), gaps for Shell Sort (0 - 10), pivot type for Quick Sort.\n"
              << "\t[iterations]\t Number of iterations for the sorting process (default is 100).\n"
              << "BENCHMARK MODE:\n"
              << "\tUsage:\n"
              << "\t\t./sorter --test <algorithm> <type> <size> <outputFile> [option]\n"
              << "\t<algorithm>\t Sorting algorithm to use (e.g., 0 - Heap, 1 - Insertion, 2 - Quick, 3 - Shell, 4 - Drunk Insertion).\n"
              << "\t<type>\t Data type to generate (e.g., 0 - int, 1 - float, 2 - double, 3 - char, 4 - BoardGame).\n"
              << "\t<size>\t Number of elements to generate (instance size).\n"
              << "\t<outputFile>\t File where the benchmark results should be saved.\n"
              << "\t[option]\t Optional parameter: drunkenness level for Drunk Insertion Sort (0 - 100), gaps for Shell Sort (0 - 10), pivot type for Quick Sort.\n"
              << "\t[iterations]\t Number of iterations for the sorting process (default is 100).\n"
              << "HELP MODE:\n"
              << "\tUsage:\n"
              << "\t\t./sorter --help\n"
              << "\tDisplays this help message.\n";
}

// Template function to sort data using the specified algorithm
template <typename T>
void sortData(int algorithm, DynamicArray<T>& data, int optional) {
    Logger::log(Logger::Level::INFO, "Starting sortData function");

    // Mapping algorithm number to SortAlgorithmType
    SortAlgorithmType algorithmType;
    switch (algorithm) {
        case 0:
            algorithmType = SortAlgorithmType::HEAP;
            break;
        case 1:
            algorithmType = SortAlgorithmType::INSERTION;
            break;
        case 2:
            algorithmType = SortAlgorithmType::QUICK;
            break;
        case 3:
            algorithmType = SortAlgorithmType::SHELL;
            break;
        case 4:
            algorithmType = SortAlgorithmType::DRUNK_INSERTION;
            break;
        default:
            Logger::log(Logger::Level::ERROR, ("Unknown algorithm: " + std::to_string(algorithm)).c_str());
            exit(1);
    }

    // Creating a sorter using SortFactory
    auto sorter = SortFactory<T>::createSorter(algorithmType);

    // If the algorithm is DrunkInsertionSort, pass the "drunkenness" level
    if (algorithmType == SortAlgorithmType::DRUNK_INSERTION) {
        dynamic_cast<DrunkInsertionSort<T>*>(sorter.get())->sort(data, optional);
    } else if (algorithmType == SortAlgorithmType::SHELL) {
        dynamic_cast<ShellSort<T>*>(sorter.get())->sort(data, optional);
    } else if (algorithmType == SortAlgorithmType::QUICK) {
        // If the algorithm is QuickSort, pass the pivot type
        PivotType pivotType = static_cast<PivotType>(optional);
        dynamic_cast<QuickSort<T>*>(sorter.get())->sort(data, pivotType);
    } else {
        sorter->sort(data);
    }
}

// Template function to check if the data is sorted
template <typename T>
bool isSorted(const DynamicArray<T>& data) {
    Logger::log(Logger::Level::INFO, "Checking if data is sorted");
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < data[i - 1]) {
            Logger::log(Logger::Level::WARNING, "Data is not sorted");
            return false;
        }
    }
    Logger::log(Logger::Level::INFO, "Data is sorted");
    return true;
}

// Template function to handle file mode operations
template <typename T>
void handleFileMode(int algorithm, const char* inputFile, const char* outputFile, int optional, const int iterations) {
    Logger::log(Logger::Level::INFO, "Entering handleFileMode function");
    auto data = new DynamicArray<T>();

    if (!FileManager::readFromFile(inputFile, *data)) {
        Logger::log(Logger::Level::ERROR, "Failed to read data from file");
        delete data;
        exit(1);
    }

    DynamicArray<int> times;

    for (int i = 0; i < iterations; ++i) {
        auto data_to_sort = new DynamicArray<T>(*data);

        Timer timer;
        timer.start();
        sortData(algorithm, *data_to_sort, optional);
        timer.stop();

        if (!isSorted(*data_to_sort)) {
            Logger::log(Logger::Level::ERROR, "Sorting failed: data is not sorted correctly");
        }

        times.push_back(timer.result());
        if (outputFile && std::strlen(outputFile) > 0 && !FileManager::writeToFile(outputFile, *data_to_sort)) {
            Logger::log(Logger::Level::ERROR, "Failed to write sorted data to file");
            delete data_to_sort;
            exit(1);
        }

        delete data_to_sort;
    }

    char timeFileName[256];
    std::snprintf(timeFileName, sizeof(timeFileName), "%s_time.txt", outputFile);
    std::ofstream file(timeFileName);

    if (file.is_open()) {
        for (const int& time : times) {
            file << time << "\n"; // Write each time to the file
        }
    } else {
        exit(1);
    }

    delete data;
}

// Template function to handle test mode operations
template <typename T>
void handleTestMode(int algorithm, size_t size, const char* outputFile, int optional, const int iterations) {
    Logger::log(Logger::Level::INFO, "Entering handleTestMode function");

    DynamicArray<int> times;

    srand(time(NULL));

    auto data = new DynamicArray<T>();
    for (size_t j = 0; j < size; ++j) {
        if constexpr (std::is_same_v<T, char>) {
            data->push_back('a' + rand() % 26);
        } else {
            data->push_back(static_cast<T>(rand() % INTMAX_MAX));
        }
    }

    for (int i = 0; i < iterations; ++i) {
        auto data_to_sort = new DynamicArray<T>(*data);

        Timer timer;
        timer.start();
        sortData(algorithm, *data_to_sort, optional);
        timer.stop();

        if (!isSorted(*data_to_sort)) {
            Logger::log(Logger::Level::ERROR, "Sorting failed: data is not sorted correctly");
        }

        times.push_back(timer.result());
        if (outputFile && std::strlen(outputFile) > 0 && !FileManager::writeToFile(outputFile, *data_to_sort)) {
            delete data_to_sort;
            exit(1);
        }

        delete data_to_sort;
    }

    delete data;

    char timeFileName[256];
    std::snprintf(timeFileName, sizeof(timeFileName), "%s.time.txt", outputFile);
    std::ofstream file(timeFileName);

    if (file.is_open()) {
        for (const int& time : times) {
            file << time << "\n"; // Write each time to the file
        }
    } else {
        exit(1);
    }

    Logger::log(Logger::Level::INFO, "Test mode completed successfully");
}

// Explicit template instantiation
template void sortData<int>(int algorithm, DynamicArray<int>& data, int optional);
template bool isSorted<int>(const DynamicArray<int>& data);
template void handleFileMode<int>(int algorithm, const char* inputFile, const char* outputFile, int optional, const int iterations);
template void handleTestMode<int>(int algorithm, size_t size, const char* outputFile, int optional, const int iterations);

template void sortData<float>(int algorithm, DynamicArray<float>& data, int optional);
template bool isSorted<float>(const DynamicArray<float>& data);
template void handleFileMode<float>(int algorithm, const char* inputFile, const char* outputFile, int optional, const int iterations);
template void handleTestMode<float>(int algorithm, size_t size, const char* outputFile, int optional, const int iterations);

template void sortData<double>(int algorithm, DynamicArray<double>& data, int optional);
template bool isSorted<double>(const DynamicArray<double>& data);
template void handleFileMode<double>(int algorithm, const char* inputFile, const char* outputFile, int optional, const int iterations);
template void handleTestMode<double>(int algorithm, size_t size, const char* outputFile, int optional, const int iterations);

template void sortData<char>(int algorithm, DynamicArray<char>& data, int optional);
template bool isSorted<char>(const DynamicArray<char>& data);
template void handleFileMode<char>(int algorithm, const char* inputFile, const char* outputFile, int optional, const int iterations);
template void handleTestMode<char>(int algorithm, size_t size, const char* outputFile, int optional, const int iterations);

template void sortData<BoardGame>(int algorithm, DynamicArray<BoardGame>& data, int optional);
template bool isSorted<BoardGame>(const DynamicArray<BoardGame>& data);
template void handleFileMode<BoardGame>(int algorithm, const char* inputFile, const char* outputFile, int optional, const int iterations);
template void handleTestMode<BoardGame>(int algorithm, size_t size, const char* outputFile, int optional, const int iterations);
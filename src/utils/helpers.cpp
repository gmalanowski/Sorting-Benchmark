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
              << "\t[outputFile]\t If provided, the sorted values will be saved to this file.\n"
              << "\t[option]\t Optional parameter: drunkenness level for Drunk Insertion Sort (0 - 100), gaps for Shell Sort (0 - 10), pivot type for Quick Sort.\n"
              << "BENCHMARK MODE:\n"
              << "\tUsage:\n"
              << "\t\t./sorter --test <algorithm> <type> <size> <outputFile> [option]\n"
              << "\t<algorithm>\t Sorting algorithm to use (e.g., 0 - Heap, 1 - Insertion, 2 - Quick, 3 - Shell, 4 - Drunk Insertion).\n"
              << "\t<type>\t Data type to generate (e.g., 0 - int, 1 - float, 2 - double, 3 - char, 4 - BoardGame).\n"
              << "\t<size>\t Number of elements to generate (instance size).\n"
              << "\t<outputFile>\t File where the benchmark results should be saved.\n"
              << "\t[option]\t Optional parameter: drunkenness level for Drunk Insertion Sort (0 - 100), gaps for Shell Sort (0 - 10), pivot type for Quick Sort.\n"
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
        // If the algorithm is ShellSort, pass the gaps
        DynamicArray<std::size_t> gaps;
        for (int i = 0; i < optional; ++i) {
            gaps.push_back(i + 1);
        }
        dynamic_cast<ShellSort<T>*>(sorter.get())->sort(data, gaps);
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
void handleFileMode(int algorithm, const char* inputFile, const char* outputFile, int optional) {
    Logger::log(Logger::Level::INFO, "Entering handleFileMode function");
    auto data = new DynamicArray<T>();
    if (!FileManager::readFromFile(inputFile, *data)) {
        delete data;
        exit(1);
    }

    Timer timer;
    timer.start();
    sortData(algorithm, *data, optional);
    timer.stop();

    Logger::log(Logger::Level::INFO, ("Elapsed time: " + std::to_string(timer.result()) + " ms").c_str());
    std::cout << "Elapsed time: " << timer.result() << " ms" << std::endl;

    if (!isSorted(*data)) {
        Logger::log(Logger::Level::ERROR, "Sorting failed: data is not sorted correctly");
        delete data;
        exit(1);
    }

    if (outputFile && std::strlen(outputFile) > 0 && !FileManager::writeToFile(outputFile, *data)) {
        delete data;
        exit(1);
    }

    delete data;
}

// Template function to handle test mode operations
template <typename T>
void handleTestMode(int algorithm, size_t size, const char* outputFile, int optional) {
    Logger::log(Logger::Level::INFO, "Entering handleTestMode function");

    const int iterations = 100;
    DynamicArray<int> times;

    for (int i = 0; i < iterations; ++i) {
        auto data = new DynamicArray<T>();
        for (size_t j = 0; j < size; ++j) {
            if constexpr (std::is_same_v<T, char>) {
                data->push_back('a' + rand() % 26);
            } else {
                data->push_back(static_cast<T>(rand() % 10000));
            }
        }

        Timer timer;
        timer.start();
        sortData(algorithm, *data, optional);
        timer.stop();

        if (!isSorted(*data)) {
            Logger::log(Logger::Level::ERROR, "Sorting failed: data is not sorted correctly");
            delete data;
            exit(1);
        }

        times.push_back(timer.result());
        if (outputFile && std::strlen(outputFile) > 0 && !FileManager::writeToFile(outputFile, *data)) {
            delete data;
            exit(1);
        }

        delete data;
    }

    int minTime = *std::min_element(times.begin(), times.end());
    int maxTime = *std::max_element(times.begin(), times.end());
    double avgTime = std::accumulate(times.begin(), times.end(), 0.0) / times.size();

    char timeFileName[256];
    std::snprintf(timeFileName, sizeof(timeFileName), "time_%s", outputFile);
    std::ofstream file(timeFileName);

    if (file.is_open()) {
        file << "Average time: " << avgTime << " ms\n";
        file << "Minimum time: " << minTime << " ms\n";
        file << "Maximum time: " << maxTime << " ms\n";
        file.close();
    } else {
        exit(1);
    }

    Logger::log(Logger::Level::INFO, "Test mode completed successfully");
}

// Explicit template instantiation
template void sortData<int>(int algorithm, DynamicArray<int>& data, int optional);
template bool isSorted<int>(const DynamicArray<int>& data);
template void handleFileMode<int>(int algorithm, const char* inputFile, const char* outputFile, int optional);
template void handleTestMode<int>(int algorithm, size_t size, const char* outputFile, int optional);

template void sortData<float>(int algorithm, DynamicArray<float>& data, int optional);
template bool isSorted<float>(const DynamicArray<float>& data);
template void handleFileMode<float>(int algorithm, const char* inputFile, const char* outputFile, int optional);
template void handleTestMode<float>(int algorithm, size_t size, const char* outputFile, int optional);

template void sortData<double>(int algorithm, DynamicArray<double>& data, int optional);
template bool isSorted<double>(const DynamicArray<double>& data);
template void handleFileMode<double>(int algorithm, const char* inputFile, const char* outputFile, int optional);
template void handleTestMode<double>(int algorithm, size_t size, const char* outputFile, int optional);

template void sortData<char>(int algorithm, DynamicArray<char>& data, int optional);
template bool isSorted<char>(const DynamicArray<char>& data);
template void handleFileMode<char>(int algorithm, const char* inputFile, const char* outputFile, int optional);
template void handleTestMode<char>(int algorithm, size_t size, const char* outputFile, int optional);

template void sortData<BoardGame>(int algorithm, DynamicArray<BoardGame>& data, int optional);
template bool isSorted<BoardGame>(const DynamicArray<BoardGame>& data);
template void handleFileMode<BoardGame>(int algorithm, const char* inputFile, const char* outputFile, int optional);
template void handleTestMode<BoardGame>(int algorithm, size_t size, const char* outputFile, int optional);
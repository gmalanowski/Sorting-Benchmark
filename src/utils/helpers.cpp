#include "utils/helpers.hpp"
#include "utils/timer.hpp"
#include "utils/file_manager.hpp"
#include "utils/logger.hpp"
#include "sort/heap_sort.hpp"
#include "sort/insertion_sort.hpp"
#include "sort/quick_sort.hpp"
#include "sort/shell_sort.hpp"
#include "sort/drunk_insertion_sort.hpp"
#include "data/board_game.hpp"
#include <iostream>

void printHelp() {
    Logger::log(Logger::Level::INFO, "Displaying help message");
    std::cout << "FILE TEST MODE:\n"
              << "\tUsage:\n"
              << "\t\t./sorter --file <algorithm> <type> <inputFile> [outputFile]\n"
              << "\t<algorithm>\t Sorting algorithm to use (e.g., 0 - Heap, 1 - Insertion, ...).\n"
              << "\t<type>\t Data type to load (e.g., 0 - int, 1 - float, 2 - double, 3 - char, 4 - BoardGame).\n"
              << "\t<inputFile>\t Input file containing the data to be sorted.\n"
              << "\t[outputFile]\t If provided, the sorted values will be saved to this file.\n"
              << "BENCHMARK MODE:\n"
              << "\tUsage:\n"
              << "\t\t./sorter --test <algorithm> <type> <size> <outputFile>\n"
              << "\t<algorithm>\t Sorting algorithm to use (e.g., 0 - Heap, 1 - Insertion, ...).\n"
              << "\t<type>\t Data type to generate (e.g., 0 - int, 1 - float, 2 - double, 3 - char, 4 - BoardGame).\n"
              << "\t<size>\t Number of elements to generate (instance size).\n"
              << "\t<outputFile>\t File where the benchmark results should be saved.\n"
              << "HELP MODE:\n"
              << "\tUsage:\n"
              << "\t\t./YourProject --help\n"
              << "\tDisplays this help message.\n";
}

template <typename T>
void sortData(int algorithm, DynamicArray<T>& data, int drunkenness) {
    Logger::log(Logger::Level::INFO, "Starting sortData function");

    HeapSort<T> heapSort;
    InsertionSort<T> insertionSort;
    QuickSort<T> quickSort;
    ShellSort<T> shellSort;
    DrunkInsertionSort<T> drunkInsertionSort;

    switch (algorithm) {
        case 0:
            Logger::log(Logger::Level::INFO, "Using HeapSort");
            heapSort.sort(data);
            break;
        case 1:
            Logger::log(Logger::Level::INFO, "Using InsertionSort");
            insertionSort.sort(data);
            break;
        case 2:
            Logger::log(Logger::Level::INFO, "Using QuickSort");
            quickSort.sort(data);
            break;
        case 3:
            Logger::log(Logger::Level::INFO, "Using ShellSort");
            shellSort.sort(data);
            break;
        case 4:
            Logger::log(Logger::Level::INFO, "Using DrunkInsertionSort");
            drunkInsertionSort.sort(data, drunkenness);
            break;
        default:
            Logger::log(Logger::Level::ERROR, "Unknown algorithm: " + std::to_string(algorithm));
            std::cerr << "Unknown algorithm: " << algorithm << std::endl;
            exit(1);
    }
}

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

template <typename T>
void handleFileMode(int algorithm, const std::string& inputFile, const std::string& outputFile, int drunkenness) {
    Logger::log(Logger::Level::INFO, "Entering handleFileMode function");
    auto data = new DynamicArray<T>();
    if (!FileManager::readFromFile(inputFile, *data)) {
        Logger::log(Logger::Level::ERROR, "Failed to read from file: " + inputFile);
        std::cerr << "Failed to read from file: " << inputFile << std::endl;
        delete data;
        exit(1);
    }

    Timer timer;
    timer.start();
    sortData(algorithm, *data, drunkenness);
    timer.stop();

    Logger::log(Logger::Level::INFO, "Elapsed time: " + std::to_string(timer.result()) + " ms");
    std::cout << "Elapsed time: " << timer.result() << " ms" << std::endl;

    if (!isSorted(*data)) {
        Logger::log(Logger::Level::ERROR, "Sorting failed: data is not sorted correctly");
        std::cerr << "Sorting failed: data is not sorted correctly." << std::endl;
        delete data;
        exit(1);
    }

    if (!outputFile.empty() && !FileManager::writeToFile(outputFile, *data)) {
        Logger::log(Logger::Level::ERROR, "Failed to write to file: " + outputFile);
        std::cerr << "Failed to write to file: " << outputFile << std::endl;
        delete data;
        exit(1);
    }

    delete data;
}

template <typename T>
void handleTestMode(int algorithm, size_t size, const std::string& outputFile, int drunkenness) {
    Logger::log(Logger::Level::INFO, "Entering handleTestMode function");
    auto data = new DynamicArray<T>();
    for (size_t i = 0; i < size; ++i) {
        if constexpr (std::is_same_v<T, char>) {
            data->push_back('a' + rand() % 26);
        } else {
            data->push_back(static_cast<T>(rand() % 10000));
        }
    }

    Timer timer;
    timer.start();
    sortData(algorithm, *data, drunkenness);
    timer.stop();

    Logger::log(Logger::Level::INFO, "Elapsed time: " + std::to_string(timer.result()) + " ms");
    std::cout << "Elapsed time: " << timer.result() << " ms" << std::endl;

    if (!isSorted(*data)) {
        Logger::log(Logger::Level::ERROR, "Sorting failed: data is not sorted correctly");
        std::cerr << "Sorting failed: data is not sorted correctly." << std::endl;
        delete data;
        exit(1);
    }

    if (!FileManager::writeToFile(outputFile, *data)) {
        Logger::log(Logger::Level::ERROR, "Failed to write to file: " + outputFile);
        std::cerr << "Failed to write to file: " << outputFile << std::endl;
        delete data;
        exit(1);
    }

    delete data;
}

// Explicit template instantiation
template void sortData<int>(int algorithm, DynamicArray<int>& data, int drunkenness);
template bool isSorted<int>(const DynamicArray<int>& data);
template void handleFileMode<int>(int algorithm, const std::string& inputFile, const std::string& outputFile, int drunkenness);
template void handleTestMode<int>(int algorithm, size_t size, const std::string& outputFile, int drunkenness);

template void sortData<float>(int algorithm, DynamicArray<float>& data, int drunkenness);
template bool isSorted<float>(const DynamicArray<float>& data);
template void handleFileMode<float>(int algorithm, const std::string& inputFile, const std::string& outputFile, int drunkenness);
template void handleTestMode<float>(int algorithm, size_t size, const std::string& outputFile, int drunkenness);

template void sortData<double>(int algorithm, DynamicArray<double>& data, int drunkenness);
template bool isSorted<double>(const DynamicArray<double>& data);
template void handleFileMode<double>(int algorithm, const std::string& inputFile, const std::string& outputFile, int drunkenness);
template void handleTestMode<double>(int algorithm, size_t size, const std::string& outputFile, int drunkenness);

template void sortData<char>(int algorithm, DynamicArray<char>& data, int drunkenness);
template bool isSorted<char>(const DynamicArray<char>& data);
template void handleFileMode<char>(int algorithm, const std::string& inputFile, const std::string& outputFile, int drunkenness);
template void handleTestMode<char>(int algorithm, size_t size, const std::string& outputFile, int drunkenness);

template void sortData<BoardGame>(int algorithm, DynamicArray<BoardGame>& data, int drunkenness);
template bool isSorted<BoardGame>(const DynamicArray<BoardGame>& data);
template void handleFileMode<BoardGame>(int algorithm, const std::string& inputFile, const std::string& outputFile, int drunkenness);
template void handleTestMode<BoardGame>(int algorithm, size_t size, const std::string& outputFile, int drunkenness);
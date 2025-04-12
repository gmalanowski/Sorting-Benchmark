#include "utils/file_manager.h"
#include "data/board_game.h"
#include <fstream>

// Template method to read data from a file into a DynamicArray
template<typename T>
bool FileManager::readFromFile(const char* filename, DynamicArray<T>& data) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false; // Return false if the file cannot be opened
    }

    size_t dataSize;
    file >> dataSize; // Read the size of the data

    T value;
    for (size_t i = 0; i < dataSize; ++i) {
        file >> value; // Read each value from the file
        data.push_back(value); // Add the value to the DynamicArray
    }

    file.close(); // Close the file
    return true; // Return true if the operation is successful
}

// Template method to write data from a DynamicArray to a file
template<typename T>
bool FileManager::writeToFile(const char* filename, const DynamicArray<T>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false; // Return false if the file cannot be opened
    }

    file << data.size() << "\n"; // Write the size of the data
    for (size_t i = 0; i < data.size(); ++i) {
        file << data[i] << "\n"; // Write each value to the file
    }

    file.close(); // Close the file
    return true; // Return true if the operation is successful
}

// Explicit template instantiations for specific types
template bool FileManager::readFromFile<int>(const char* filename, DynamicArray<int>& data);
template bool FileManager::writeToFile<int>(const char* filename, const DynamicArray<int>& data);
template bool FileManager::readFromFile<float>(const char* filename, DynamicArray<float>& data);
template bool FileManager::writeToFile<float>(const char* filename, const DynamicArray<float>& data);
template bool FileManager::readFromFile<double>(const char* filename, DynamicArray<double>& data);
template bool FileManager::writeToFile<double>(const char* filename, const DynamicArray<double>& data);
template bool FileManager::readFromFile<char>(const char* filename, DynamicArray<char>& data);
template bool FileManager::writeToFile<char>(const char* filename, const DynamicArray<char>& data);
template bool FileManager::readFromFile<BoardGame>(const char* filename, DynamicArray<BoardGame>& data);
template bool FileManager::writeToFile<BoardGame>(const char* filename, const DynamicArray<BoardGame>& data);
#include "utils/file_manager.hpp"
#include "data/board_game.hpp"
#include <fstream>

// Template method to read data from a file into a DynamicArray
template<typename T>
bool FileManager::readFromFile(const std::string& filename, DynamicArray<T>& data) {
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
bool FileManager::writeToFile(const std::string& filename, const DynamicArray<T>& data) {
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
template bool FileManager::readFromFile<int>(const std::string& filename, DynamicArray<int>& data);
template bool FileManager::writeToFile<int>(const std::string& filename, const DynamicArray<int>& data);
template bool FileManager::readFromFile<float>(const std::string& filename, DynamicArray<float>& data);
template bool FileManager::writeToFile<float>(const std::string& filename, const DynamicArray<float>& data);
template bool FileManager::readFromFile<double>(const std::string& filename, DynamicArray<double>& data);
template bool FileManager::writeToFile<double>(const std::string& filename, const DynamicArray<double>& data);
template bool FileManager::readFromFile<char>(const std::string& filename, DynamicArray<char>& data);
template bool FileManager::writeToFile<char>(const std::string& filename, const DynamicArray<char>& data);
template bool FileManager::readFromFile<BoardGame>(const std::string& filename, DynamicArray<BoardGame>& data);
template bool FileManager::writeToFile<BoardGame>(const std::string& filename, const DynamicArray<BoardGame>& data);
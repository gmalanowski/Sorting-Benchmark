#include "utils/file_manager.hpp"
#include "data/board_game.hpp"
#include <fstream>

template<typename T>
bool FileManager::readFromFile(const std::string& filename, DynamicArray<T>& data) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    size_t dataSize;
    file >> dataSize;

    T value;
    for (size_t i = 0; i < dataSize; ++i) {
        file >> value;
        data.push_back(value);
    }

    file.close();
    return true;
}

template<typename T>
bool FileManager::writeToFile(const std::string& filename, const DynamicArray<T>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    file << data.size() << "\n";
    for (size_t i = 0; i < data.size(); ++i) {
        file << data[i] << "\n";
    }

    file.close();
    return true;
}

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
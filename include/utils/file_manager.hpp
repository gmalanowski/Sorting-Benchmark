#ifndef PROJEKT_FILE_MANAGER_HPP
#define PROJEKT_FILE_MANAGER_HPP

#include <string>
#include "data/dynamic_array.hpp"

// Class for managing file operations
class FileManager {
public:
    // Template method to read data from a file into a DynamicArray
    template<typename T>
    static bool readFromFile(const std::string& filename, DynamicArray<T>& data);

    // Template method to write data from a DynamicArray to a file
    template<typename T>
    static bool writeToFile(const std::string& filename, const DynamicArray<T>& data);
};

#endif // PROJEKT_FILE_MANAGER_HPP
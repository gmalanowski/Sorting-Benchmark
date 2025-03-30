#ifndef PROJEKT_FILE_MANAGER_HPP
#define PROJEKT_FILE_MANAGER_HPP

#include <string>
#include "../data/dynamic_array.hpp"

class FileManager {
public:
    template<typename T>
    static bool readFromFile(const std::string& filename, DynamicArray<T>& data);

    template<typename T>
    static bool writeToFile(const std::string& filename, const DynamicArray<T>& data);
};

#endif // PROJEKT_FILE_MANAGER_HPP
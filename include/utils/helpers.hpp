#ifndef PROJEKT_HELPERS_HPP
#define PROJEKT_HELPERS_HPP

#include <string>
#include "data/dynamic_array.hpp"

// Function to print help information
void printHelp();

// Template function to sort data using a specified algorithm
template <typename T>
void sortData(int algorithm, DynamicArray<T>& data, int drunkenness = 0);

// Template function to check if the data is sorted
template <typename T>
bool isSorted(const DynamicArray<T>& data);

// Template function to handle file mode operations
template <typename T>
void handleFileMode(int algorithm, const std::string& inputFile, const std::string& outputFile, int drunkenness = 0);

// Template function to handle test mode operations
template <typename T>
void handleTestMode(int algorithm, size_t size, const std::string& outputFile, int drunkenness = 0);

#endif // PROJEKT_HELPERS_HPP
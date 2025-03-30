#ifndef PROJEKT_HELPERS_HPP
#define PROJEKT_HELPERS_HPP

#include <string>
#include "../data/dynamic_array.hpp"

void printHelp();
template <typename T>
void sortData(int algorithm, DynamicArray<T>& data, int drunkenness = 0);
template <typename T>
bool isSorted(const DynamicArray<T>& data);
template <typename T>
void handleFileMode(int algorithm, const std::string& inputFile, const std::string& outputFile, int drunkenness = 0);
template <typename T>
void handleTestMode(int algorithm, size_t size, const std::string& outputFile, int drunkenness = 0);

#endif // PROJEKT_HELPERS_HPP
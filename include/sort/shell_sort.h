#ifndef PROJEKT_SHELL_SORT_HPP
#define PROJEKT_SHELL_SORT_HPP

#include "data/dynamic_array.h"
#include "sort_algorithm.h"

// Template class for ShellSort inheriting from SortAlgorithm
template<typename T>
class ShellSort : public SortAlgorithm<T> {
public:
    // Method to sort data
    void sort(DynamicArray<T>& data) override;
    void sort(DynamicArray<T>& data, const int customGaps);
};

#endif // PROJEKT_SHELL_SORT_HPP
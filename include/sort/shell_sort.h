#ifndef PROJEKT_SHELL_SORT_HPP
#define PROJEKT_SHELL_SORT_HPP

#include "data/dynamic_array.h"
#include "sort_algorithm.h"

// Template class for ShellSort inheriting from SortAlgorithm
template<typename T>
class ShellSort : public SortAlgorithm<T> {
public:
    // Constructor to initialize with custom gaps
    explicit ShellSort(const DynamicArray<std::size_t>& gaps);

    // Default constructor with a fallback gap sequence
    ShellSort();

    // Method to sort data
    void sort(DynamicArray<T>& data) override;
    void sort(DynamicArray<T>& data, const DynamicArray<std::size_t>& customGaps);

private:
    DynamicArray<std::size_t> gaps; // Gap sequence for the ShellSort algorithm
};

#endif // PROJEKT_SHELL_SORT_HPP
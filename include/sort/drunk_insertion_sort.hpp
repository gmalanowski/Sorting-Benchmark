#ifndef PROJEKT_DRUNK_INSERTION_SORT_HPP
#define PROJEKT_DRUNK_INSERTION_SORT_HPP

#include "data/dynamic_array.hpp"
#include "sort_algorithm.hpp"

// Template class for DrunkInsertionSort inheriting from SortAlgorithm
template<typename T>
class DrunkInsertionSort : public SortAlgorithm<T> {
public:
    // Method to sort data
    void sort(DynamicArray<T>& data) override;

    // Method to sort data considering the level of "drunkenness"
    void sort(DynamicArray<T>& data, int drunkenness);
};

#endif // PROJEKT_DRUNK_INSERTION_SORT_HPP
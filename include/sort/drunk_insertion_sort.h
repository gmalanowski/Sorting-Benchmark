#ifndef PROJEKT_DRUNK_INSERTION_SORT_HPP
#define PROJEKT_DRUNK_INSERTION_SORT_HPP

#include "data/dynamic_array.h"
#include "sort_algorithm.h"

// Template class for DrunkInsertionSort inheriting from SortAlgorithm
template<typename T>
class DrunkInsertionSort : public SortAlgorithm<T> {
public:
    // Method to sort data
    using SortAlgorithm<T>::sort; // Inherit the sort method from SortAlgorithm
    void sort(DynamicArray<T>& data) override;

    // Method to sort data considering the level of "drunkenness"
    void sort(DynamicArray<T>& data, int drunkenness);
};

#endif // PROJEKT_DRUNK_INSERTION_SORT_HPP
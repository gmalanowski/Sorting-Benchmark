#ifndef PROJEKT_INSERTION_SORT_HPP
#define PROJEKT_INSERTION_SORT_HPP

#include "data/dynamic_array.hpp"
#include "sort_algorithm.hpp"

// Template class for InsertionSort inheriting from SortAlgorithm
template<typename T>
class InsertionSort : public SortAlgorithm<T> {
public:
    // Method to sort data
    void sort(DynamicArray<T>& data);
};

#endif // PROJEKT_INSERTION_SORT_HPP
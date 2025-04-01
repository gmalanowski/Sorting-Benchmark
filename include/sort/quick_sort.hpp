#ifndef PROJEKT_QUICK_SORT_HPP
#define PROJEKT_QUICK_SORT_HPP

#include "data/dynamic_array.hpp"
#include "sort_algorithm.hpp"

// Template class for QuickSort inheriting from SortAlgorithm
template<typename T>
class QuickSort : public SortAlgorithm<T> {
public:
    // Method to sort data
    void sort(DynamicArray<T>& data);
};

#endif // PROJEKT_QUICK_SORT_HPP
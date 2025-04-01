#ifndef PROJEKT_HEAP_SORT_HPP
#define PROJEKT_HEAP_SORT_HPP

#include "data/dynamic_array.hpp"
#include "sort_algorithm.hpp"

// Template class for HeapSort inheriting from SortAlgorithm
template<typename T>
class HeapSort : public SortAlgorithm<T> {
public:
    // Method to sort data
    void sort(DynamicArray<T>& data) override;
};

#endif // PROJEKT_HEAP_SORT_HPP
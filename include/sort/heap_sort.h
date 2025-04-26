#ifndef PROJEKT_HEAP_SORT_HPP
#define PROJEKT_HEAP_SORT_HPP

#include "data/dynamic_array.h"
#include "sort_algorithm.h"

// Template class for HeapSort inheriting from SortAlgorithm
template<typename T>
class HeapSort : public SortAlgorithm<T> {
public:
    // Method to sort data
    void sort(DynamicArray<T>& data) override;

private:
    // Helper method to maintain the heap property
    void heapify(DynamicArray<T>& data, int n, int i);
    // Helper method to swap two elements
    void swap(T& a, T& b);
};

#endif // PROJEKT_HEAP_SORT_HPP
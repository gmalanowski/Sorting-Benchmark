#ifndef PROJEKT_QUICK_SORT_HPP
#define PROJEKT_QUICK_SORT_HPP

#include "data/dynamic_array.h"
#include "sort_algorithm.h"

enum class PivotType {
    LEFT,
    RIGHT,
    MIDDLE,
    RANDOM
};

// Template class for QuickSort inheriting from SortAlgorithm
template<typename T>
class QuickSort : public SortAlgorithm<T> {
public:
    // Method to sort data
    using SortAlgorithm<T>::sort; // Inherit the sort method from SortAlgorithm
    void sort(DynamicArray<T>& data) override;
    void sort(DynamicArray<T>& data, PivotType pivotType);

private:
    // Helper method to partition the array
    int partition(DynamicArray<T>& data, int low, int high, PivotType pivotType);

    // Recursive QuickSort method
    void quickSort(DynamicArray<T>& data, int low, int high, PivotType pivotType);

    // Helper method to swap two elements
    void swap(T& a, T& b);
};

#endif // PROJEKT_QUICK_SORT_HPP
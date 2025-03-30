#ifndef PROJEKT_QUICK_SORT_HPP
#define PROJEKT_QUICK_SORT_HPP

#include "../data/dynamic_array.hpp"
#include "sort_algorithm.hpp"

template<typename T>
class QuickSort : public SortAlgorithm<T> {
public:
    void sort(DynamicArray<T>& data);
};

#endif // PROJEKT_QUICK_SORT_HPP
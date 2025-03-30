#ifndef PROJEKT_HEAP_SORT_HPP
#define PROJEKT_HEAP_SORT_HPP

#include "../data/dynamic_array.hpp"
#include "sort_algorithm.hpp"

template<typename T>
class HeapSort : public SortAlgorithm<T> {
public:
    void sort(DynamicArray<T>& data) override;
};

#endif // PROJEKT_HEAP_SORT_HPP
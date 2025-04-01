#ifndef PROJEKT_DRUNK_INSERTION_SORT_HPP
#define PROJEKT_DRUNK_INSERTION_SORT_HPP

#include "data/dynamic_array.hpp"
#include "sort_algorithm.hpp"

template<typename T>
class DrunkInsertionSort : public SortAlgorithm<T> {
public:
    void sort(DynamicArray<T>& data) override;
    void sort(DynamicArray<T>& data, int drunkenness);
};

#endif // PROJEKT_DRUNK_INSERTION_SORT_HPP
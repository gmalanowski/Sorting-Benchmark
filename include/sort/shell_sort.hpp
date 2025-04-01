#ifndef PROJEKT_SHELL_SORT_HPP
#define PROJEKT_SHELL_SORT_HPP

#include "data/dynamic_array.hpp"
#include "sort_algorithm.hpp"

template<typename T>
class ShellSort : public SortAlgorithm<T> {
public:
    void sort(DynamicArray<T>& data);
};

#endif // PROJEKT_SHELL_SORT_HPP
#ifndef PROJEKT_SORT_FACTORY_HPP
#define PROJEKT_SORT_FACTORY_HPP

#include "heap_sort.hpp"
#include "insertion_sort.hpp"
#include "quick_sort.hpp"
#include "shell_sort.hpp"
#include "drunk_insertion_sort.hpp"
#include <memory>
#include <stdexcept>

// Enum class for different types of sorting algorithms
enum class SortAlgorithmType {
    HEAP,
    INSERTION,
    QUICK,
    SHELL,
    DRUNK_INSERTION
};

// Template class for SortFactory
template<typename T>
class SortFactory {
public:
    // Static method to create a sorter based on the algorithm type
    static std::unique_ptr<SortAlgorithm<T>> createSorter(SortAlgorithmType algorithm);
};

#endif // PROJEKT_SORT_FACTORY_HPP
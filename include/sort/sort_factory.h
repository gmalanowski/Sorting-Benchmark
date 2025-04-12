#ifndef PROJEKT_SORT_FACTORY_HPP
#define PROJEKT_SORT_FACTORY_HPP

#include "heap_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include "drunk_insertion_sort.h"
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
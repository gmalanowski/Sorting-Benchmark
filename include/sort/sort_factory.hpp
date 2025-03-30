#ifndef PROJEKT_SORT_FACTORY_HPP
#define PROJEKT_SORT_FACTORY_HPP

#include "heap_sort.hpp"
#include "insertion_sort.hpp"
#include "quick_sort.hpp"
#include "shell_sort.hpp"
#include "drunk_insertion_sort.hpp"
#include <memory>
#include <stdexcept>

enum class SortAlgorithmType {
    HEAP,
    INSERTION,
    QUICK,
    SHELL,
    DRUNK_INSERTION
};

template<typename T>
class SortFactory {
public:
    static std::unique_ptr<SortAlgorithm<T>> createSorter(SortAlgorithmType algorithm);
};

#endif // PROJEKT_SORT_FACTORY_HPP
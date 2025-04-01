#include "sort/sort_factory.hpp"

// Factory method to create a sorter based on the specified algorithm type
template<typename T>
std::unique_ptr<SortAlgorithm<T>> SortFactory<T>::createSorter(SortAlgorithmType algorithm) {
    switch (algorithm) {
        case SortAlgorithmType::HEAP:
            return std::make_unique<HeapSort<T>>(); // Create a HeapSort instance
        case SortAlgorithmType::INSERTION:
            return std::make_unique<InsertionSort<T>>(); // Create an InsertionSort instance
        case SortAlgorithmType::QUICK:
            return std::make_unique<QuickSort<T>>(); // Create a QuickSort instance
        case SortAlgorithmType::SHELL:
            return std::make_unique<ShellSort<T>>(); // Create a ShellSort instance
        case SortAlgorithmType::DRUNK_INSERTION:
            return std::make_unique<DrunkInsertionSort<T>>(); // Create a DrunkInsertionSort instance
        default:
            throw std::invalid_argument("Unknown sorting algorithm"); // Throw an exception for unknown algorithms
    }
}

// Explicit template instantiation for specific types
template class SortFactory<int>;
template class SortFactory<float>;
template class SortFactory<double>;
template class SortFactory<char>;
template class SortFactory<BoardGame>;
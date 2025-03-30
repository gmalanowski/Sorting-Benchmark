#include "../../include/sort/sort_factory.hpp"

template<typename T>
std::unique_ptr<SortAlgorithm<T>> SortFactory<T>::createSorter(SortAlgorithmType algorithm) {
    switch (algorithm) {
        case SortAlgorithmType::HEAP:
            return std::make_unique<HeapSort<T>>();
        case SortAlgorithmType::INSERTION:
            return std::make_unique<InsertionSort<T>>();
        case SortAlgorithmType::QUICK:
            return std::make_unique<QuickSort<T>>();
        case SortAlgorithmType::SHELL:
            return std::make_unique<ShellSort<T>>();
        case SortAlgorithmType::DRUNK_INSERTION:
            return std::make_unique<DrunkInsertionSort<T>>();
        default:
            throw std::invalid_argument("Unknown sorting algorithm");
    }
}

// Explicit template instantiation
template class SortFactory<int>;
template class SortFactory<float>;
template class SortFactory<double>;
template class SortFactory<char>;
template class SortFactory<BoardGame>;
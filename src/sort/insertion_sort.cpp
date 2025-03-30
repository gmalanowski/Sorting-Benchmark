#include "../../include/sort/insertion_sort.hpp"

template<typename T>
void InsertionSort<T>::sort(DynamicArray<T>& data) {
    // TODO: Implementacja sortowania przez wstawianie
    return;
}

// Explicit template instantiation
template class InsertionSort<int>;
template class InsertionSort<float>;
template class InsertionSort<double>;
template class InsertionSort<char>;
template class InsertionSort<BoardGame>;
#include "sort/drunk_insertion_sort.hpp"

template<typename T>
void DrunkInsertionSort<T>::sort(DynamicArray<T>& data) {
    sort(data, 0);
}

template<typename T>
void DrunkInsertionSort<T>::sort(DynamicArray<T>& data, int drunkenness) {
    // TODO: Implementacja sortowania przez wstawianie z uwzględnieniem poziomu "pijaności"
    return;
}

// Explicit template instantiation
template class DrunkInsertionSort<int>;
template class DrunkInsertionSort<float>;
template class DrunkInsertionSort<double>;
template class DrunkInsertionSort<char>;
template class DrunkInsertionSort<BoardGame>;
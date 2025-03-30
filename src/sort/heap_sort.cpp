#include "../../include/sort/heap_sort.hpp"

template<typename T>
void HeapSort<T>::sort(DynamicArray<T>& data) {
    // TODO: Implementacja sortowania przez kopcowanie
    return;
}

// Explicit template instantiation
template class HeapSort<int>;
template class HeapSort<float>;
template class HeapSort<double>;
template class HeapSort<char>;
template class HeapSort<BoardGame>;
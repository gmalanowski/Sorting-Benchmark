#include "sort/insertion_sort.h"

template<typename T>
void InsertionSort<T>::sort(DynamicArray<T>& data) {
    for (std::size_t i = 1; i < data.size(); ++i) {
        T key = data[i];
        int j = i - 1;

        // Shift elements greater than the key one position to the right
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        // Insert the key into the correct position
        data[j + 1] = key;
    }
}

// Explicit template instantiation
template class InsertionSort<int>;
template class InsertionSort<float>;
template class InsertionSort<double>;
template class InsertionSort<char>;
template class InsertionSort<BoardGame>;
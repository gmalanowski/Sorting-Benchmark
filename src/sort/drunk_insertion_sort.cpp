#include "sort/drunk_insertion_sort.h"
#include <cstdlib>

template<typename T>
void DrunkInsertionSort<T>::sort(DynamicArray<T>& data) {
    sort(data, 0); // Default drunkenness level
}

template<typename T>
void DrunkInsertionSort<T>::sort(DynamicArray<T>& data, int drunkenness) {
    for (std::size_t i = 1; i < data.size(); ++i) {
        T key = data[i];
        int j = i - 1;

        // Standard insertion sort logic
        while (j >= 0 && data[j] > key) {
            // Introduce randomness based on drunkenness level
            if (drunkenness > 0 && rand() % 100 < drunkenness) {
                // Randomly swap elements
                int randomIndex = rand() % data.size();
                std::swap(data[j], data[randomIndex]);
            } else {
                data[j + 1] = data[j];
            }
            --j;
        }
        data[j + 1] = key;
    }
}

// Explicit template instantiation
template class DrunkInsertionSort<int>;
template class DrunkInsertionSort<float>;
template class DrunkInsertionSort<double>;
template class DrunkInsertionSort<char>;
template class DrunkInsertionSort<BoardGame>;
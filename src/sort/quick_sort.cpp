#include "sort/quick_sort.h"

// Helper method to swap two elements
template<typename T>
void QuickSort<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Helper method to partition the array
template<typename T>
int QuickSort<T>::partition(DynamicArray<T>& data, int low, int high, PivotType pivotType) {
    int pivotIndex = low;
    switch (pivotType) {
        case PivotType::LEFT: pivotIndex = low; break;
        case PivotType::RIGHT: pivotIndex = high; break;
        case PivotType::MIDDLE: pivotIndex = (low + high) / 2; break;
        case PivotType::RANDOM: pivotIndex = low + rand() % (high - low + 1); break;
        default: pivotIndex = (low + high) / 2; break;
    }
    swap(data[pivotIndex], data[high]);
    T pivot = data[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (data[j] <= pivot) {
            ++i;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return i + 1;
}

// Recursive QuickSort method
template<typename T>
void QuickSort<T>::quickSort(DynamicArray<T>& data, int low, int high, PivotType pivotType) {
    if (low < high) {
        int pi = partition(data, low, high, pivotType); // Partition the array

        // Recursively sort elements before and after partition
        quickSort(data, low, pi - 1, pivotType);
        quickSort(data, pi + 1, high, pivotType);
    }
}

// Base sort method
template<typename T>
void QuickSort<T>::sort(DynamicArray<T>& data) {
    if (data.size() > 1) {
        quickSort(data, 0, data.size() - 1, PivotType::MIDDLE); // Default pivot type
    }
}

// Implementation of the sort method
template<typename T>
void QuickSort<T>::sort(DynamicArray<T>& data, PivotType pivotType) {
    if (data.size() > 1) {
        quickSort(data, 0, data.size() - 1, pivotType);
    }
}

// Explicit template instantiation
template class QuickSort<int>;
template class QuickSort<float>;
template class QuickSort<double>;
template class QuickSort<char>;
template class QuickSort<BoardGame>;
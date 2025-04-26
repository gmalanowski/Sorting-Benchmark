#include "sort/heap_sort.h"

// Helper method to swap two elements
template<typename T>
void HeapSort<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Helper method to maintain the heap property
template<typename T>
void HeapSort<T>::heapify(DynamicArray<T>& data, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && data[left] > data[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && data[right] > data[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(data[i], data[largest]); // Swap root with largest
        heapify(data, n, largest); // Recursively heapify the affected subtree
    }
}

// Method to sort data using HeapSort
template<typename T>
void HeapSort<T>::sort(DynamicArray<T>& data) {
    int n = data.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(data, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; --i) {
        swap(data[0], data[i]); // Move current root to end
        heapify(data, i, 0); // Call heapify on the reduced heap
    }
}

// Explicit template instantiation
template class HeapSort<int>;
template class HeapSort<float>;
template class HeapSort<double>;
template class HeapSort<char>;
template class HeapSort<BoardGame>;
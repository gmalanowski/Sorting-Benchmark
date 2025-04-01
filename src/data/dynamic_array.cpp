#include "data/dynamic_array.hpp"
#include "data/board_game.hpp"

// Default constructor initializing an empty DynamicArray
template<typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), capacity(0), length(0) {}

// Destructor to clean up allocated memory
template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

// Method to add an element to the end of the array
template<typename T>
void DynamicArray<T>::push_back(const T& value) {
    if (length == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[length++] = value;
}

// Method to remove the last element of the array
template<typename T>
void DynamicArray<T>::pop_back() {
    if (length == 0) {
        throw std::out_of_range("Array is empty");
    }
    --length;
}

// Operator to access an element by index
template<typename T>
T& DynamicArray<T>::operator[](std::size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Const version of the operator to access an element by index
template<typename T>
const T& DynamicArray<T>::operator[](std::size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Method to get the current size of the array
template<typename T>
std::size_t DynamicArray<T>::size() const {
    return length;
}

// Method to check if the array is empty
template<typename T>
bool DynamicArray<T>::empty() const {
    return length == 0;
}

// Method to resize the array to a new capacity
template<typename T>
void DynamicArray<T>::resize(std::size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (std::size_t i = 0; i < length; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

// Function to check if the array is sorted
template<typename T>
bool isSorted(const DynamicArray<T>& data) {
    for (std::size_t i = 1; i < data.size(); ++i) {
        if (data[i] < data[i - 1]) {
            return false;
        }
    }
    return true;
}

// Explicit instantiation of DynamicArray and isSorted for specific types
template class DynamicArray<int>;
template class DynamicArray<float>;
template class DynamicArray<double>;
template class DynamicArray<char>;
template class DynamicArray<BoardGame>;

template bool isSorted<int>(const DynamicArray<int>& data);
template bool isSorted<float>(const DynamicArray<float>& data);
template bool isSorted<double>(const DynamicArray<double>& data);
template bool isSorted<char>(const DynamicArray<char>& data);
template bool isSorted<BoardGame>(const DynamicArray<BoardGame>& data);
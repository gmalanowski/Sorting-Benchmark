#ifndef PROJEKT_DYNAMIC_ARRAY_HPP
#define PROJEKT_DYNAMIC_ARRAY_HPP

#include <stdexcept>
#include <cstddef>
#include <algorithm>
#include "board_game.h"

// Template class for DynamicArray
template<typename T>
class DynamicArray {
public:
    // Default constructor
    DynamicArray();

    // Destructor
    ~DynamicArray();

    // Adds an element to the end of the array
    void push_back(const T& value);

    // Removes the last element of the array
    void pop_back();

    // Indexing operator (modifiable)
    T& operator[](std::size_t index);

    // Indexing operator (non-modifiable)
    const T& operator[](std::size_t index) const;

    // Returns the number of elements in the array
    std::size_t size() const;

    // Checks if the array is empty
    bool empty() const;


    // Methods to support range-based for loops

    // Return pointer to the first element
    const T* begin() const;

    // Return pointer to one past the last element
    const T* end() const;

    // Copy constructor
    DynamicArray(const DynamicArray<T>& other);

    // Move assignment operator
    DynamicArray<T>& operator=(const DynamicArray<T>& other);

private:
    // Resizes the array
    void resize(std::size_t new_capacity);

    // Pointer to the array data
    T* data;

    // Capacity of the array
    std::size_t capacity;

    // Current number of elements in the array
    std::size_t length;
};

// Function to check if the array is sorted
template<typename T>
bool isSorted(const DynamicArray<T>& data);

#endif // PROJEKT_DYNAMIC_ARRAY_HPP
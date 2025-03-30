#ifndef PROJEKT_DYNAMIC_ARRAY_HPP
#define PROJEKT_DYNAMIC_ARRAY_HPP

#include <stdexcept>
#include <cstddef>
#include <algorithm>
#include "board_game.hpp"

template<typename T>
class DynamicArray {
public:
    DynamicArray();
    ~DynamicArray();

    void push_back(const T& value);
    void pop_back();
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
    std::size_t size() const;
    bool empty() const;

private:
    void resize(std::size_t new_capacity);

    T* data;
    std::size_t capacity;
    std::size_t length;
};

template<typename T>
bool isSorted(const DynamicArray<T>& data);

#endif // PROJEKT_DYNAMIC_ARRAY_HPP
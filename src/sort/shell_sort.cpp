#include "sort/shell_sort.h"

// Constructor to initialize ShellSort with custom gaps
template<typename T>
ShellSort<T>::ShellSort(const DynamicArray<std::size_t>& gaps) : gaps(gaps) {}

// Default constructor with a fallback gap sequence
template<typename T>
ShellSort<T>::ShellSort() {
    gaps.push_back(1);
}

// Method to sort data using ShellSort with custom gaps
template<typename T>
void ShellSort<T>::sort(DynamicArray<T>& data, const DynamicArray<std::size_t>& customGaps) {
    std::size_t n = data.size();

    // Iterate over the provided gap sequence
    for (std::size_t gap : customGaps) {
        // Perform a gapped insertion sort
        for (std::size_t i = gap; i < n; ++i) {
            T temp = data[i];
            std::size_t j;

            // Shift earlier gap-sorted elements up until the correct location for data[i] is found
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }

            // Put temp (the original data[i]) in its correct location
            data[j] = temp;
        }
    }
}

template<typename T>
void ShellSort<T>::sort(DynamicArray<T>& data) {
    sort(data, gaps); // Call the overloaded sort method with default gaps
}

// Explicit template instantiation
template class ShellSort<int>;
template class ShellSort<float>;
template class ShellSort<double>;
template class ShellSort<char>;
template class ShellSort<BoardGame>;
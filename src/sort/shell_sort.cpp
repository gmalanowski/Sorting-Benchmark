#include "sort/shell_sort.h"

// Method to sort data using ShellSort with custom gaps
template<typename T>
void ShellSort<T>::sort(DynamicArray<T>& data, const int customGaps) {
    // Generate gap sequence using the Knuth formula
    DynamicArray<std::size_t> gaps;
    for (std::size_t gap = 1; gap < data.size(); gap = gap * customGaps + 1) {
        gaps.push_back(gap);
    }

    // Sort the array using the gap sequence
    for (int i = gaps.size() - 1; i >= 0; --i) {
        std::size_t gap = gaps[i];
        for (std::size_t j = gap; j < data.size(); ++j) {
            T temp = data[j];
            std::size_t k;
            for (k = j; k >= gap && data[k - gap] > temp; k -= gap) {
                data[k] = data[k - gap];
            }
            data[k] = temp;
        }
    }
}

template<typename T>
void ShellSort<T>::sort(DynamicArray<T>& data) {
    sort(data, 1); // Call the overloaded sort method with default gaps
}

// Explicit template instantiation
template class ShellSort<int>;
template class ShellSort<float>;
template class ShellSort<double>;
template class ShellSort<char>;
template class ShellSort<BoardGame>;
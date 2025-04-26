#ifndef PROJEKT_SORT_ALGORITHM_HPP
#define PROJEKT_SORT_ALGORITHM_HPP

// Template class SortAlgorithm
template<typename T>
class SortAlgorithm {
public:
    // Virtual method to sort data, to be implemented in derived classes
    virtual void sort(DynamicArray<T>& data) = 0;

    // Virtual destructor
    virtual ~SortAlgorithm() = default;
};

#endif // PROJEKT_SORT_ALGORITHM_HPP
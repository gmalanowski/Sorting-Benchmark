#ifndef PROJEKT_SORT_ALGORITHM_HPP
#define PROJEKT_SORT_ALGORITHM_HPP

template<typename T>
class SortAlgorithm {
public:
    virtual void sort(DynamicArray<T>& data) = 0;
    virtual ~SortAlgorithm() = default;
};

#endif // PROJEKT_SORT_ALGORITHM_HPP
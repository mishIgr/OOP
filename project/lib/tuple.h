#ifndef tuple_h
#define tuple_h

#include <algorithm>

template <typename T, size_t S>
class Tuple {

    T arr[S];

public:

    Tuple();
    Tuple(const T, const T);
    Tuple(const Tuple<T, S>&);
    Tuple(Tuple<T, S>&&);

    Tuple<T, S>& operator=(const Tuple<T, S>&);
    Tuple<T, S>& operator=(Tuple<T, S>&&);
    Tuple<T, S> operator+(const Tuple<T, S>&);
    Tuple<T, S>& operator+=(const Tuple<T, S>&);
    T& operator[](size_t);

    size_t get_size();
};

template <typename T, size_t S>
Tuple<T, S>::Tuple() {}

template <typename T, size_t S>
Tuple<T, S>::Tuple(const T x, const T y) {
    this->arr[0] = x;
    this->arr[1] = y;
}

template <typename T, size_t S>
Tuple<T, S>::Tuple(const Tuple<T, S>& other) {
    std::copy(other.arr, other.arr + S, this->arr);
}

template <typename T, size_t S>
Tuple<T, S>::Tuple(Tuple<T, S>&& other) {
    std::swap(this->arr, other.arr);
}

template <typename T, size_t S>
Tuple<T, S>& Tuple<T, S>::operator=(const Tuple<T, S>& other) {
    if (this == &other)
        return *this;
    
    Tuple<T, S> tmp(other);
    std::swap(this->arr, tmp.arr);
    return *this;
}

template <typename T, size_t S>
Tuple<T, S>& Tuple<T, S>::operator=(Tuple<T, S>&& other) {
    if (this == &other)
        return *this;
    
    std::swap(this->arr, other.arr);
    return *this;
}

template <typename T, size_t S>
Tuple<T, S> Tuple<T, S>::operator+(const Tuple<T, S>& other) {
    Tuple<T, S> sub_tuple(other);
    for (unsigned i = 0; i < S; ++i)
        sub_tuple.arr[i] += this->arr[i];
    return sub_tuple;
}

template <typename T, size_t S>
Tuple<T, S>& Tuple<T, S>::operator+=(const Tuple<T, S>& other) {
    for (size_t i = 0; i < S; ++i)
        this->arr[i] = other.arr[i];
    return *this;
}

template <typename T, size_t S>
T& Tuple<T, S>::operator[](size_t index) {
    return this->arr[index];
}

template <typename T, size_t S>
size_t Tuple<T, S>::get_size() {
    return S;
}

#endif
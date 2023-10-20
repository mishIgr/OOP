#ifndef tuple_cpp
#define tuple_cpp

#include "tuple.h"
#include <algorithm>

template <typename T>
Tuple<T>::Tuple() : Tuple(1) {}

template <typename T>
Tuple<T>::Tuple(unsigned size) {
    this->size = size;
    this->arr = new T[size];
}

template <typename T>
Tuple<T>::Tuple(const Tuple<T>& other) : size(other.size) {
    this->arr = new T[this->size];
    std::copy(other.arr, other.arr + other.size, this->arr);
}

template <typename T>
Tuple<T>::Tuple(Tuple<T>&& other) {
    std::swap(this->size, other.size);
    std::swap(this->arr, other.arr);
}

template <typename T>
Tuple<T>& Tuple<T>::operator=(const Tuple<T>& other) {
    if (this == &other)
        return *this;
    
    Tuple<T> tmp(other);
    std::swap(this->size, tmp.size);
    std::swap(this->arr, tmp.arr);
    return *this;
}

template <typename T>
Tuple<T>& Tuple<T>::operator=(Tuple<T>&& other) {
    if (this == &other)
        return *this;
    
    std::swap(this->size, other.size);
    std::swap(this->arr, other.arr);
    return *this;
}

template <typename T>
Tuple<T> Tuple<T>::operator+(const Tuple<T>& other) {
    if (this->size != other.size)
        return *this;
    Tuple<T> sub_tuple(other);
    for (unsigned i = 0; i < this->size; ++i)
        sub_tuple.arr[i] += this->arr[i];
    return sub_tuple;
}

template <typename T>
T& Tuple<T>::operator[](unsigned index) {
    return this->arr[index];
}

template<typename T>
unsigned Tuple<T>::get_size() {
    return this->size;
}

template <typename T>
Tuple<T>::~Tuple() {
    delete [] this->arr;
}

#endif
#ifndef tuple_h
#define tuple_h

#include <algorithm>
#include <initializer_list>
#include <stdexcept>
#include <iostream>

template <typename T>
class Tuple {

    T* arr;
    size_t size;

public:

    Tuple();
    Tuple(std::initializer_list<T>);
    Tuple(const Tuple<T>&);
    Tuple(Tuple<T>&&);
    ~Tuple();

    Tuple<T>& operator=(const Tuple<T>&);
    Tuple<T>& operator=(Tuple<T>&&);
    Tuple<T> operator+(const Tuple<T>&);
    Tuple<T>& operator+=(const Tuple<T>&);
    T& operator[](size_t);

    size_t get_size();
};

template <typename T>
Tuple<T>::Tuple() : size(0), arr(nullptr) {}

template <typename T>
Tuple<T>::Tuple(std::initializer_list<T> arg) {
    this->size = arg.size();
    this->arr = new T[this->size];
    size_t i = 0;
    for (auto item : arg) {
        this->arr[i] = item;
        ++i;
    }
}

template <typename T>
Tuple<T>::Tuple(const Tuple<T>& other) : size(other.size) {
    this->arr = new T[this->size];
    std::copy(other.arr, other.arr + other.size, this->arr);
}

template <typename T>
Tuple<T>::Tuple(Tuple<T>&& other) {
    std::swap(this->arr, other.arr);
    std::swap(this->size, other.size);
}

template <typename T>
Tuple<T>::~Tuple() { delete [] this->arr; }

template <typename T>
Tuple<T>& Tuple<T>::operator=(const Tuple<T>& other) {
    if (this == &other)
        return *this;
    
    Tuple<T> tmp(other);
    std::swap(this->arr, tmp.arr);
    std::swap(this->size, tmp.size);
    return *this;
}

template <typename T>
Tuple<T>& Tuple<T>::operator=(Tuple<T>&& other) {
    if (this == &other)
        return *this;
    
    std::swap(this->arr, other.arr);
    std::swap(this->size, other.size);
    return *this;
}

template <typename T>
Tuple<T> Tuple<T>::operator+(const Tuple<T>& other) {
    if (this->size != other.size)
        throw std::logic_error("Size different.\n");
    
    Tuple<T> sub_tuple(other);
    for (unsigned i = 0; i < other.size; ++i)
        sub_tuple.arr[i] += this->arr[i];
    return sub_tuple;
}

template <typename T>
Tuple<T>& Tuple<T>::operator+=(const Tuple<T>& other) {
    if (this->size != other.size)
        throw std::logic_error("Size different.\n");
    
    for (size_t i = 0; i < other.size; ++i)
        this->arr[i] = other.arr[i];
    return *this;
}

template <typename T>
T& Tuple<T>::operator[](size_t index) {
    return this->arr[index];
}

template <typename T>
size_t Tuple<T>::get_size() {
    return this->size;
}

#endif
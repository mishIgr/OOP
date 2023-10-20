#ifndef tuple_h
#define tuple_h

template <typename T>
class Tuple {

    T* arr;
    unsigned size;

public:

    Tuple();
    Tuple(unsigned);
    Tuple(const Tuple<T>&);
    Tuple(Tuple<T>&&);

    Tuple<T>& operator=(const Tuple<T>&);
    Tuple<T>& operator=(Tuple<T>&&);
    Tuple<T>& operator+(const Tuple<T>&);
    T& operator[](unsigned);

    unsigned get_size();

    ~Tuple();

};

#endif
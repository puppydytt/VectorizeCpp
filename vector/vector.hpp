#ifndef VECTORIZECPP_VECTOR_HPP
#define VECTORIZECPP_VECTOR_HPP

#include <cstdlib>
#include <iostream>

typedef unsigned long long uint_64;

using namespace std;

template<typename T>
class vectorProto {
private:
    unsigned long long capacity;
    unsigned length;
    T *arr;
public:

    vectorProto();

    ~vectorProto();

    void push(T value);

    void out();

    T operator[](uint_64);

    void pop();

    uint_64 getCapacity();

    void exhaustVector();
};

template<typename T>
vectorProto<T>::vectorProto():capacity(), length() {
    arr = static_cast<T *>(calloc(1, sizeof(T)));
    length = 0;
    capacity = 1;
}


template<typename T>
void vectorProto<T>::push(const T value) {
    if (capacity == length) {
        capacity *= 2;
        arr = static_cast<T *>(realloc(arr, sizeof(T) * capacity));
        if (arr == NULL) {
            perror("Memory allocation failed");
            exit(-228);
        };
    }
    arr[length] = value;
    length++;
}

template<typename T>
void vectorProto<T>::out() {
    for (unsigned i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}

template<typename T>
void vectorProto<T>::pop() {
    length--;
    if (length == 0) exhaustVector();
}

template<typename T>
T vectorProto<T>::operator[](unsigned long long int index) {
    if (index > length - 1) throw out_of_range("Accessing non allocated component");
    return arr[index];
}

template<typename T>
vectorProto<T>::~vectorProto() {
    exhaustVector();
}


template<typename T>
uint_64 vectorProto<T>::getCapacity() {
    return capacity * sizeof(T);
}

template<typename T>
void vectorProto<T>::exhaustVector() {
    length = 0;
    capacity = 0;
    free(arr);
}


#endif //VECTORIZECPP_VECTOR_HPP

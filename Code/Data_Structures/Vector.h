#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#define BASE_VECTOR_SIZE 16

template <class T>
class Vector {
   public:
    Vector(T d);  // constructor
    ~Vector();    // destructor

    int size();       // returns number of elements in vector
    int capacity();   // returns capacity of vector
    bool is_empty();  // returns true if vector is empty
    void print();     // prints array, formatted

    void insert(int idx, T x);  // insert x at idx, shift elements right
    void push_back(T x);        // insert x at end of vector
    void push_front(T x);       // insert x at start of vector

    T at(int idx);           // get element at idx
    void put(int idx, T x);  // put x at idx, replaces if idx is not empty

    void delete_at(int idx);  // remove element at idx, shift elements to left
    void delete_item(T x);    // remove all instances of x
    T pop();                  // remove last element and return it

    int find(T x);  // linear search for x, returns -1 if not present

   private:
    int c, s;
    T *arr, def;
    void resize(int n);  // resize internal array to s
};

template <class T>
Vector<T>::Vector(T d) {
    c = BASE_VECTOR_SIZE;
    s = 0;
    def = d;
    arr = new T[BASE_VECTOR_SIZE];
    for (int i = 0; i < c; *(arr + i) = d, i++)
        ;
}

template <class T>
Vector<T>::~Vector() {
    delete[] arr;
}

template <class T>
int Vector<T>::size() {
    return s;
}

template <class T>
int Vector<T>::capacity() {
    return c;
}

template <class T>
bool Vector<T>::is_empty() {
    return s == 0;
}

template <class T>
void Vector<T>::print() {
    std::cout << "[ ";
    for (int i = 0; i < c; i++) {
        std::cout << *(arr + i) << ' ';
        if (i == c - 1) {
            continue;
        }
        std::cout << ", ";
    }
    std::cout << "] (Size: " << s << ", Capacity: " << c << ')' << std::endl;
}

template <class T>
void Vector<T>::insert(int idx, T x) {
    while (idx >= c || arr[c - 1] != def) {
        resize(2 * c);
    }
    for (int i = c - 1; i > idx; *(arr + i) = *(arr + i - 1), i--)
        ;
    *(arr + idx) = x;
    s++;
}
template <class T>
void Vector<T>::push_back(T x) {
    int i = c - 1;
    while (*(arr + i) == def) {
        i--;
    }
    insert(i + 1, x);
}

template <class T>
void Vector<T>::push_front(T x) {
    insert(0, x);
}

template <class T>
T Vector<T>::at(int idx) {
    if (idx >= c) {
        throw;
    }
    return *(arr + idx);
}

template <class T>
void Vector<T>::put(int idx, T x) {
    while (idx >= c) {
        resize(2 * c);
    }

    if (arr[idx] == def) {
        s++;
    }
    *(arr + idx) = x;
}

template <class T>
void Vector<T>::delete_at(int idx) {
    for (int i = idx; i < c - 1; *(arr + i) = *(arr + i + 1), i++)
        ;
    s--;
}

template <class T>
void Vector<T>::delete_item(T x) {
    for (int i = 0; i < c; i++) {
        if (*(arr + i) == x) {
            delete_at(i);
            return;
        }
    }
}

template <class T>
T Vector<T>::pop() {
    T t;
    int i = c - 1;
    while (*(arr + i) == def) {
        i--;
    }
    t = *(arr + i);
    delete_at(i);
    return t;
}

template <class T>
int Vector<T>::find(T x) {
    for (int i = 0; i < c; i++) {
        if (x == *(arr + i)) {
            return i;
        }
    }
    return -1;
}

template <class T>
void Vector<T>::resize(int n) {
    T* t = new T[n];
    for (int i = 0; i < c; *(t + i) = *(arr + i), i++)
        ;
    for (int i = c; i < n; *(t + i) = def, i++)
        ;
    delete[] arr;
    c = n;
    arr = t;
}

#endif
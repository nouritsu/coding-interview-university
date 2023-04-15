#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H

template <class T>
class Queue_ARR {
   public:
    Queue_ARR(int capacity);
    ~Queue_ARR();

    int size();       // returns size of queue
    int capacity();   // returns capacity of internal array
    bool is_empty();  // returns true if queue is empty
    bool is_full();   // returns true if queue is at capacity

    void enqueue(T x);  // add item to queue
    T dequeue();        // remove item from queue

    void print();  // prints queue, formatted

   private:
    T* arr;
    int s, c, top;
};

template <class T>
Queue_ARR<T>::Queue_ARR(int capacity) {
    arr = new T[capacity];
    for (int i = 0; i < capacity; *(arr + i) = (T)0, i++)
        ;
    s = 0;
    c = capacity;
    top = -1;
}

template <class T>
Queue_ARR<T>::~Queue_ARR() {
    delete[] arr;
}

template <class T>
int Queue_ARR<T>::size() {
    return s;
}

template <class T>
int Queue_ARR<T>::capacity() {
    return c;
}

template <class T>
bool Queue_ARR<T>::is_empty() {
    return s == 0;
}

template <class T>
bool Queue_ARR<T>::is_full() {
    return s == c;
}

template <class T>
void Queue_ARR<T>::enqueue(T x) {
    if (is_full()) {
        throw;
    }
    arr[++top] = x;
    s++;
}

template <class T>
T Queue_ARR<T>::dequeue() {
    T t = arr[0];
    for (int i = 0; i < c - 1; *(arr + i) = *(arr + i + 1), i++)
        ;
    s--;
    top--;
    return t;
}

template <class T>
void Queue_ARR<T>::print() {
    std::cout << "<-- [ ";
    for (int i = 0; i < s; i++) {
        std::cout << *(arr + i) << ' ';
        if (i != s - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "] <-- (Size: " << s << ", Capacity: " << c << ')'
              << std::endl;
}

#endif
#ifndef STACK_H
#define STACK_H

template <class T>
class Stack {
   public:
    Stack(int capacity);  // constructor
    ~Stack();             // destructor

    int capacity();   // returns capacity of stack
    int size();       // returns size of stack
    bool is_empty();  // returns true if stack is empty

    void push(T x);  // push element to stack
    T peek();        // peek element on top of stack
    T pop();         // removes and returns element on top of stack

    void print();  // prints stack, formatted

   private:
    T* arr;
    int top, c, s;
};

template <class T>
Stack<T>::Stack(int capacity) {
    arr = new T[capacity];
    top = -1;
    c = capacity;
}

template <class T>
Stack<T>::~Stack() {
    delete[] arr;
}

template <class T>
int Stack<T>::capacity() {
    return c;
}

template <class T>
int Stack<T>::size() {
    return top + 1;
}

template <class T>
bool Stack<T>::is_empty() {
    return top == -1;
}

template <class T>
void Stack<T>::push(T x) {
    arr[++top] = x;
}

template <class T>
T Stack<T>::peek() {
    return arr[top];
}

template <class T>
T Stack<T>::pop() {
    return arr[top--];
}

template <class T>
void Stack<T>::print() {
    std::cout << "<end>" << std::endl;
    for (int i = 0; i < c - top - 1; i++) {
        std::cout << (T)0 << std::endl;
    }
    for (int i = top; i >= 0; i--) {
        std::cout << arr[i];
        if (i == top) {
            std::cout << " <- top of stack";
        }
        std::cout << std::endl;
    }

    std::cout << "<start>" << std::endl;
    std::cout << "(Size: " << top + 1 << ", Capacity: " << c << ')'
              << std::endl;
}

#endif
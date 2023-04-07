#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class Node {
   public:
    Node(T x);
    T data;
    Node *next, *prev;
};

template <class T>
Node<T>::Node(T x) {
    data = x;
    next = nullptr;
    prev = nullptr;
}

template <class T>
class LinkedList {
   public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    int size();       // returns number of elements in list
    bool is_empty();  // returns true if list is empty
    void print();     // prints linked list

    void push_front(T x);  // insert x at start of list
    T pop_front();         // remove first element and return it
    T peek_front();        // returns first element

    void push_back(T x);  // insert x at end of list
    T pop_back();         // removes last element and return it
    T peek_back();        // returns last element

    void insert(int idx, T x);  // insert x at idx //TODO
    T at(int idx);              // returns element at idx
    T at_n_from_end(int n);     // returns element at nth position from end

    void delete_at(int idx);  // remove idxth node //TODO
    void delete_all(T x);     // remove all nodes containing x

    bool find(T x);  // linear search for x, returns true if present
    void reverse();  // reverse the list //TODO

   private:
    Node<T> *head, *tail;
    int s;
};

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    s = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    for (int i = 0; i < s; i++) {
        // delete_at(i);
    }
}

template <class T>
int LinkedList<T>::size() {
    return s;
}

template <class T>
bool LinkedList<T>::is_empty() {
    return s == 0;
}

template <class T>
void LinkedList<T>::print() {
    Node<T> *c;
    std::cout << "[ ";

    c = head;
    for (int i = 0; i < s; i++) {
        std::cout << c->data << ' ';
        c = c->next;
        if (i == s - 1) {
            continue;
        }
        std::cout << "-> ";
    }
    std::cout << "]" << std::endl;
}

template <class T>
void LinkedList<T>::push_front(T x) {
    Node<T> *n = new Node<T>(x);
    if (!head) {
        head = n;
        tail = n;
    } else {
        n->next = head;
        head->prev = n;
        head = n;
    }
    s++;
}

template <class T>
T LinkedList<T>::pop_front() {
    if (!head) {
        return (T)0;
    }

    T t = head->data;
    delete_at(0);
    return t;
}

template <class T>
T LinkedList<T>::peek_front() {
    if (!head) {
        return (T)0;
    }

    T t = head->data;
    return t;
}

template <class T>
void LinkedList<T>::push_back(T x) {
    Node<T> *n = new Node<T>(x);
    if (!tail) {
        head = n;
        tail = n;
    } else {
        n->prev = tail;
        tail->next = n;
        tail = n;
    }
    s++;
}

template <class T>
T LinkedList<T>::pop_back() {
    if (!tail) {
        return (T)0;
    }

    T t = tail->data;
    delete_at(s - 1);
    return t;
}

template <class T>
T LinkedList<T>::peek_back() {
    if (!tail) {
        return (T)0;
    }

    T t = tail->data;
    return t;
}

template <class T>
void LinkedList<T>::insert(int idx, T x) {}

template <class T>
T LinkedList<T>::at(int idx) {
    if (idx >= s) {
        return (T)0;
    }

    Node<T> *c;
    c = head;
    for (int i = 0; i < idx; i++) {
        c = c->next;
    }
    return c->data;
}

template <class T>
T LinkedList<T>::at_n_from_end(int n) {
    if (n >= s) {
        return (T)0;
    }

    Node<T> *c;
    c = tail;
    for (int i = 0; i < n; i++) {
        c = c->prev;
    }
    return c->data;
}

template <class T>
void LinkedList<T>::delete_at(int idx) {}

template <class T>
void LinkedList<T>::delete_all(T x) {
    Node<T> *c;
    c = head;
    for (int i = 0; i < s; i++) {
        if (c->data == x) {
            delete_at(i);
        }
        c = c->next;
    }
}

template <class T>
bool LinkedList<T>::find(T x) {
    if (!head | !tail) {
        return false;
    }

    Node<T> *c;
    c = head;
    for (int i = 0; i < s; i++) {
        if (c->data == x) {
            return true;
        }
        c = c->next;
    }
    return false;
}

template <class T>
void LinkedList<T>::reverse() {}

#endif
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "./Linked_List_Node.h"

template <class T>
class LinkedList {
   public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    int size();       // returns number of elements in list
    bool is_empty();  // returns true if list is empty
    void print();     // prints linked list, formatted

    void push_front(T x);  // insert x at start of list
    T pop_front();         // remove first element and return it
    T peek_front();        // returns first element

    void push_back(T x);  // insert x at end of list
    T pop_back();         // removes last element and return it
    T peek_back();        // returns last element

    void insert(int idx, T x);  // insert x at idx
    T at(int idx);              // returns element at idx
    T at_n_from_end(int n);     // returns element at nth position from end

    void delete_at(int idx);  // remove idxth node
    void delete_item(T x);    // remove first node from head containing x

    bool find(T x);  // linear search for x, returns true if present
    void reverse();  // reverse the list

   private:
    int s;
    Node<T> *head, *tail;
    Node<T> *traverse_to(int idx);  // returns node at idx
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
        delete_at(i);
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
    std::cout << "| ";

    c = head;
    for (int i = 0; i < s; i++) {
        std::cout << c->data << ' ';
        c = c->next;
        if (i == s - 1) {
            continue;
        }
        std::cout << "<-> ";
    }
    std::cout << "| (Size: " << s << ')' << std::endl;
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
void LinkedList<T>::insert(int idx, T x) {
    if (idx > s) {
        throw;
    }

    if (idx == 0) {
        push_front(x);
    } else if (idx == s) {
        push_back(x);
    } else {
        Node<T> *n = new Node<T>(x);
        Node<T> *c = traverse_to(idx);
        n->next = c;
        n->prev = c->prev;
        c->prev->next = n;
        c->prev = n;
        s++;
    }
}

template <class T>
T LinkedList<T>::at(int idx) {
    Node<T> *c = traverse_to(idx);
    return c ? c->data : (T)0;
}

template <class T>
T LinkedList<T>::at_n_from_end(int n) {
    Node<T> *c = traverse_to(s - n - 1);
    return c ? c->data : (T)0;
}

template <class T>
void LinkedList<T>::delete_at(int idx) {
    Node<T> *c = traverse_to(idx);
    if (!c) {  // cannot delete something that does not exist
        throw;
    }

    if (!c->next && !c->prev) {  // list only has 1 item
        head = nullptr;
        tail = nullptr;
    } else if (!c->prev) {  // item is at start
        head = c->next;
        c->next->prev = nullptr;
    } else if (!c->next) {  // item is at end
        tail = c->prev;
        c->prev->next = nullptr;
    } else {  // item is somewhere in the middle
        c->prev->next = c->next;
        c->next->prev = c->prev;
    }
    delete c;
    s--;
}

template <class T>
void LinkedList<T>::delete_item(T x) {
    Node<T> *c;
    c = head;
    for (int i = 0; i < s; i++) {
        if (c->data == x) {
            delete_at(i);
            return;
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
void LinkedList<T>::reverse() {
    for (int i = 0; i < s; insert(i, pop_back()), i++)
        ;
}

template <class T>
Node<T> *LinkedList<T>::traverse_to(int idx) {
    if (!head || !tail || idx >= s || idx < 0) {
        return nullptr;
    }

    auto from_start = [&, idx]() {
        Node<T> *cursor = head;
        for (int i = 0; i < idx; i++) {
            cursor = cursor->next;
        }
        return cursor;
    };

    auto from_end = [&, idx]() {
        Node<T> *cursor = tail;
        for (int i = 0; i < s - idx - 1; i++) {
            cursor = cursor->prev;
        }
        return cursor;
    };

    return (idx < s / 2) ? from_start() : from_end();
}

#endif
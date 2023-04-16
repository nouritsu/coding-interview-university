#ifndef QUEUE_LL_H
#define QUEUE_LL_H

#include "./Linked_List_Node.h"
#include "Queue_ARR.h"

template <class T>
class QueueLL {
   public:
    QueueLL();   // constructor
    ~QueueLL();  // destructor

    int size();       // returns size of queue
    bool is_empty();  // returns true if queue is empty

    void enqueue(T x);  // add item to queue
    T dequeue();        // remove item from queue

    void print();  // prints queue, formatted

   private:
    Node<T> *head, *tail;
    int s;
};

template <class T>
QueueLL<T>::QueueLL() {
    head = nullptr;
    tail = nullptr;
    s = 0;
}

template <class T>
QueueLL<T>::~QueueLL() {
    for (int i = 0; i < s; i++) {
        dequeue();
    }
}

template <class T>
int QueueLL<T>::size() {
    return s;
}

template <class T>
bool QueueLL<T>::is_empty() {
    return s == 0;
}

template <class T>
void QueueLL<T>::enqueue(T x) {
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
T QueueLL<T>::dequeue() {
    if (!head) {
        throw;
    }

    Node<T> *c = head;
    T t = head->data;
    head = c->next;
    c->next->prev = nullptr;

    s--;
    delete c;
    return t;
}

template <class T>
void QueueLL<T>::print() {
    Node<T> *c = head;

    std::cout << "<-- | ";
    for (int i = 0; i < s; i++) {
        std::cout << c->data << ' ';
        if (i != s - 1) {
            std::cout << "<-> ";
        }
        c = c->next;
    }
    std::cout << "| <-- (Size: " << s << ')' << std::endl;
}

#endif

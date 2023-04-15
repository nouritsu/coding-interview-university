#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template <class T>
class Node {
   public:
    Node(T x) : data(x), next(nullptr), prev(nullptr){};  // constructor
    T data;
    Node *next, *prev;
};
#endif

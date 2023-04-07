#include <iostream>
#include <string>

#include "./Linked_List/Linked_List.h"
#include "./Vector/Vector.h"

using namespace std;

int main(void) {
    LinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_front(0);
    l.print();

    return 0;
}

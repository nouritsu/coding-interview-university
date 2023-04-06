#include <iostream>
#include <string>

#include "./Vector/Vector.h"

using namespace std;

int main(void) {
    Vector<int> vec(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vec.print();
    vec.pop();
    vec.print();
    return 0;
}

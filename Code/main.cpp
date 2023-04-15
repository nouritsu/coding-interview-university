#include <assert.h>

#include <iostream>
#include <string>

#include "./Data_Structures/Linked_List.h"
#include "./Data_Structures/Queue_ARR.h"
#include "./Data_Structures/Queue_LL.h"
#include "./Data_Structures/Stack.h"
#include "./Data_Structures/Vector.h"

using namespace std;

void test_vector();
void test_linked_list();
void test_stack();
void test_queue_ll();
void test_queue_arr();

int main(void) {
    test_vector();
    return 0;
}

void test_vector() {
    cout << "------------------------------------------------------------------"
            "------- VECTOR TEST "
            "------------------------------------------------------------------"
            "-------"
         << endl;

    Vector<int> vec(0);

    cout << "STATS TEST 1: " << endl;
    cout << "Size (should be 0): " << vec.size() << endl;
    cout << "Capacity (should be 16): " << vec.capacity() << endl;
    cout << "Is_Empty (should be true): " << vec.is_empty() << endl;
    cout << endl;

    cout << "PRINT TEST: " << endl;
    vec.print();
    cout << endl;

    cout << "INSERT TESTS: " << endl;
    cout << "Inserting 2 at index 0: " << endl;
    vec.insert(0, 2);
    vec.print();
    cout << "Pushing 3 to back: " << endl;
    vec.push_back(3);
    vec.print();
    cout << "Inserting 1 to front: " << endl;
    vec.push_front(1);
    vec.print();
    cout << "Inserting 4 at index 3: " << endl;
    vec.insert(3, 4);
    vec.print();
    cout << endl;

    cout << "ARRAY METHOD TESTS: " << endl;
    cout << "Item at index 2 (should be 3): " << vec.at(2) << endl;
    cout << "Setting index 4 to 6: " << endl;
    vec.put(4, 6);
    vec.print();
    cout << endl;

    cout << "STATS TEST 2: " << endl;
    cout << "Size (should be 3): " << vec.size() << endl;
    cout << "Capacity (should be 16): " << vec.capacity() << endl;
    cout << "Is_Empty (should be false): " << vec.is_empty() << endl;
    cout << endl;

    cout << "DELETE TESTS: " << endl;
    cout << "Deleting element at index 4: " << endl;
    vec.delete_at(4);
    vec.print();
    cout << "Pushing back item '5' 3 times: " << endl;
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    vec.print();
    cout << "Deleting first instance of 5: " << endl;
    vec.delete_item(5);
    vec.print();
    cout << "Deleting one more instance of 5: " << endl;
    vec.delete_item(5);
    vec.print();
    cout << "Using pop method: " << endl;
    cout << "Popped item (should be 5): " << vec.pop() << endl;
    vec.print();
    cout << endl;

    cout << "STATS TEST 3: " << endl;
    cout << "Size (should be 4): " << vec.size() << endl;
    cout << "Capacity (should be 16): " << vec.capacity() << endl;
    cout << "Is_Empty (should be false): " << vec.is_empty() << endl;
    cout << endl;

    cout << "SEARCH TEST: " << endl;
    cout << "Searching for 3 (should be index 2): " << vec.find(3) << endl;
    cout << "Searching for 55 (should be -1): " << vec.find(55) << endl;
    cout << endl;

    cout << "RESIZE TEST: " << endl;
    cout << "Forcing resize by pushing 1 13 times: " << endl;
    for (int i = 0; i < 13; i++) {
        vec.push_back(1);
    }
    vec.print();
    cout << endl;

    cout << "STATS TEST 4: " << endl;
    cout << "Size (should be 17): " << vec.size() << endl;
    cout << "Capacity (should be 32): " << vec.capacity() << endl;
    cout << "Is_Empty (should be false): " << vec.is_empty() << endl;
    cout << endl;

    cout << "------------------------------------------------------------------"
            "------------------------------------------------------------------"
            "---------------------------"
         << endl;
};

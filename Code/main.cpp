#include <assert.h>

#include <iostream>
#include <string>

#include "./Data_Structures/Linked_List.h"
#include "./Data_Structures/Queue_ARR.h"
#include "./Data_Structures/Queue_LL.h"
#include "./Data_Structures/Stack.h"
#include "./Data_Structures/Vector.h"

using std::cout;
using std::endl;

void test_vector();
void test_linked_list();
void test_stack();
void test_queue_ll();
void test_queue_arr();

int main(void) {
    // test_vector();
    // test_linked_list();
    // test_stack();
    // test_queue_ll();
    // test_queue_arr();
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

    cout << "INSERT TEST: " << endl;
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

    cout << "ARRAY METHOD TEST: " << endl;
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

    cout << "DELETE TEST: " << endl;
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

void test_linked_list() {
    cout << "-------------------- LINKED_LIST TEST --------------------"
         << endl;

    LinkedList<int> ll;

    cout << "STATS TEST 1: " << endl;
    cout << "Size (should be 0): " << ll.size() << endl;
    cout << "Is_Empty (should be true): " << ll.is_empty() << endl;
    cout << endl;

    cout << "PRINT TEST: " << endl;
    ll.print();
    cout << endl;

    cout << "STACK METHOD TEST: " << endl;
    cout << "Pushing 2 to front: " << endl;
    ll.push_front(2);
    ll.print();
    cout << "Pushing 1 to front: " << endl;
    ll.push_front(1);
    ll.print();
    cout << "Pushing 3 to front: " << endl;
    ll.push_front(3);
    ll.print();
    cout << "Peeking front (should be 3): " << ll.peek_front() << endl;
    cout << "Popping front (should be 3): " << ll.pop_front() << endl;
    ll.print();
    cout << "Pushing 3 to back: " << endl;
    ll.push_back(3);
    ll.print();
    cout << "Pushing 5 to back: " << endl;
    ll.push_back(5);
    ll.print();
    cout << "Pushing 2 to back: " << endl;
    ll.push_back(2);
    ll.print();
    cout << "Peeking back (should be 2) " << ll.peek_back() << endl;
    cout << "Popping back (should be 2): " << ll.pop_back() << endl;
    ll.print();
    cout << endl;

    cout << "STATS TEST 2: " << endl;
    cout << "Size (should be 4): " << ll.size() << endl;
    cout << "Is_Empty (should be false): " << ll.is_empty() << endl;
    cout << endl;

    cout << "ARRAY METHOD TEST: " << endl;
    cout << "Inserting 4 at index 3: " << endl;
    ll.insert(3, 4);
    ll.print();
    cout << "Inserting 5 at index 5" << endl;
    ll.insert(5, 5);
    ll.print();
    cout << "Item at index 2 (should be 3): " << ll.at(2) << endl;
    cout << "Item at index 1 from end (should be 5): " << ll.at_n_from_end(1)
         << endl;
    cout << endl;

    cout << "STATS TEST 3: " << endl;
    cout << "Size (should be 6): " << ll.size() << endl;
    cout << "Is_Empty (should be false): " << ll.is_empty() << endl;
    cout << endl;

    cout << "DELETE TEST: " << endl;
    cout << "Deleting item at index 3: " << endl;
    ll.delete_at(3);
    ll.print();
    cout << "Deleting first instance of 5: " << endl;
    ll.delete_item(5);
    ll.print();
    cout << "Deleting another instance of 5: " << endl;
    ll.delete_item(5);
    ll.print();
    cout << endl;

    cout << "STATS TEST 4: " << endl;
    cout << "Size (should be 3): " << ll.size() << endl;
    cout << "Is_Empty (should be false): " << ll.is_empty() << endl;
    cout << endl;

    cout << "SEARCH TEST: " << endl;
    cout << "Searching for 2 (should be true): " << ll.find(2) << endl;
    cout << "Searching for 12 (should be false): " << ll.find(12) << endl;
    cout << endl;

    cout << "REVERSE TEST: " << endl;
    ll.reverse();
    ll.print();
    cout << endl;

    cout << "----------------------------------------------------------"
         << endl;
}

void test_stack() {
    cout << "-------------------- STACK TEST --------------------" << endl;

    Stack<int> s(16);

    cout << "STATS TEST 1: " << endl;
    cout << "Size (should be 0): " << s.size() << endl;
    cout << "Capacity (should be 16): " << s.capacity() << endl;
    cout << "Is_Empty (should be true): " << s.is_empty() << endl;
    cout << endl;

    cout << "PRINT TEST: " << endl;
    s.print();
    cout << endl;

    cout << "STACK METHOD TEST: " << endl;
    cout << "Pushing 1: " << endl;
    s.push(1);
    s.print();
    cout << "Pushing 2: " << endl;
    s.push(2);
    s.print();
    cout << "Pushing 3: " << endl;
    s.push(3);
    s.print();
    cout << "Peeking (should be 3): " << s.peek() << endl;
    cout << "Popping (should be 3): " << s.pop() << endl;
    s.print();
    cout << endl;

    cout << "STATS TEST 2: " << endl;
    cout << "Size (should be 2): " << s.size() << endl;
    cout << "Capacity (should be 16): " << s.capacity() << endl;
    cout << "Is_Empty (should be false): " << s.is_empty() << endl;
    cout << endl;

    cout << "----------------------------------------------------" << endl;
}

void test_queue_ll() {
    cout << "-------------------- QUEUE_LL TEST --------------------" << endl;

    QueueLL<int> q;

    cout << "STATS TEST 1: " << endl;
    cout << "Size (should be 0): " << q.size() << endl;
    cout << "Is_Empty (should be true): " << q.is_empty() << endl;
    cout << endl;

    cout << "QUEUE METHOD TEST: " << endl;
    cout << "Enqueueing 1: " << endl;
    q.enqueue(1);
    q.print();
    cout << "Enqueueing 2: " << endl;
    q.enqueue(2);
    q.print();
    cout << "Enqueueing 3: " << endl;
    q.enqueue(3);
    q.print();
    cout << "Enqueueing 4: " << endl;
    q.enqueue(4);
    q.print();
    cout << "Dequeueing (should be 1): " << q.dequeue() << endl;
    q.print();
    cout << "Dequeueing (should be 2): " << q.dequeue() << endl;
    q.print();
    cout << endl;

    cout << "STATS TEST 2: " << endl;
    cout << "Size (should be 2): " << q.size() << endl;
    cout << "Is_Empty (should be false): " << q.is_empty() << endl;
    cout << endl;

    cout << "-------------------------------------------------------" << endl;
}

void test_queue_arr() {
    cout << "---------------------------- QUEUE_ARR TEST "
            "----------------------------"
         << endl;

    QueueARR<int> q(8);

    cout << "STATS TEST 1: " << endl;
    cout << "Size (should be 0): " << q.size() << endl;
    cout << "Capacity (should be 8): " << q.capacity() << endl;
    cout << "Is_Empty (should be true): " << q.is_empty() << endl;
    cout << "Is_Full (should be false): " << q.is_full() << endl;
    cout << endl;

    cout << "QUEUE METHOD TEST: " << endl;
    cout << "Enqueueing 1: " << endl;
    q.enqueue(1);
    q.print();
    cout << "Enqueueing 2: " << endl;
    q.enqueue(2);
    q.print();
    cout << "Enqueueing 3: " << endl;
    q.enqueue(3);
    q.print();
    cout << "Enqueueing 4: " << endl;
    q.enqueue(4);
    q.print();
    cout << "Dequeueing (should be 1): " << q.dequeue() << endl;
    q.print();
    cout << "Dequeueing (should be 2): " << q.dequeue() << endl;
    q.print();
    cout << endl;

    cout << "STATS TEST 2: " << endl;
    cout << "Size (should be 2): " << q.size() << endl;
    cout << "Capacity (should be 8): " << q.capacity() << endl;
    cout << "Is_Empty (should be false): " << q.is_empty() << endl;
    cout << "Is_Full (should be false): " << q.is_full() << endl;
    cout << endl;

    cout << "STATS TEST 3: " << endl;
    cout << "Enqueueing -1 6 times" << endl;
    for (int i = 0; i < 6; i++) {
        q.enqueue(-1);
    }
    q.print();
    cout << "Size (should be 8): " << q.size() << endl;
    cout << "Capacity (should be 8): " << q.capacity() << endl;
    cout << "Is_Empty (should be false): " << q.is_empty() << endl;
    cout << "Is_Full (should be true): " << q.is_full() << endl;
    cout << endl;

    cout << "------------------------------------------------------------------"
            "-----"
         << endl;
}
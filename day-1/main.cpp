#include <iostream>

#include "LinkedList.h"

int main() {
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.print();
    ll.pop_front();
    ll.print();
}
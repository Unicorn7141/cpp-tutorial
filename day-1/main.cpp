#include <iostream>

#include "LinkedList.h"

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.print();
    ll.pop_front();
    ll.print();
}
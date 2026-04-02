//
// Created by harel on 02/04/2026.
//

#ifndef DAY_1_LINKEDLIST_H
#define DAY_1_LINKEDLIST_H

#include <memory>
#include <utility>
#include <iostream>
#include "Node.h"

class LinkedList {
    std::unique_ptr<Node> head;
public:
    // TIP Task: Move Constructor
    LinkedList() = default;
    LinkedList(LinkedList&& other) noexcept : head(std::move(other.head)) {}

    // TODO: push_front()
    void push_front(const int val) {
        // We must initialize the Node members manually since no constructor was provided
        auto newNode = std::make_unique<Node>();
        newNode->value = val;

        // Transfer ownership of the current head to the new node's next
        newNode->next = std::move(head);

        // The new node now becomes the head
        head = std::move(newNode);
    }

    // TODO: pop_front()
    void pop_front() {
        if (head) {
            // Transfer ownership of the second node into 'head'
            // The old 'head' node is automatically deleted
            head = std::move(head->next);
        }
    }

    // TODO: print()
    void print() const {
        // Using a non-owning node to traverse
        Node* current = head.get();
        while (current) {
            std::cout << current->value << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }
};
#endif //DAY_1_LINKEDLIST_H

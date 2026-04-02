//
// Created by harel on 02/04/2026.
//

#ifndef DAY_1_NODE_H
#define DAY_1_NODE_H
#pragma once
#include <memory>
struct Node {
    int value;
    std::unique_ptr<Node> next;
};
#endif //DAY_1_NODE_H

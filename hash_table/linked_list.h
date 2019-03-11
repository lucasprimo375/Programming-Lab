#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

class LinkedList {
public:
    LinkedList();

    ~LinkedList();

    void include_node(Node* node);

    void print_nodes();

public:
    Node* head_;
};

#endif
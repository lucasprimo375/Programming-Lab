#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "linked_list.h"
#include "node.h"

class HashTable {
public:
    HashTable(int linked_lists_size);

    ~HashTable();

    void include_element(Node* node);

    void print_elements();

private:
    int linked_lists_size_;
    LinkedList* linked_lists_;
};

#endif
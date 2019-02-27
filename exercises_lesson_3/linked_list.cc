#include <iostream>

#include "linked_list.h"

LinkedList::LinkedList(){
    head_ = nullptr;
}

LinkedList::~LinkedList(){
    Node* node = head_;

    while(node != nullptr){
        Node* temp_node = node->next();
        delete node;
        node = temp_node;
    }
}

void LinkedList::include_node(Node* node){
    node->set_next(head_);
    head_ = node;
}

void LinkedList::print_nodes(){
    Node* node = head_;

    while(node != nullptr){
        std::cout << node->get_data() << std::endl;
        node = node->next();
    }
}
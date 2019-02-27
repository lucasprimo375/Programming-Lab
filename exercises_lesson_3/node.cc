#include "node.h"
#include <iostream>

Node::Node(int data, Node* next){
    data_ = data;
    next_ = next;
}

void Node::set_next(Node* next){
    next_ = next;
}

Node* Node::next(){
    return next_;
}

int Node::get_data(){
    return data_;
}
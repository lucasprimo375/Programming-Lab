#include <iostream>

#include "hash_table.h"

HashTable::HashTable(int linked_lists_size){
    linked_lists_size_ = linked_lists_size;
    linked_lists_ = new LinkedList[linked_lists_size_];
}

HashTable::~HashTable(){
    /*for(int i=0; i<linked_lists_size_; i++){
        //delete linked_lists_[i];
    }*/
    delete[] linked_lists_;
}

void HashTable::include_element(Node* node){
    int list_to_receive = node->get_data() % linked_lists_size_;

    linked_lists_[list_to_receive].include_node(node);
}

void HashTable::print_elements(){
    for(int i=0; i<linked_lists_size_; i++){
        std::cout << "printing linked list " << i << std::endl;

        linked_lists_[i].print_nodes();

        std::cout << std::endl;
    }
}
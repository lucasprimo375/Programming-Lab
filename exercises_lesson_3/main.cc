#include <iostream>

#include "node.h"
#include "linked_list.h"
#include "hash_table.h"

int get_input_from_user(std::string message);

int main(){
    int linked_lists_number = get_input_from_user("input the number of linked lists in the hash table: ");
    if(linked_lists_number <= 0){
        return 0;
    }

    HashTable hash_table(linked_lists_number);

    int user_input = 1;
    bool done = false;

    while(!done){
        user_input = get_input_from_user("input positive integer (negative integer to end): ");
        if(user_input >= 0){
            Node* node = new Node(user_input);
            hash_table.include_element(node);
        } else {
            done = true;
        }
    }

    hash_table.print_elements();
}

int get_input_from_user(std::string message){
    std::cout << message;

    int input;

    std::cin >> input;

    return input;
}
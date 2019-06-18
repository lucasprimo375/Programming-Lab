#include <iostream>

#include "user_input.h"
#include "utils.h"

#include "node.h"
#include "min_heap.h"

int main() {
	//Utils::print_file( UserInput::get_file_to_encode() );

	node* node1 = new node();
	node1->character = 'a';
	node1->frequency = 10;

	node* node2 = new node();
	node2->character = 'b';
	node2->frequency = 5;

	node* node3 = new node();
	node3->character = 'c';
	node3->frequency = 4;

	node** nodes = new node*[3];

	nodes[0] = node1;
	nodes[1] = node2;
	nodes[2] = node3;

	MinHeap minHeap(3, nodes);

	minHeap.print();

	std::cout << minHeap.getMin()->character << std::endl;

	minHeap.print();

	return 0;
}
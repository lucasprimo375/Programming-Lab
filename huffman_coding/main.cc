#include <iostream>
#include <string>

#include "user_input.h"
#include "utils.h"

#include "node.h"
#include "min_heap.h"

int main() {
	node* node1 = new node();
	node1->character = 'a';
	node1->frequency = 10;

	node* node2 = new node();
	node2->character = 'b';
	node2->frequency = 5;

	node* node3 = new node();
	node3->character = 'c';
	node3->frequency = 6;

	node* node4 = new node();
	node4->character = 'd';
	node4->frequency = 11;

	node** nodes = new node*[4];
	nodes[0] = node1;
	nodes[1] = node2;
	nodes[2] = node3;
	nodes[3] = node4;

	MinHeap minHeap;

	minHeap.addNode(node1);
	minHeap.print();
	std::cout << std::endl;

	minHeap.addNode(node2);
	minHeap.print();
	std::cout << std::endl;

	minHeap.addNode(node3);
	minHeap.print();
	std::cout << std::endl;

	minHeap.getMin();
	minHeap.print();
	std::cout << std::endl;

	minHeap.addNode(node4);
	minHeap.print();
	std::cout << std::endl;

	return 0;
}
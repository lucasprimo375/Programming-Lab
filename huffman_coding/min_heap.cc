#include <iostream>

#include "node.h"
#include "min_heap.h"

MinHeap::MinHeap(int size, node** nodes) {
	size_ = size;

	nodes_ = nodes;

	buildHeap();
}

node* MinHeap::getMin() {

}

void MinHeap::print() {
	for( int i = 0; i < size_; i++ ) {
		std::cout << "node at " << i << " is " << nodes_[i]->character << " whith frequency " << nodes_[i]->frequency << std::endl;
	}
}

void MinHeap::heapify(int index) {
	int smallest;

	int left = 2*index + 1;
	int right = 2*index + 2;

	if( (left < size_) && (nodes_[left]->frequency < nodes_[index]->frequency) )
		smallest = left;
	else smallest = index;

	if( (right < size_) && (nodes_[right]->frequency < nodes_[index]->frequency) )
		smallest = right;

	if( smallest != index ) {
		node* n = nodes_[smallest];

		nodes_[smallest] = nodes_[index];

		nodes_[index] = n;

		heapify(smallest);
	}
}

void MinHeap::buildHeap() {
	for( int i = size_/2; i >= 0; i-- )
		heapify(i);
}
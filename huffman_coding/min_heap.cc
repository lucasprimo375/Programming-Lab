#include <iostream>

#include "node.h"
#include "min_heap.h"

MinHeap::MinHeap(int size, node** nodes) {
	size_ = size;

	nodes_ = nodes;

	buildHeap();
}

MinHeap::MinHeap() {
	size_ = 0;
}

node* MinHeap::getMin() {
	if( size_ == 0 ) return nullptr;

	node* minNode = nodes_[0];

	node** newNodes = new node*[size_ - 1];

	newNodes[0] = nodes_[size_ - 1];

	for( int i = 1; i<size_ - 1; i++ ) {
		newNodes[i] = nodes_[i];
	}

	delete nodes_;

	nodes_ = newNodes;

	size_--;

	heapify(0);

	return minNode;
}

void MinHeap::print() {
	for( int i = 0; i < size_; i++ ) {
		std::cout << "node at " << i << " is " << nodes_[i]->character << " with frequency " << nodes_[i]->frequency << std::endl;
	}
}

void MinHeap::addNode(node* n) {
	node** newNodes = new node*[size_ + 1];

	newNodes[size_] = n;

	for( int i = 0; i < size_; i++ )
		newNodes[i] = nodes_[i];

	if( size_ != 0 ) delete nodes_;

	nodes_ = newNodes;

	size_++;

	heapifyBottomUp(size_ - 1);
}

int MinHeap::getSize() {
	return size_;
}

void MinHeap::heapify(int index) {
	int smallest;

	int left = 2*index + 1;
	int right = 2*index + 2;

	if( (left < size_) && (nodes_[left]->frequency < nodes_[index]->frequency) )
		smallest = left;
	else smallest = index;

	if( (right < size_) && (nodes_[right]->frequency < nodes_[smallest]->frequency) )
		smallest = right;

	if( smallest != index ) {
		node* n = nodes_[smallest];

		nodes_[smallest] = nodes_[index];

		nodes_[index] = n;

		heapify(smallest);
	}
}

void MinHeap::heapifyBottomUp(int index) {
	int parent = ( index - 1 ) / 2;

	while( ( index > 0 ) && ( nodes_[parent]->frequency > nodes_[index]->frequency ) ) {
		node* n = nodes_[parent];

		nodes_[parent] = nodes_[index];

		nodes_[index] = n;

		index = parent;

		parent = ( index - 1 ) / 2;
	}
}

void MinHeap::buildHeap() {
	for( int i = size_/2; i >= 0; i-- )
		heapify(i);
}
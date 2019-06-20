#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "node.h"

class MinHeap {
public:
	MinHeap(int size, node** nodes);

	MinHeap();

	node* getMin();

	void print();

	void addNode(node* n);

private:
	void heapify(int index);

	void heapifyBottomUp(int index);

	void buildHeap();

	int size_;

	node** nodes_;
};

#endif
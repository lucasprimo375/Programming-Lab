#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "node.h"

class MinHeap {
public:
	MinHeap(int size, node** nodes);

	node* getMin();

	void print();

private:
	void heapify(int index);

	void buildHeap();

	int size_;

	node** nodes_;
};

#endif
#ifndef POINTER_BASED_QUICK_SORT_H
#define POINTER_BASED_QUICK_SORT_H

#include "generic_quick_sort.h"

class PointerBasedQuickSort : public GenericQuickSort {
public:
	PointerBasedQuickSort(int* vector, int size);
	~PointerBasedQuickSort();
	void sort();

private:
	void quick_sort(int initial_index, int last_index);
	int partition(int initial_index, int last_index);
};

#endif
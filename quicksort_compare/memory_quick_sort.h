#ifndef MEMORY_QUICK_SORT_H
#define MEMORY_QUICK_SORT_H

#include "generic_quick_sort.h"

class MemoryQuickSort : public GenericQuickSort {
public:
	MemoryQuickSort(int* vector, int size, bool is_bad_instance);
	~MemoryQuickSort();
	void sort();

private:
	void quick_sort(int initial_index, int last_index);
	int partition(int initial_index, int last_index);
};

#endif
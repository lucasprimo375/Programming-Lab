#ifndef BFPRT_QUICK_SORT_H
#define BFPRT_QUICK_SORT_H

#include "generic_quick_sort.h"

class BfprtQuickSort : public GenericQuickSort {
public:
	BfprtQuickSort(int* vector, int size);
	~BfprtQuickSort();
	void sort();

private:
	void quick_sort(int initial_index, int last_index);
	int partition(int initial_index, int last_index);
	int bfprt_partition(int initial_index, int last_index, int i_index);
	int hoare_selection(int initial_index, int last_index, int i_index);
};

#endif
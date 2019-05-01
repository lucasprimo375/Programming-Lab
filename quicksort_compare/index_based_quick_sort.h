#ifndef INDEX_BASED_QUICK_SORT_H
#define INDEX_BASED_QUICK_SORT_H

#include "generic_quick_sort.h"

class IndexBasedQuickSort : public GenericQuickSort {
public:
	IndexBasedQuickSort(int* vector, int size, bool is_bad_instance);
	~IndexBasedQuickSort();
	void sort();
protected:
	void quick_sort(int initial_index, int last_index);
	int partition(int initial_index, int last_index);

private:
};

#endif
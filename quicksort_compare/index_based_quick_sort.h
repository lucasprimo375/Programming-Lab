#ifndef INDEX_BASED_QUICK_SORT_H
#define INDEX_BASED_QUICK_SORT_H

#include "generic_quick_sort.h"

class IndexBasedQuickSort : public GenericQuickSort {
public:
	IndexBasedQuickSort(int* vector, int size);
	~IndexBasedQuickSort();
	void sort();
protected:

private:
};

#endif
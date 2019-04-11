#ifndef RANDOM_PIVOT_QUICK_SORT_H
#define RANDOM_PIVOT_QUICK_SORT_H

#include "generic_quick_sort.h"

class RandomPivotQuickSort : public GenericQuickSort {
public:
	RandomPivotQuickSort(int* vector, int size);
	~RandomPivotQuickSort();
	void sort();

protected:
	int choose_pivot(int initial_index, int last_index);

private:
	void quick_sort(int initial_index, int last_index);
	int partition(int initial_index, int last_index);
};

#endif
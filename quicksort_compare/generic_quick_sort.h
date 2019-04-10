#ifndef GENERIC_QUICK_SORT_H
#define GENERIC_QUICK_SORT_H

class GenericQuickSort {
public:
	GenericQuickSort(int* vector, int size);
	~GenericQuickSort();
	virtual void sort() = 0;
	bool is_vector_sorted(int* vector, int size);
protected:
	virtual int choose_pivot(int initial_index, int last_index);

	int* vector_;
	int size_;
};

#endif
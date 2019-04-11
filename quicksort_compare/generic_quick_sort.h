#ifndef GENERIC_QUICK_SORT_H
#define GENERIC_QUICK_SORT_H

class GenericQuickSort {
public:
	GenericQuickSort(int* vector, int size);
	~GenericQuickSort();
	virtual void sort() = 0;
	bool is_vector_sorted();
	int* get_vector();

protected:
	virtual int choose_pivot(int initial_index, int last_index);
	void swap(int* v1, int* v2);
	int get_time_seconds();

	int start_time;
	int finish_time;

	int* vector_;
	int size_;
};

#endif
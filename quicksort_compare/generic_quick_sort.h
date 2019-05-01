#ifndef GENERIC_QUICK_SORT_H
#define GENERIC_QUICK_SORT_H

class GenericQuickSort {
public:
	GenericQuickSort(int* vector, int size, bool is_bad_instance);
	~GenericQuickSort();
	virtual void sort() = 0;
	bool is_vector_sorted();
	int* get_vector();

protected:
	virtual int choose_pivot(int initial_index, int last_index);
	void swap(int* v1, int* v2);
	int get_time_seconds();

	void generate_bad_instance();

	unsigned long int start_time_;
	unsigned long int finish_time_;

	int* vector_;
	int size_;
};

#endif
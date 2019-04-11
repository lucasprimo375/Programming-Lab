#include "index_based_quick_sort.h"

IndexBasedQuickSort::IndexBasedQuickSort(int* vector, int size) : GenericQuickSort(vector, size){}

IndexBasedQuickSort::~IndexBasedQuickSort(){}

void IndexBasedQuickSort::sort() {
	quick_sort(0, size_ - 1);
}

void IndexBasedQuickSort::quick_sort(int initial_index, int last_index){
	if(initial_index < last_index){
		int pivot_index = partition(initial_index, last_index);
		quick_sort(initial_index, pivot_index - 1);
		quick_sort(pivot_index + 1, last_index);
	}
}

int IndexBasedQuickSort::partition(int initial_index, int last_index){
	float pivot = vector_[choose_pivot(initial_index, last_index)];

	int j = initial_index;
	for(int i=initial_index; i<last_index; i++){
		if(vector_[i] < pivot){
			swap(&vector_[i], &vector_[j]);
			j++;
		}
	}

	swap(&vector_[j], &vector_[last_index]);

	return j;
}
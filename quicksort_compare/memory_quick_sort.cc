#include <iostream>

#include "memory_quick_sort.h"

MemoryQuickSort::MemoryQuickSort(int* vector, int size) : GenericQuickSort(vector, size) {}

MemoryQuickSort::~MemoryQuickSort() {}

void MemoryQuickSort::sort() {
	start_time_ = get_time_seconds();

	quick_sort(0, size_ - 1);

	finish_time_ = get_time_seconds();

	std::cout << "The run time of Memory Quick Sort is " << (finish_time_ - start_time_)/1000.0 << " seconds" << std::endl;
}

void MemoryQuickSort::quick_sort(int initial_index, int last_index) {
	while(initial_index < last_index){
        int pivot_index = partition(initial_index, last_index);
        int initial_to_pivot_size = pivot_index - initial_index + 1;
        int pivot_to_last_size = last_index - pivot_index + 1;

        if(initial_to_pivot_size > pivot_to_last_size){
            quick_sort(pivot_index + 1, last_index);
            last_index = pivot_index - 1;
        } else {
            quick_sort(initial_index, pivot_index - 1);
            initial_index = pivot_index + 1;
        }
    }
}

int MemoryQuickSort::partition(int initial_index, int last_index) {
	int pivot = vector_[choose_pivot(initial_index, last_index)];

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

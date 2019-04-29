#include <iostream>
#include <cmath>

#include "bfprt_quick_sort.h"

BfprtQuickSort::BfprtQuickSort(int* vector, int size) : GenericQuickSort(vector, size){}

BfprtQuickSort::~BfprtQuickSort(){}

void BfprtQuickSort::sort(){
	start_time_ = get_time_seconds();

	quick_sort(0, size_ - 1);

	finish_time_ = get_time_seconds();

	std::cout << "The run time of BFPRT Quick Sort is " << (finish_time_ - start_time_)/1000.0 << " seconds" << std::endl;
}

void BfprtQuickSort::quick_sort(int initial_index, int last_index) {
	int size = last_index - initial_index + 1;
	if(initial_index < last_index){
		int median_index = bfprt_partition(initial_index, last_index, initial_index + std::floor(size/2));
		quick_sort(initial_index, median_index - 1);
		quick_sort(median_index + 1, last_index);
	}
}

int BfprtQuickSort::partition(int initial_index, int last_index) {
	return 0;
}

int BfprtQuickSort::bfprt_partition(int initial_index, int last_index, int i_index) {
	int size = last_index - initial_index + 1;

	if(size <= 5){
		return hoare_selection(initial_index, last_index, std::floor(size/2) + initial_index);
	} else {
		int median_position = initial_index;
		for(int i = initial_index; i <= last_index; i = i + 5){
			int j = std::min(i + 4, last_index);
			int size = j - i + 1;
			int median_index = hoare_selection(i, j, std::floor(size/2) + i);
			swap(&vector_[median_index], &vector_[median_position]);
			median_position++;
		}

		int new_last_index = median_position - 1;

		int median_of_medians_index = bfprt_partition(initial_index, new_last_index, i_index);

		swap(&vector_[initial_index], &vector_[median_of_medians_index]);

		int pivot = vector_[initial_index];

		int j = initial_index;
	    int equal_index = initial_index;
	    for(int i=initial_index+1; i<=last_index; i++){
	        if(vector_[i] < pivot){
	            int y = vector_[i];
	            vector_[i] = vector_[equal_index+1];
	            vector_[equal_index+1] = vector_[j];
	            vector_[j] = y;
	            j++;
	            equal_index++;
	        } else if(vector_[i] == pivot){
	            swap(&vector_[i], &vector_[equal_index+1]);
	            equal_index++;
	        }
	    }

	    if((i_index >= j) && (i_index <= equal_index)) {
	    	return i_index;	
	    }

	    if(i_index < j) {
	    	return bfprt_partition(initial_index, j-1, i_index);
	    }

	    return bfprt_partition(equal_index + 1, last_index, i_index);
	}
}

int BfprtQuickSort::hoare_selection(int initial_index, int last_index, int i_index) {
	if(initial_index == last_index) return last_index;

	float pivot = vector_[last_index];

	int j = initial_index;
	for(int i=initial_index; i<last_index; i++){
		if(vector_[i] <= pivot){
			swap(&vector_[i], &vector_[j]);
			j++;
		}
	}

	swap(&vector_[j], &vector_[last_index]);

	if(j == i_index) return j;

	if(i_index > j) return hoare_selection(j+1, last_index, i_index);

	// i_index < j
	return hoare_selection(initial_index, j-1, i_index);
}	
#include <ctime>
#include <iostream>
#include <chrono>

#include "generic_quick_sort.h"

GenericQuickSort::GenericQuickSort(int* vector, int size, bool is_bad_instance) {
	size_ = size;

	if(!is_bad_instance){
		vector_ = vector;	
	} else {
		generate_bad_instance();
	}
}

GenericQuickSort::~GenericQuickSort(){
	delete [] vector_;
}

bool GenericQuickSort::is_vector_sorted() {
	for(int i=1; i<size_; i++){
		for(int j=0; j<i; j++){
			if(vector_[i] < vector_[j]){
				return false;
			}
		}
	}

	return true;
}

int GenericQuickSort::choose_pivot(int initial_index, int last_index) {
	return last_index;
}

void GenericQuickSort::swap(int* v1, int* v2){
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

int* GenericQuickSort::get_vector(){
	return vector_;
}

int GenericQuickSort::get_time_seconds(){
	std::chrono::milliseconds ms = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());
	
	return ms.count();
}

void GenericQuickSort::generate_bad_instance() {
	int* pos = new int[size_];

	for(int i = 0; i < size_; i++) {
		pos[i] = i;
	}

	for(int i = size_-1; i != -1; i--) {
      	int pivot_index = choose_pivot(0, i);
      	
      	vector_[ pos[pivot_index] ] = i;

      	swap( &pos[pivot_index], &pos[0] );

      	swap( &pos[0], &pos[i] );
 	}

 	delete [] pos;
}
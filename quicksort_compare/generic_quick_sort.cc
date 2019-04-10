#include "generic_quick_sort.h"

GenericQuickSort::GenericQuickSort(int* vector, int size) {
	vector_ = vector;
	size_ = size;
}

GenericQuickSort::~GenericQuickSort(){
	delete [] vector_;
}

bool GenericQuickSort::is_vector_sorted(int* vector, int size) {
	for(int i=1; i<size; i++){
		if(vector_[i] < vector_[i-1]){
			return false;
		}
	}

	return true;
}

int choose_pivot(int initial_index, int last_index) {
	return last_index;
}
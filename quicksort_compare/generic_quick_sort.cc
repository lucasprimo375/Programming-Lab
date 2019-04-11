#include "generic_quick_sort.h"

GenericQuickSort::GenericQuickSort(int* vector, int size) {
	vector_ = vector;
	size_ = size;
}

GenericQuickSort::~GenericQuickSort(){
	delete [] vector_;
}

bool GenericQuickSort::is_vector_sorted() {
	for(int i=1; i<size_; i++){
		if(vector_[i] < vector_[i-1]){
			return false;
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
	return 0;
}
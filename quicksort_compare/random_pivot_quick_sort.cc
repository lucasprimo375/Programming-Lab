#include <random>
#include <iostream>

#include "random_pivot_quick_sort.h"

RandomPivotQuickSort::RandomPivotQuickSort(int* vector, int size) : GenericQuickSort(vector, size){}

RandomPivotQuickSort::~RandomPivotQuickSort(){}

int RandomPivotQuickSort::choose_pivot(int initial_index, int last_index){
	std::random_device rd;
	
	std::mt19937 ger(rd());

	std::uniform_int_distribution<int> dis(initial_index, last_index);

	return dis(ger);
}

void RandomPivotQuickSort::sort(){
	quick_sort(0, size_ - 1);
}

void RandomPivotQuickSort::quick_sort(int initial_index, int last_index){
	if(initial_index < last_index){
		int pivot_index = partition(initial_index, last_index);
		quick_sort(initial_index, pivot_index - 1);
		quick_sort(pivot_index + 1, last_index);
	}
}

int RandomPivotQuickSort::partition(int initial_index, int last_index){
	int random_index = choose_pivot(initial_index, last_index);

	std::cout << "RANDOM PIVOT IS vector[" << random_index << "] = " << vector_[random_index] << std::endl;

	swap(&vector_[random_index], &vector_[last_index]);

	float pivot = vector_[last_index];

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
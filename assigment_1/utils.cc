#include <random>
#include <iostream>

#include "utils.h"

int* generate_random_instance(int size, float min_value, float max_value){
	std::random_device rd;
	
	std::mt19937 ger(rd());

	std::uniform_int_distribution<int> dis(min_value, max_value);

	int* vector = new int[size];

	for(int i=0; i<size; i++)
		vector[i] = dis(ger);

	return vector;
}

bool is_vector_sorted(int* vector, int size){
	for(int i=1; i<size; i++){
		if(vector[i] < vector[i-1]){
			return false;
		}
	}

	return true;
}

void print_vector(int* vector, int size){
	for(int i=0; i<size; i++){
		if(i != size-1){
			std::cout << vector[i] << ", ";
		} else {
			std::cout << vector[i] << std::endl;
		}
	}
}

int* copy_vector(int* vector, int size){
	int* copy = new int[size];

	for(int i=0; i<size; i++){
		copy[i] = vector[i];
	}

	return copy;
}
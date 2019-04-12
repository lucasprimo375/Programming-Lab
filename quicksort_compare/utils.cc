#include <random>
#include <iostream>
#include <time.h>

#include "utils.h"

int* generate_random_instance(int size, int min_value, int max_value){
	std::random_device rd;
	
	std::mt19937 ger(rd());

	std::uniform_int_distribution<int> dis(min_value, max_value);

	int* vector = new int[size];

	for(int i=0; i<size; i++)
		vector[i] = dis(ger);

	return vector;
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

int generate_random_number(int min_value, int max_value){
	srand(time(nullptr));

	return min_value + (rand() % (max_value - min_value + 1));
}
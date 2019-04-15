#include <iostream>
#include <cmath>
#include <algorithm>
#include <time.h>

float* input_vector(int* size);
void quick_sort(float* vector, int initial_index, int last_index);
void bfprt_partition(float* vector, int vector_size, int initial_index, int last_index, int i_index);
int hoare_selection(float* vector, int initial_index, int last_index, int i_index);
void swap(float* v1, float* v2);
void print_vector(float* vector, int size);

int main(){
	int size;
	float* vector = input_vector(&size);

	std::cout << "printing vector before ordering" << std::endl;

	print_vector(vector, size);

	quick_sort(vector, 0, size-1/*, size, std::floor(size/2)*/);

	std::cout << "printing vector after ordering" << std::endl;

	print_vector(vector, size);

	return 0;
}

void bfprt_partition(float* vector, int vector_size, int initial_index, int last_index, int i_index){
	std::cout << vector_size << std::endl;
	int size = last_index - initial_index + 1;

	int median_of_medians_index;

	if(size <= 5){
		median_of_medians_index = hoare_selection(vector, initial_index, last_index, std::floor(size/2) + initial_index);
	} else {
		int median_position = initial_index;
		for(int i = initial_index; i <= last_index; i = i + 5){
			int j = std::min(i + 4, last_index);
			int size = j - i + 1;
			int median_index = hoare_selection(vector, i, j, std::floor(size/2) + i);
			swap(&vector[median_index], &vector[median_position]);
			median_position++;
		}

		int new_last_index = median_position - 1;

		bfprt_partition(vector, vector_size, initial_index, new_last_index, i_index);

		return;
	}

	swap(&vector[initial_index], &vector[median_of_medians_index]);

	int pivot = vector[initial_index];

	int j = initial_index;
    int equal_index = initial_index;
    for(int i=initial_index+1; i<=initial_index+vector_size-1; i++){
        if(vector[i] < pivot){
            int y = vector[i];
            vector[i] = vector[equal_index+1];
            vector[equal_index+1] = vector[j];
            vector[j] = y;
            j++;
            equal_index++;
        } else if(vector[i] == pivot){
            swap(&vector[i], &vector[equal_index+1]);
            equal_index++;
        }
    }

    if((i_index >= j) && (i_index <= equal_index)) {
    	std::cout << "the median is " << vector[i_index] << std::endl;
    	return;	
    }

    if(i_index < j) {
    	int new_vector_size = j - 1 - initial_index + 1;
    	bfprt_partition(vector, new_vector_size, initial_index, j-1, i_index);
    	return;
    }

    int new_vector_size = last_index - (equal_index + 1) + 1;
    bfprt_partition(vector, new_vector_size, equal_index + 1, last_index, i_index);
    return;
}

float* input_vector(int* size){
	std::cout << "input vector size: ";
	std::cin >> *size;

	float* aux = new float[*size];

	srand(time(nullptr));

	for(int i=0; i<*size; i++){
		/*std::cout << "input element " << i+1 << ": ";
		std::cin >> aux[i];*/
		aux[i] = rand()%(1000+1);
	}

	std::cout << std::endl;

	return aux;
}

void quick_sort(float* vector, int initial_index, int last_index){
	int size = last_index - initial_index + 1;
	if(initial_index < last_index){
		bfprt_partition(vector, size, initial_index, last_index, initial_index + std::floor(size/2));
		/*quick_sort(vector, initial_index, initial_index + std::floor(size/2) - 1);
		quick_sort(vector, initial_index + std::floor(size/2) + 1, last_index);*/
	}
}

int hoare_selection(float* vector, int initial_index, int last_index, int i_index){
	if(initial_index == last_index) return last_index;

	float pivot = vector[last_index];

	int j = initial_index;
	for(int i=initial_index; i<last_index; i++){
		if(vector[i] <= pivot){
			swap(&vector[i], &vector[j]);
			j++;
		}
	}

	swap(&vector[j], &vector[last_index]);

	if(j == i_index) return j;

	if(i_index > j) return hoare_selection(vector, j+1, last_index, i_index);

	// i_index < j
	return hoare_selection(vector, initial_index, j-1, i_index);
}

void print_vector(float* vector, int size){
	for(int i=0; i<size; i++){
		if(i != size - 1){
			std::cout << vector[i] << ",";
		} else {
			std::cout << vector[i] << "" << std::endl;
		}
	}

	std::cout << std::endl;
}

void swap(float* v1, float* v2){
	float temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}
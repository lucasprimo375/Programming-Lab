#include <iostream>
#include <cmath>

float* input_vector(int* size);
void quick_sort(float* vector, int initial_index, int last_index);
int hoare_partition(float* vector, int initial_index, int last_index, int i_index);
void swap(float* v1, float* v2);
void print_vector(float* vector, int size);

int main(){
	int size;
	float* vector = input_vector(&size);

	std::cout << "printing vector before ordering" << std::endl;

	print_vector(vector, size);

	quick_sort(vector, 0, size-1);

	std::cout << "printing vector after ordering" << std::endl;

	print_vector(vector, size);

	return 0;
}

int hoare_partition(float* vector, int initial_index, int last_index, int i_index){
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

	if(i_index > j) return hoare_partition(vector, j+1, last_index, i_index);

	// i_index < j
	return hoare_partition(vector, initial_index, j-1, i_index);
}

void quick_sort(float* vector, int initial_index, int last_index){
	int size = last_index - initial_index + 1;
	if(initial_index < last_index){
		int pivot_index = hoare_partition(vector, initial_index, last_index, size/2);
		quick_sort(vector, initial_index, pivot_index - 1);
		quick_sort(vector, pivot_index + 1, last_index);
	}
}

float* input_vector(int* size){
	std::cout << "input vector size: ";
	std::cin >> *size;

	float* aux = new float[*size];

	for(int i=0; i<*size; i++){
		std::cout << "input element " << i+1 << ": ";
		std::cin >> aux[i];
	}

	std::cout << std::endl;

	return aux;
}

void print_vector(float* vector, int size){
	for(int i=0; i<size; i++){
		if(i != size - 1){
			std::cout << vector[i] << ", ";
		} else {
			std::cout << vector[i] << "." << std::endl;
		}
	}

	std::cout << std::endl;
}

void swap(float* v1, float* v2){
	float temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}
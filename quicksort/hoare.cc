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

	int i = std::floor(size/2);
	hoare_partition(vector, 0, size-1, i);

	std::cout << "printing vector after ordering" << std::endl;

	print_vector(vector, size);

	return 0;
}

int hoare_partition(float* vector, int initial_index, int last_index, int i_index){
	if(initial_index > last_index) {
		std::cout << "i_index: " << i_index << std::endl;
		std::cout << "initial_index: " << initial_index << std::endl;
		std::cout << "last_index: " << last_index << std::endl;
		return 0;
	}

	float pivot = vector[last_index];

	/*std::cout << "i_index: " << i_index << std::endl;
	std::cout << "initial_index: " << initial_index << std::endl;
	std::cout << "last_index: " << last_index << std::endl;*/

	int j = initial_index;
	for(int i=initial_index; i<last_index; i++){
		if(vector[i] < pivot){
			swap(&vector[i], &vector[j]);
			j++;
		}
	}

	swap(&vector[j], &vector[last_index]);

	if(j == i_index) {
		std::cout << "index is " << j << ", with value " << vector[j] << std::endl;
		return j;
	}

	if(j < i_index) {
		std::cout << "IF 1" << std::endl;
		std::cout << "entering " << j+1 << " to " << last_index 
					<< " looking " << i_index-j-1 << std::endl;
		return hoare_partition(vector, j+1, last_index, i_index-j-1);
	}

	if(j > i_index) {
		std::cout << "IF 2" << std::endl;
		std::cout << "entering " << initial_index << " to " << j-1 
					<< " looking " << i_index << std::endl;
		return hoare_partition(vector, initial_index, j-1, i_index);
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

void quick_sort(float* vector, int initial_index, int last_index){
	if(initial_index < last_index){
		/*int pivot_index = hoare_partition(vector, initial_index, last_index);
		quick_sort(vector, initial_index, pivot_index - 1);
		quick_sort(vector, pivot_index + 1, last_index);*/
	}
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
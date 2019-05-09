#include <iostream>
#include <cmath>

float* input_vector(int* size);
void quick_sort(float* vector, int initial_index, int last_index);
int bfprt_partition(float* vector, int initial_index, int last_index, int i_index);
int hoare_selection(float* vector, int initial_index, int last_index, int i_index);
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

int bfprt_partition(float* vector, int initial_index, int last_index, int i_index){
	int size = last_index - initial_index + 1;

	if(size <= 5){
		return hoare_selection(vector, initial_index, last_index, std::floor(size/2) + initial_index);
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

		int median_of_medians_index = bfprt_partition(vector, initial_index, new_last_index, initial_index + std::floor((new_last_index - initial_index + 1)/2));

		swap(&vector[initial_index], &vector[median_of_medians_index]);

		int pivot = vector[initial_index];

		int j = initial_index;
	    int equal_index = initial_index;
	    for(int i=initial_index+1; i<=last_index; i++){
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
	    	return i_index;	
	    }

	    if(i_index < j) {
	    	return bfprt_partition(vector, initial_index, j-1, i_index);
	    }

	    return bfprt_partition(vector, equal_index + 1, last_index, i_index);
	}
}

float* input_vector(int* size){
	std::cout << "input vector size: ";
	std::cin >> *size;

	float* aux = new float[*size];

	srand(time(nullptr));

	for(int i=0; i<*size; i++){
		std::cout << "input element " << i+1 << ": ";
		std::cin >> aux[i];
	}

	std::cout << std::endl;

	return aux;
}

void quick_sort(float* vector, int initial_index, int last_index){
	int size = last_index - initial_index + 1;
	if(initial_index < last_index){
		int median_index = bfprt_partition(vector, initial_index, last_index, initial_index + std::floor(size/2));
		quick_sort(vector, initial_index, median_index - 1);
		quick_sort(vector, median_index + 1, last_index);
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
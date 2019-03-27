#include <iostream>
#include <cmath>
#include <algorithm>

float* input_vector(int* size);
void quick_sort(float* vector, int initial_index, int last_index);
int bfprt_partition(float* vector, int initial_index, int last_index, int i_index);
void bfprt_selection(float* vector, int initial_index, int last_index);
int hoare_selection(float* vector, int initial_index, int last_index, int i_index);
void swap(float* v1, float* v2);
void print_vector(float* vector, int size);

int main(){
	int size;
	float* vector = input_vector(&size);

	std::cout << "printing vector before ordering" << std::endl;

	print_vector(vector, size);

	bfprt_selection(vector, 0, size-1);

	std::cout << "printing vector after ordering" << std::endl;

	print_vector(vector, size);

	return 0;
}

void bfprt_selection(float* vector, int initial_index, int last_index){
	int size = last_index - initial_index + 1;

	if(size != 1){
		int i_index = std::floor(size/2) + initial_index;

		int approximate_median_index = bfprt_partition(vector, initial_index, last_index, i_index);

		std::cout << "MEDIAN IS " << vector[approximate_median_index] << std::endl;

		float pivot = vector[approximate_median_index];

	    int r = initial_index;
	    int s = initial_index;
	    for(int i=initial_index+1; i<=last_index; i++){
	        if(vector[i] < pivot){
	            int y = vector[i];
	            vector[i] = vector[s+1];
	            vector[s+1] = vector[r];
	            vector[r] = y;
	            r++;
	            s++;
	        } else if(vector[i] == pivot){
	            swap(&vector[i], &vector[s+1]);
	            s++;
	        }
	    }

	    //r++;

	    std::cout << "i is " << i_index << ", with value "<< vector[i_index] << std::endl;
	    std::cout << "r is " << r << ", with value "<< vector[r] << std::endl;
	    std::cout << "s is " << s << ", with value "<< vector[s] << std::endl;

	    if((i_index >= r) && (i_index <= s)){
	    	std::cout << "FOUND" << std::endl;
	    	//swap(&vector[i_index], &vector[i_index-1]);
	    	//return;
	    }

	    if(i_index < r){
	    	std::cout << "(IF 1): SEARCH FOR " << initial_index << " to " << r-1 << std::endl;
	    	//bfprt_selection(vector, initial_index, r-1);
	    	return;
	    }

	    if(i_index > s){
	    	std::cout << "(IF 2): SEARCH FOR " << s+1 << " to " << last_index << std::endl;
	    	//bfprt_selection(vector, s+1, last_index);
	    	return;
	    }
	}
}

float* input_vector(int* size){
	/*std::cout << "input vector size: ";
	std::cin >> *size;*/
	*size = 10;

	float* aux = new float[*size];

	for(int i=0; i<*size; i++){
		/*std::cout << "input element " << i+1 << ": ";
		std::cin >> aux[i];*/
		aux[i] = (*size) - i;
	}

	//std::cout << std::endl;

	return aux;
}

int bfprt_partition(float* vector, int initial_index, int last_index, int i_index){
	int size = last_index - initial_index + 1;

	if(size <= 5){
		return hoare_selection(vector, initial_index, last_index, std::floor(size/2) + initial_index);
	}


	int median_position = initial_index;
	for(int i = initial_index; i <= last_index; i = i + 5){
		int median_index = bfprt_partition(vector, i, std::min(i + 4, last_index), i_index);
		swap(&vector[median_index], &vector[median_position]);
		median_position++;
	}

	int last_median_index = median_position - 1;

	return bfprt_partition(vector, initial_index, last_median_index, std::floor(size/2) + initial_index);
}

void quick_sort(float* vector, int initial_index, int last_index){
	int size = last_index - initial_index + 1;
	if(initial_index < last_index){
		int pivot_index = bfprt_partition(vector, initial_index, last_index, std::floor(size/2));
		std::cout << "the pivot index is " << pivot_index << std::endl;
		std::cout << "the pivot is " << vector[pivot_index] << std::endl;
		/*quick_sort(vector, initial_index, pivot_index - 1);
		quick_sort(vector, pivot_index + 1, last_index);*/
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
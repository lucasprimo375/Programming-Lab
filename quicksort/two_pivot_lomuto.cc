#include <iostream>

float* input_vector(int* size);
void quick_sort(float* vector, int initial_index, int last_index);
int* lomuto_partition(float* vector, int initial_index, int last_index);
void swap(float* v1, float* v2);
void print_vector(float* vector, int size);
void print_sub_vector(float* vector, int initial_index, int last_index);
void move(float* vector, int original_position, int new_position);

int main(){
    int size;
    float* vector = input_vector(&size);

    std::cout << "printing vector before ordering" << std::endl;

    print_vector(vector, size);

    quick_sort(vector, 0, size-1);

    std::cout << "printing vector after ordering" << std::endl;

    print_vector(vector, size);

    delete vector;

    return 0;
}

int* lomuto_partition(float* vector, int initial_index, int last_index){
    float pivot = vector[initial_index];

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

    int* pivot_index = new int[2];
    pivot_index[0] = j;
    pivot_index[1] = equal_index;

    return pivot_index;
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
        int* pivot_index = lomuto_partition(vector, initial_index, last_index);
        quick_sort(vector, initial_index, pivot_index[0] - 1);
        quick_sort(vector, pivot_index[1] + 1, last_index);
        delete pivot_index;
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
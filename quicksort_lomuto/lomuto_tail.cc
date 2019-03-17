#include <iostream>

float* input_vector(int* size);
void tail_quick_sort(float* vector, int initial_index, int last_index);
int lomuto_partition(float* vector, int initial_index, int last_index);
void swap(float* v1, float* v2);
void print_vector(float* vector, int size);

int main(){
    int size;
    float* vector = input_vector(&size);

    std::cout << "printing vector before ordering" << std::endl;

    print_vector(vector, size);

    tail_quick_sort(vector, 0, size-1);

    std::cout << "printing vector after ordering" << std::endl;

    print_vector(vector, size);

    return 0;
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

void tail_quick_sort(float* vector, int initial_index, int last_index){
    while(initial_index < last_index){
        int pivot_index = lomuto_partition(vector, initial_index, last_index);
        int initial_to_pivot_size = pivot_index - initial_index + 1;
        int pivot_to_last_size = last_index - pivot_index + 1;

        if(initial_to_pivot_size > pivot_to_last_size){
            tail_quick_sort(vector, pivot_index + 1, last_index);
            last_index = pivot_index - 1;
        } else {
            tail_quick_sort(vector, initial_index, pivot_index - 1);
            initial_index = pivot_index + 1;
        }
    }
}

int lomuto_partition(float* vector, int initial_index, int last_index){
    float pivot = vector[last_index];

    int j = initial_index;
    for(int i=initial_index; i<last_index; i++){
        if(vector[i] < pivot){
            swap(&vector[i], &vector[j]);
            j++;
        }
    }

    swap(&vector[j], &vector[last_index]);

    return j;
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
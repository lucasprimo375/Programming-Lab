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

    return 0;
}

int* lomuto_partition(float* vector, int initial_index, int last_index){
    float pivot = vector[last_index];

    int j = initial_index;
    int equals_counter = 0;
    for(int i=initial_index; i<last_index; i++){
        if(vector[i] <= pivot){
            if(vector[i] == pivot){
                equals_counter++;
            }

            swap(&vector[i], &vector[j]);
            j++;
        }
    }

    swap(&vector[j], &vector[last_index]);

    int equals_counter_aux = equals_counter;
    int j_aux = j-1;
    int i = j-2;
    while(i >= initial_index){
        if(vector[i] == pivot){
            move(vector, i, j_aux);
            j_aux--;
        }
        i--;
    }

    int* pivot_index = new int[2];
    pivot_index[0] = j-equals_counter;
    pivot_index[1] = j;

    return pivot_index;
}

void move(float* vector, int original_position, int new_position){
    for(int i=original_position; i<new_position; i++){
        swap(&vector[i], &vector[i+1]);
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
        int* pivot_index = lomuto_partition(vector, initial_index, last_index);
        quick_sort(vector, initial_index, pivot_index[0] - 1);
        quick_sort(vector, pivot_index[1] + 1, last_index);
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

void print_sub_vector(float* vector, int initial_index, int last_index){
    for(int i=initial_index; i<=last_index; i++){
        if(i != last_index){
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
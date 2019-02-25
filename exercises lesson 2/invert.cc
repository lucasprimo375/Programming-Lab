#include <iostream>

void invert(int* v, int n);
void copy_vector(int* original, int* copy, int n);
void show_vector(int* v, int n);


int main(){
    int* v = new int[5];
    int n = 5;
    *v = 1;
    *(v+1) = 12;
    *(v+2) = 23;
    *(v+3) = 74;
    *(v+4) = 50;

    std::cout << "original vector:" << std::endl;
    show_vector(v, n);

    invert(v, n);

    std::cout << std::endl << "inverted vector" << std::endl;
    show_vector(v, n);

    return 0;
}

void invert(int* v, int n){
    int* temp_v = new int[n];
    copy_vector(v, temp_v, n);

    int j = n-1;
    for(int i=0; i<n; i++){
        *(v+i) = *(temp_v+j);
        j--;
    }

    delete [] temp_v;
}

void copy_vector(int* original, int* copy, int n){
    for(int i=0; i<n; i++){
        *(copy+i) = *(original+i);
    }
}

void show_vector(int* v, int n){
    for(int i = 0; i<n; i++){
        if(i != n-1){
            std::cout << *(v+i) << ",";
        } else {
            std::cout << *(v+i) << std::endl;
        }
    }
}
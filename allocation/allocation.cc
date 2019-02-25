#include <iostream>
#include <new>

int get_int_from_user();
int* handle_new_input(int* integers, int former_size, int new_size);
void print_vector(int* v, int size);
void main_loop();

int main(){
	main_loop();

	return 0;
}

int* handle_new_input(int* integers, int former_size, int new_size){
	int* new_vector = new(std::nothrow) int[new_size];

	for(int i=0; i<former_size; i++){
		*(new_vector+i) = *(integers+i);
	}

	delete [] integers;

	return new_vector;
}

void main_loop(){
	bool done = false;
	int integers_read = 0;
	int* integers = new(std::nothrow) int;
	int size = 1;

	while(!done){
		int input = get_int_from_user();
		if(input < 0){
			done = true;
		} else {
			if(integers_read == size){
				integers = handle_new_input(integers, size, 2*size);
				size = 2*size;
			}

			*(integers+integers_read) = input;
			integers_read++; 
		}
	}

	print_vector(integers, integers_read);
}

void print_vector(int* v, int size){
	if(size > 0){
		std::cout << std::endl << "printing the input:" << std::endl;

		for(int i=0; i<size; i++){
			std::cout << *(v+i) << std::endl;
		}
	} else {
		std::cout << "nothing to print" << std::endl;
	}
}

int get_int_from_user(){
	std::cout << "input integer number (negative to end):";

	int input;

	std::cin >> input;

	return input;
}
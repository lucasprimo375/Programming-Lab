#include <iostream>

#include "user_input.h"
#include "utils.h"

int main() {

	do {
		int size = get_vector_size();
		int* limits = get_min_max_values();
		int* vector = generate_random_instance(size, limits[0], limits[1]);
		print_vector(vector, size);

	} while(should_continue());
}
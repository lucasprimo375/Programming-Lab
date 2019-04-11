#include <iostream>

#include "user_input.h"
#include "utils.h"
#include "generic_quick_sort.h"
#include "index_based_quick_sort.h"

int main() {

	GenericQuickSort* generic_quick_sort;

	do {
		int size = get_vector_size();
		int* limits = get_min_max_values();
		int* vector = generate_random_instance(size, limits[0], limits[1]);

		std::cout << "Printing unsorted vector" << std::endl;
		print_vector(vector, size);

		int* generic_quick_sort_vector = copy_vector(vector, size);
		generic_quick_sort = new IndexBasedQuickSort(generic_quick_sort_vector, size);
		generic_quick_sort->sort();
		std::cout << "Index Based Quick sort has " << (generic_quick_sort->is_vector_sorted() ? "" : "not ") << "sorted the vector" << std::endl;
		std::cout << "Printing sorted vector" << std::endl;
		print_vector(generic_quick_sort->get_vector(), size);
		delete generic_quick_sort;

	} while(should_continue());
}
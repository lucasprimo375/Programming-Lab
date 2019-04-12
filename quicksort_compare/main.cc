#include <iostream>

#include "user_input.h"
#include "utils.h"
#include "generic_quick_sort.h"
#include "index_based_quick_sort.h"
#include "random_pivot_quick_sort.h"
#include "pointer_based_quick_sort.h"

int main() {

	GenericQuickSort* generic_quick_sort;

	do {
		int size = get_vector_size();
		int* limits = get_min_max_values();
		int* vector = generate_random_instance(size, limits[0], limits[1]);

		//std::cout << "Printing unsorted vector" << std::endl;
		//print_vector(vector, size);

		int* index_based_quick_sort_vector = copy_vector(vector, size);

		std::cout << std::endl;

		generic_quick_sort = new IndexBasedQuickSort(index_based_quick_sort_vector, size);
		generic_quick_sort->sort();
		std::cout << "Index Based Quick Sort has " << (generic_quick_sort->is_vector_sorted() ? "" : "not ") << "sorted the vector" << std::endl;
		//std::cout << "Printing sorted vector" << std::endl;
		//print_vector(generic_quick_sort->get_vector(), size);
		delete generic_quick_sort;

		std::cout << std::endl;

		int* random_pivot_quick_sort_vector = copy_vector(vector, size);
		generic_quick_sort = new RandomPivotQuickSort(random_pivot_quick_sort_vector, size);
		generic_quick_sort->sort();
		std::cout << "Random Pivot Quick Sort has " << (generic_quick_sort->is_vector_sorted() ? "" : "not ") << "sorted the vector" << std::endl;
		//std::cout << "Printing sorted vector" << std::endl;
		//print_vector(generic_quick_sort->get_vector(), size);
		delete generic_quick_sort;

		std::cout << std::endl;

		int* pointer_based_quick_sort_vector = copy_vector(vector, size);
		generic_quick_sort = new PointerBasedQuickSort(pointer_based_quick_sort_vector, size);
		generic_quick_sort->sort();
		std::cout << "Pointer Based Quick Sort has " << (generic_quick_sort->is_vector_sorted() ? "" : "not ") << "sorted the vector" << std::endl;
		//std::cout << "Printing sorted vector" << std::endl;
		//print_vector(generic_quick_sort->get_vector(), size);
		delete generic_quick_sort;

		std::cout << std::endl;

	} while(should_continue());
}
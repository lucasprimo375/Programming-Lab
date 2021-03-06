#include <iostream>

#include "user_input.h"
#include "utils.h"
#include "generic_quick_sort.h"
#include "index_based_quick_sort.h"
#include "random_pivot_quick_sort.h"
#include "pointer_based_quick_sort.h"
#include "memory_quick_sort.h"
#include "bfprt_quick_sort.h"

int main() {

	GenericQuickSort* generic_quick_sort;

	do {

		int size = get_vector_size();
	
		int* vector;

		bool generate_bad_instance = should_generate_bad_instance();
		if(!generate_bad_instance){
			int* limits = get_min_max_values();
			vector = generate_random_instance(size, limits[0], limits[1]);
		}

		/*std::cout << "Printing unsorted vector" << std::endl;
		print_vector(vector, size);*/

		int* index_based_quick_sort_vector;
		int* random_pivot_quick_sort_vector;
		int* pointer_based_quick_sort_vector;		
		int* memory_quick_sort_vector;		
		int* bfprt_quick_sort_vector;		
		if(!generate_bad_instance){
			index_based_quick_sort_vector = copy_vector(vector, size);
			random_pivot_quick_sort_vector = copy_vector(vector, size);
			pointer_based_quick_sort_vector = copy_vector(vector, size);
			memory_quick_sort_vector = copy_vector(vector, size);
			bfprt_quick_sort_vector = copy_vector(vector, size);
		} else {
			index_based_quick_sort_vector = new int[size];
			random_pivot_quick_sort_vector = new int[size];
			pointer_based_quick_sort_vector = new int[size];
			memory_quick_sort_vector = new int[size];
			bfprt_quick_sort_vector = new int[size];
		}

		std::cout << std::endl;

		generic_quick_sort = new IndexBasedQuickSort(index_based_quick_sort_vector, size, generate_bad_instance);
		generic_quick_sort->sort();
		std::cout << "Index Based Quick Sort has " << (generic_quick_sort->is_vector_sorted() ? "" : "not ") << "sorted the vector" << std::endl;
		delete generic_quick_sort;

		std::cout << std::endl;

		generic_quick_sort = new RandomPivotQuickSort(random_pivot_quick_sort_vector, size, generate_bad_instance);
		generic_quick_sort->sort();
		std::cout << "Random Pivot Quick Sort has " << (generic_quick_sort->is_vector_sorted() ? "" : "not ") << "sorted the vector" << std::endl;		delete generic_quick_sort;

		std::cout << std::endl;

		generic_quick_sort = new PointerBasedQuickSort(pointer_based_quick_sort_vector, size, generate_bad_instance);
		generic_quick_sort->sort();
		std::cout << "Pointer Based Quick Sort has " << (generic_quick_sort->is_vector_sorted() ? "" : "not ") << "sorted the vector" << std::endl;
		delete generic_quick_sort;

		std::cout << std::endl;

		generic_quick_sort = new MemoryQuickSort(memory_quick_sort_vector, size, generate_bad_instance);
		generic_quick_sort->sort();
		std::cout << "Memory Quick Sort has " << (generic_quick_sort->is_vector_sorted() ? "" : "not ") << "sorted the vector" << std::endl;
		delete generic_quick_sort;

		std::cout << std::endl;

		generic_quick_sort = new BfprtQuickSort(bfprt_quick_sort_vector, size, generate_bad_instance);
		generic_quick_sort->sort();
		std::cout << "BFPRT Quick Sort has " << (generic_quick_sort->is_vector_sorted() ? "" : "not ") << "sorted the vector" << std::endl;
		delete generic_quick_sort;

		std::cout << std::endl;

	} while(should_continue());
}

#include <iostream>

#include "instance_generator.h"
#include "instance.h"
#include "utils.h"
#include "user_input.h"
#include "subsequence_search.h"

int main(){
	do {
		Instance* instance = generate_instance();
		print_instance(instance);

		int text_size = get_text_size( instance->text );
		int pattern_size = get_text_size( instance->pattern );

		int maximum_matching_size = text_size/pattern_size;

		int* kmp_matching_indexes = new int[maximum_matching_size];

		std::cout << std::endl << "Running Knuth-Morris-Pratt Algorithm" << std::endl;

		knuth_morris_pratt(instance->text, instance->pattern, kmp_matching_indexes);

		print_matching_indexes(kmp_matching_indexes);


		int* bf_matching_indexes = new int[maximum_matching_size];

		std::cout << std::endl << "Running Brute Force Algorithm" << std::endl;

		brute_force(instance->text, instance->pattern, bf_matching_indexes);

		print_matching_indexes(bf_matching_indexes);

		std::cout << std::endl;

		if( is_equal( kmp_matching_indexes,  bf_matching_indexes) ) {
			std::cout << "The matching indexes are all equal" << std::endl;
		} else {
			std::cout << "The matching indexes are different" << std::endl;
		}
	} while( should_continue() );

	return 0;
}

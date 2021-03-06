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

		int maximum_matching_size = text_size;

		int* kmp_matching_indexes = new int[maximum_matching_size];

		std::cout << std::endl << std::endl << "RUNNING KNUTH-MORRIS-PRATT ALGORITHM" << std::endl;

		unsigned long int start_time = get_time_seconds();
		knuth_morris_pratt(instance->text, instance->pattern, kmp_matching_indexes);
		unsigned long int finish_time = get_time_seconds();

		std::cout << std::endl << "The running time of Knuth-Morris-Pratt is " << (finish_time - start_time)/1000.0 << " seconds" << std::endl;

		print_matching_indexes(kmp_matching_indexes);


		int* bf_matching_indexes = new int[maximum_matching_size];

		std::cout << std::endl << std::endl << "RUNNING BRUTE FORCE ALGORITHM" << std::endl;

		start_time = get_time_seconds();
		brute_force(instance->text, instance->pattern, bf_matching_indexes);
		finish_time = get_time_seconds();

		std::cout << std::endl << "The running time of Brute Forte is " << (finish_time - start_time)/1000.0 << " seconds" << std::endl;

		print_matching_indexes(bf_matching_indexes);

		std::cout << std::endl;

		is_equal( kmp_matching_indexes,  bf_matching_indexes);
	} while( should_continue() );

	return 0;
}

#include <sstream>

#include "instance_generator.h"
#include "instance.h"
#include "utils.h"
#include "user_input.h"
#include "subsequence_search.h"

int main(){
	do {
		Instance* instance = generate_instance();
		print_instance(instance);

		int* matching_indexes = new int[200];

		knuth_morris_pratt(instance->text, instance->pattern, matching_indexes);

		//print_matching_indexes(matching_indexes);
	} while( should_continue() );

	return 0;
}

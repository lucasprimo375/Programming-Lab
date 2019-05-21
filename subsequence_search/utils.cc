#include <iostream>
#include <time.h>

#include "utils.h"
#include "user_input.h"
#include "real_instances.h"

char* generate_as_vector(int size) {
	char* text = new char[size + 1];

	for(int i=0; i<size; i++) {
		text[i] = 'a';
	}

	text[size] = '\0';

	return text;
}

char* generate_as_vector_with_a_b(int size) {
	char* text = new char[size + 1];

	for(int i=0; i<size-1; i++) {
		text[i] = 'a';
	}

	text[size - 1] = 'b';

	text[size] = '\0';

	return text;	
}

Instance* generate_worst_case_1_instance(int text_size, int pattern_size) {
	char* text = generate_as_vector(text_size);

	char* pattern = generate_as_vector_with_a_b(pattern_size);

	Instance* instance = new Instance();

	instance->text = text;
	instance->pattern = pattern;

	return instance;
}

Instance* generate_worst_case_2_instance(int text_size, int pattern_size) {
	char* text = generate_as_vector(text_size);

	char* pattern = generate_as_vector(pattern_size);

	Instance* instance = new Instance();

	instance->text = text;
	instance->pattern = pattern;

	return instance;
}

int generate_random_number(int min_value, int max_value){
	srand(time(nullptr));

	return min_value + (rand() % (max_value - min_value + 1));
}

char* generate_random_text(int size, int limit) {
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'z', 'w'};

	char* text = new char[size+1];

	for(int i=0; i<size; i++) {
		int character_index = generate_random_number(0, limit);
		text[i] = alphabet[character_index];
	}

	text[size] = '\0';

	return text;
}

Instance* generate_random_instance(int text_size, int pattern_size, int limit) {
	char* text = generate_random_text(text_size, limit);
	char* pattern = generate_random_text(pattern_size, limit);

	Instance* instance = new Instance();

	instance->text = text;
	instance->pattern = pattern;

	return instance;
}

Instance* generate_real_text_instance(int real_pattern_index) {
	Instance* instance = new Instance();

	instance->text = real_text;
	instance->pattern = patterns[real_pattern_index];

	return instance;
}

Instance* generate_instance() {
	InstanceType instance_type = get_instance_type();

	if( instance_type != RealText ) {
		int* sizes = get_text_and_pattern_size();

		int text_size = sizes[0];
		int pattern_size = sizes[1];

		if( instance_type == Random ) {
			int limit = get_pattern_limit();

			std::cout << "generating random instance" << std::endl;
		} else {
			if( instance_type == WorstCase1 ) {
				std::cout << "generating worst case 1 instance" << std::endl;

				return generate_worst_case_1_instance(text_size, pattern_size);
			} else { // instance_type == WorstCase2
				std::cout << "generating worst case 2 instance" << std::endl;

				return generate_worst_case_2_instance(text_size, pattern_size);
			}
		}
	} else {
		int real_pattern_index = get_real_word_index();

		std::cout << "generating real text instance" << std::endl;
	}
}
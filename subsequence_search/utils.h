#ifndef UTILS_H
#define UTILS_H

struct Instance {
	char* text;
	char* pattern;
};

char* generate_as_vector(int size);

char* generate_as_vector_with_a_b(int size);

Instance* generate_worst_case_1_instance(int text_size, int pattern_size);

Instance* generate_worst_case_2_instance(int text_size, int pattern_size);

Instance* generate_instance();

#endif
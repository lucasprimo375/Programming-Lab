#ifndef INSTANCE_GENERATOR_H
#define INSTANCE_GENERATOR_H

struct Instance {
	char* text;
	char* pattern;
};

Instance* generate_worst_case_1_instance(int text_size, int pattern_size);

Instance* generate_worst_case_2_instance(int text_size, int pattern_size);

Instance* generate_random_instance(int text_size, int pattern_size, int limit);

Instance* generate_real_text_instance(int real_pattern_index);

Instance* generate_instance();

#endif
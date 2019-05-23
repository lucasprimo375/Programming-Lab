#ifndef UTILS_H
#define UTILS_H

#include "instance.h"

enum InstanceType {Random, WorstCase1, WorstCase2, RealText};

char* generate_as_vector(int size);

char* generate_as_vector_with_a_b(int size);

int generate_random_number(int min_value, int max_value);

char* generate_random_text(int size, int limit);

void print_text(char* text);

void print_instance(Instance* instance);

void print_matching_indexes(int* matching_indexes);

#endif
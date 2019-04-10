#ifndef UTILS_H
#define UTILS_H

int* generate_random_instance(int size, float min_value, float max_value);
bool is_vector_sorted(int* vector, int size);
void print_vector(int* vector, int size);
int* copy_vector(int* vector, int size);

#endif
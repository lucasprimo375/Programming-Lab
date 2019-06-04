#include <iostream>
#include <random>

#include "utils.h"
#include "instance.h"
#include "instance_type.h"

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

int generate_random_number(int min_value, int max_value){
	std::random_device rd;
	
	std::mt19937 ger(rd());

	std::uniform_int_distribution<int> dis(min_value, max_value);

	return dis(ger);
}

char* generate_random_text(int size, int limit) {
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'z', 'w'};

	char* text = new char[size+1];

	for(int i=0; i<size; i++) {
		int character_index = generate_random_number(0, limit - 1);
		text[i] = alphabet[character_index];
	}

	text[size] = '\0';

	return text;
}

void print_text(char* text) {
	int i = 0;

	while( text[i] != '\0' ) {
		std::cout << text[i];

		i++;
	}

	std::cout << std::endl;
}

void print_instance(Instance* instance){
	if( instance->type != RealText ){
		char* text = instance->text;
		char* pattern = instance->pattern;


		std::cout << "printing instance text" << std::endl;
		print_text(text);

		std::cout << "printing instance pattern" << std::endl;
		print_text(pattern);
	}
}

void print_matching_indexes(int* matching_indexes) {
	int i = 0;

	std::cout << "Printing matching indexes" << std::endl;

	while( matching_indexes[i] != -1 ) {
		std::cout << matching_indexes[i] << " ";

		i++;
	}

	if( i != 0)	std::cout << std::endl;
	else std::cout << "There are no matching indexes" << std::endl;
}
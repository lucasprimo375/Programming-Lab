#include <iostream>
#include <time.h>
#include <random>

#include "utils.h"
#include "instance.h"

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
	//srand(time(nullptr));

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

	std::cout << "." << std::endl;
}

void print_instance(Instance* instance){
	char* text = instance->text;
	char* pattern = instance->pattern;


	std::cout << "printing instance text" << std::endl;
	print_text(text);
}
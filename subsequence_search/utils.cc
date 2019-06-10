#include <iostream>
#include <random>
#include <chrono>

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

void print_text(const char* text) {
	int i = 0;

	while( (text[i] != '\0') && (i < 100) ) {
		std::cout << text[i];

		i++;
	}

	if( (text[i] != '\0') && (i >= 100) ) std::cout << "...";

	std::cout << std::endl;
}

void print_instance(Instance* instance){
	const char* text = instance->text;
	const char* pattern = instance->pattern;


	std::cout << std::endl << "printing instance text" << std::endl;
	print_text(text);

	std::cout << std::endl << "printing instance pattern" << std::endl;
	print_text(pattern);
}

void print_matching_indexes(int* matching_indexes) {
	int i = 0;

	std::cout << std::endl << "Printing matching indexes" << std::endl;

	while( (matching_indexes[i] != -1) /*&& (i < 100)*/ ) {
		if( i < 100 ) std::cout << matching_indexes[i] << " ";

		i++;
	}

	if( i >= 100 ) std::cout << "...";

	if( matching_indexes[i] == -1 )	std::cout << std::endl;
	else std::cout << std::endl << "There are no matching indexes" << std::endl;
}

bool is_equal(int* matching_1, int* matching_2) {
	int i = 0;

	while( (matching_1[i] != -1) && (matching_2[i] != -1) && (matching_1[i] == matching_2[i]) )
		i++;

	if( (matching_1[i] == -1) && (matching_2[i] == -1) ) return true;

	return false;
}

int get_text_size(const char* text) {
	int i = 0;
	
	while( text[i] != '\0' )
		i++;
		
	return i;
}

int get_time_seconds(){
	std::chrono::milliseconds ms = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());
	
	return ms.count();
}
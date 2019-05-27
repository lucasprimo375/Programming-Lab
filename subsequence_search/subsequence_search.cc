#include <iostream>

#include "subsequence_search.h"

bool brute_force_subsequence(char* text, char* pattern, int begin_index) {
	int text_index = begin_index;
	int pattern_index = 0;

	while( (text[text_index] != '\0') && (pattern[pattern_index] != '\0' ) ){
		if( text[text_index] != pattern[pattern_index]) return false;
	
		text_index++;
		pattern_index++;
	}

	if( (text[text_index] == '\0') && (pattern[pattern_index] != '\0') ) return false;

	return true;
}

void brute_force(char* text, char* pattern, int* output) {
	int i = 0;
	int output_index = 0;

	while( text[i] != '\0' ) {
		if( brute_force_subsequence(text, pattern, i) ) {
			output[output_index] = i;
			output_index++;
		}

		i++;
	}

	output[output_index] = -1;
}

int get_text_size(char* text) {
	int i = 0;
	
	while( text[i] != '\0' )
		i++;
		
	return i;
}

int* build_failure_function(char* pattern) {
	int i = 1;
	int j = 0;
	
	int pattern_size = get_text_size(pattern);
	int* failure_function = new int[pattern_size + 2];
	
	failure_function[0] = 0;

	while( i < pattern_size ) {
		std::cout << "i is " << i << std::endl;
		if( pattern[i] = pattern[j] ) {
			failure_function[i] = failure_function[j];
		} else {
			failure_function[i] = j;
			j = failure_function[j];

			while( (j >= 0) && (pattern[i] != pattern[j]) ) {
				std::cout << "j is " << j << std::endl;
				j = failure_function[j];
			}

			i++;
			j++;
		}
	}

	failure_function[i] = j;

	failure_function[i+1] = -1;

	return failure_function;
}

void knuth_morris_pratt(char* text, char* pattern, int* output) {
	int* failure_function = build_failure_function(pattern);
	
	int i = 0;
	while( failure_function[i] != -1 ) {
		std::cout << i << ": " << failure_function[i] << std::endl;
		i++;
	}
}

#include <iostream>

#include "subsequence_search.h"
#include "utils.h"

bool brute_force_subsequence(const char* text, const char* pattern, int begin_index) {
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

void brute_force(const char* text, const char* pattern, int* output) {
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

int* build_failure_function(const char* pattern) {
	int pattern_size = get_text_size(pattern);
	int* failure_function = new int[pattern_size];
	
	failure_function[0] = 0;

	for( int i = 1; i < pattern_size; i++ ) {
		int k = i - 1;

		for(;;) {
			int l = failure_function[k];

			if( l == 0 ) {
				if( pattern[0] == pattern[i] ) failure_function[i] = 1;
				else failure_function[i] = 0;
				break;
			} else {
				if( pattern[i] == pattern[l] ) {
					failure_function[i] = l + 1;
					break;
				} else {
					k = l - 1;
				}
			}
		}
	}
	
	return failure_function;
}

void knuth_morris_pratt(const char* text, const char* pattern, int* output) {
	int* failure_function = build_failure_function(pattern);

	int i = 0;
	int j = 0;
	int k = 0;
	
	int n = get_text_size(text);
	int m = get_text_size(pattern);

	while( i < n ) {
		if( text[i] != pattern[j] ) {
			if( j == 0 ) i++;
			else j = failure_function[j - 1];
		} else {
			if( j == m - 1 ){
				output[k] = i - j;
				k++;

				j = failure_function[j];
				i++;
			} else {
				i++;
				j++;
			}
		}
	}

	output[k] = -1;
}

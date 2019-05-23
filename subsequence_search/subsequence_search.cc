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
#ifndef SUBSEQUENCE_SEARCH
#define SUBSEQUENCE_SEARCH

bool brute_force_subsequence(char* text, char* pattern, int begin_index);

void brute_force(char* text, char* pattern, int* output);

int get_text_size(char* text);

int* build_failure_function(char* pattern);

void knuth_morris_pratt(char* text, char* pattern, int* output);

#endif

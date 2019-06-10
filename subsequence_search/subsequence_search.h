#ifndef SUBSEQUENCE_SEARCH
#define SUBSEQUENCE_SEARCH

bool brute_force_subsequence(const char* text, const char* pattern, int begin_index);

void brute_force(const char* text, const char* pattern, int* output);

int* build_failure_function(const char* pattern);

void knuth_morris_pratt(const char* text,const char* pattern, int* output);

#endif

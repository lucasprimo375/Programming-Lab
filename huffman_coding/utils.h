#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <unordered_map>

#include "min_heap.h"
#include "node.h"

namespace Utils {
	void print_file(std::string file_name);

	std::unordered_map<char, int>* get_frequency_table(std::string file_name);
	void insert_characters(std::unordered_map<char, int>* frequency_table, std::string line);
	void print_frequency_table(std::unordered_map<char, int>* frequency_table);

	MinHeap* build_frequency_min_heap( std::string file_name );

	void generate_huffman_code( node* root, node* n, std::string* code, std::unordered_map<std::string, std::string>* code_map );
	void print_code_map(std::unordered_map<std::string, std::string>* code_map);
};

#endif
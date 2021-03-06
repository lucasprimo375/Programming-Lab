#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <unordered_map>
#include <vector>

#include "min_heap.h"
#include "node.h"

namespace Utils {
	void print_file(std::string file_name);

	std::unordered_map<char, int>* get_frequency_table(std::string file_name);
	void insert_characters(std::unordered_map<char, int>* frequency_table, char Char);
	void print_frequency_table(std::unordered_map<char, int>* frequency_table);

	MinHeap* build_frequency_min_heap( std::string file_name );

	void generate_huffman_code( node* root, node* n, std::string* code, std::unordered_map<std::string, std::string>* code_map );
	void print_code_map(std::unordered_map<std::string, std::string>* code_map);

	bool write_coded_file(std::unordered_map<std::string, std::string>* code_map, std::string file_name_to_encode, std::string output_file_name, node* treeRoot);
	std::string encode_string( std::unordered_map<std::string, std::string>* code_map, std::string string_to_encode );
	void write_tree_to_file( std::ofstream& output_stream, node* treeRoot );
	void write_tree(node* n, std::vector<char>& tree);
	bool write_string_to_file( std::string string, std::string output_file_name);

	std::unordered_map<std::string, std::string>* build_code_map( std::string file_to_decode );
	void write_decoded_file( std::unordered_map<std::string, std::string>* code_map, std::string file_name_to_decode, std::string output_file_name );
	std::string decode_string( std::unordered_map<std::string, std::string>* code_map, std::string string );
	bool is_string_decodable( std::string string );

	bool compare_files( std::string first, std::string second );

	void decode( std::string file_name_to_decode, std::string output_file_name );

	node* build_tree( std::string output_string, int& position, node* n );
};

#endif
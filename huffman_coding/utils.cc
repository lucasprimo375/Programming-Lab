#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "utils.h"
#include "min_heap.h"
#include "node.h"

void Utils::print_file(std::string file_name) {
	std::ifstream file_stream;
	
	file_stream.open(file_name.c_str(), std::ifstream::in);

	if( file_stream ) {
		std::cout << std::endl << "Printing " << file_name << "'s content" << std::endl << std::endl;

		std::string line;

		while( std::getline(file_stream, line) ) {
		    std::cout << line << std::endl;
		}
	} else {
		std::cout << std::endl << "Your file could not be opened or does not exist" << std::endl;
	}

	file_stream.close();
}

std::unordered_map<char, int>* Utils::get_frequency_table(std::string file_name) {
	std::ifstream file_stream;

	file_stream.open(file_name.c_str(), std::ifstream::in);

	if( !file_stream ) {
		return nullptr;
	}

	std::unordered_map<char, int>* frequency_table = new std::unordered_map<char, int>();

	std::string line;

	while( std::getline(file_stream, line) ) {
	    Utils::insert_characters(frequency_table, line);
	}

	return frequency_table;
}

void Utils::insert_characters(std::unordered_map<char, int>* frequency_table, std::string line) {
	int line_size = line.size();

	for( int i = 0; i < line_size; i++ ) {
		char char_i = line[i];
		auto char_iterator = frequency_table->find( char_i );

		if( char_iterator == frequency_table->end() ) {
			frequency_table->emplace( char_i, 1 );
		} else {
			int char_count = char_iterator->second;

			char_count++;

			frequency_table->erase( char_i );

			frequency_table->emplace( char_i, char_count);
		}
	}
}

void Utils::print_frequency_table(std::unordered_map<char, int>* frequency_table) {
	for( auto& entry : *frequency_table ) {
		std::cout << entry.first << ": " << entry.second << std::endl;
	}
}

MinHeap* Utils::build_frequency_min_heap( std::string file_name ) {
	std::unordered_map<char, int>* frequency_table = Utils::get_frequency_table( file_name );

	MinHeap* minHeap = new MinHeap();

	for( auto& entry : *frequency_table ) {
		node* n = new node();
		n->character = entry.first;
		n->frequency = entry.second;

		minHeap->addNode( n );
	}

	return minHeap;
}

void Utils::generate_huffman_code( node* root, node* n, std::string* code, std::unordered_map<std::string, std::string>* code_map) {
	if( n->character.size() == 1 ) {
		if( ( root == n ) && ( n->left == nullptr ) && ( n->right == nullptr ) )
			code_map->emplace( n->character, *code );
		else {
			code_map->emplace( n->character, *code );
			*code = code->substr(0, code->size() - 1);
		}
	}

	if( n->left != nullptr ) {
		code->append("0");
		Utils::generate_huffman_code( root, n->left, code, code_map );
	}

	if( n->right != nullptr ) {
		code->append("1");
		Utils::generate_huffman_code( root, n->right, code, code_map );
	}

	if( ( n->left != nullptr ) && ( n->right != nullptr ) )
		*code = code->substr(0, code->size() - 1);
}

void Utils::print_code_map(std::unordered_map<std::string, std::string>* code_map) {
	for( auto& entry : *code_map ) {
		std::cout << entry.first << ": " << entry.second << std::endl;
	}
}
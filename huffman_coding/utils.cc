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

	Utils::print_frequency_table( frequency_table );

	MinHeap* minHeap = new MinHeap();

	for( auto& entry : *frequency_table ) {
		node* n = new node();
		n->character = entry.first;
		n->frequency = entry.second;

		minHeap->addNode( n );
	}

	return minHeap;
}
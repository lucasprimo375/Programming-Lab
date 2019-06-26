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

bool Utils::write_coded_file(std::unordered_map<std::string, std::string>* code_map, std::string file_name_to_encode, std::string output_file_name) {
	output_file_name.append(".huff");

	std::ifstream file_stream;

	file_stream.open(file_name_to_encode.c_str(), std::ifstream::in);

	if( !file_stream ) {
		return false;
	}

	bool result = Utils::write_tree_to_file( code_map, output_file_name );

	if( !result ) return false;

	std::string line;

	while( std::getline(file_stream, line) ) {
		std::string encoded_string = Utils::encode_string( code_map, line );
		Utils::write_string_to_file(encoded_string, output_file_name);
	}

	return true;
}

std::string Utils::encode_string( std::unordered_map<std::string, std::string>* code_map, std::string string_to_encode ) {
	std::string encoded_string = "";

	int size = string_to_encode.size();

	for( int i = 0; i < size; i++ ){
		std::string str(1, string_to_encode[i]);
		encoded_string.append( code_map->find(str)->second );
	}

	return encoded_string;
}

bool Utils::write_tree_to_file( std::unordered_map<std::string, std::string>* code_map, std::string output_file_name ) {
	std::ofstream output_stream;

	output_stream.open( output_file_name.c_str(), std::ifstream::out );

	if( !output_stream ) return false;

	for( auto& entry : *code_map ) {
		output_stream << entry.first << ": " << entry.second << std::endl;
	}

	output_stream.close();

	return true;
}

bool Utils::write_string_to_file( std::string string, std::string output_file_name) {
	std::ofstream output_stream;

	output_stream.open( output_file_name.c_str(), std::ifstream::app );

	if( !output_stream ) return false;

	output_stream << string << std::endl;

	output_stream.close();

	return true;
}

std::unordered_map<std::string, std::string>* Utils::build_code_map( std::string file_to_decode ) {
	std::ifstream file_stream;

	file_stream.open(file_to_decode.c_str(), std::ifstream::in);

	if( !file_stream ) {
		return nullptr;
	}

	std::unordered_map<std::string, std::string>* code_map = new std::unordered_map<std::string, std::string>();

	std::string line;

	while( std::getline(file_stream, line) ) {
		std::string delimiter = ": ";
		
		auto pos = line.find(delimiter);

		if( pos == std::string::npos ) break;

		std::string token = line.substr(0, pos);

		std::string code = line.substr(pos + 2, line.size() - pos);

		code_map->emplace( code, token);
	}

	file_stream.close();

	return code_map;
}

void Utils::write_decoded_file( std::unordered_map<std::string, std::string>* code_map, std::string file_name_to_decode, std::string output_file_name ) {
	std::ifstream input_stream;
	std::ofstream output_stream;

	input_stream.open( file_name_to_decode.c_str(), std::ifstream::in );
	output_stream.open( output_file_name.c_str(), std::ifstream::out );

	if( ( input_stream ) && ( output_stream ) ) {
		std::string line;

		while( std::getline( input_stream, line ) ) {
			if( Utils::is_string_decodable(line) ) {
				output_stream << Utils::decode_string( code_map, line ) << std::endl;
			}
		}
	}
}

std::string Utils::decode_string( std::unordered_map<std::string, std::string>* code_map, std::string string ) {
	std::string aux = string;

	std::string output = "";

	while( aux.size() > 0 ) {
		std::string code (1, aux[0]);
		int i = 0;

		auto iter = code_map->find(code);

		while( iter == code_map->end() ) {
			i++;
			code += aux[i];
			iter = code_map->find(code);
		}

		output.append( iter->second );

		aux = aux.substr(i+1, aux.size() - i);
	}

	return output;
}

bool Utils::is_string_decodable( std::string string ) {
	std::string delimiter = ": ";
		
	auto pos = string.find(delimiter);

	if( pos == std::string::npos ) return true;

	return false;
}

bool Utils::compare_files( std::string first, std::string second ) {
	std::ifstream first_stream;
	std::ifstream second_stream;

	first_stream.open( first.c_str(), std::ifstream::in );
	second_stream.open( second.c_str(), std::ifstream::in );

	if( (!first_stream) || (!second_stream) ){
		std::cout << std::endl << "One of the files could not be opened or does not exist" << std::endl;

		return false;
	}

	std::string first_line;
	std::string second_line;

	bool once = false;

	while( std::getline( first_stream, first_line ) ) {
		once = true;
		
		if( !std::getline(second_stream, second_line) )
			return false;

		if( first_line != second_line ) return false;
	}

	if( (!once) && (std::getline(second_stream, second_line)) )
		return false;

	return true;
}
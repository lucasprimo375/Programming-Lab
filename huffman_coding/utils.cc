#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "utils.h"
#include "min_heap.h"
#include "node.h"

#define INTERNAL_NODE '@'
#define NULL_NODE '&'
#define LEAF_NODE '*'

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

	char Char;

	while( file_stream >> std::noskipws >> Char ) {
	    Utils::insert_characters(frequency_table, Char);
	}

	return frequency_table;
}

void Utils::insert_characters(std::unordered_map<char, int>* frequency_table, char Char) {
	auto char_iterator = frequency_table->find( Char );

	if( char_iterator == frequency_table->end() ) {
		frequency_table->emplace( Char, 1 );
	} else {
		int char_count = char_iterator->second;

		char_count++;

		frequency_table->erase( Char );

		frequency_table->emplace( Char, char_count);
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

bool Utils::write_coded_file(std::unordered_map<std::string, std::string>* code_map, std::string file_name_to_encode, std::string output_file_name, node* treeRoot) {
	output_file_name.append(".huff");

	std::ifstream file_stream;

	file_stream.open(file_name_to_encode, std::ios::binary);

	std::ofstream output_stream;
	output_stream.open( output_file_name, std::ios::binary );

	if( (!file_stream) || (!output_stream) ) {
		return false;
	}

	Utils::write_tree_to_file( output_stream, treeRoot );

	std::string line;

	char readChar;
	std::string charCode;
	int byteCounter = 0;
	char byte_to_write = 0;

	char leftOverBits = 0;
	std::streamoff leftOverBitsAddress = output_stream.tellp();
	output_stream.write( (char*)&leftOverBits, sizeof(char) );

	int number_of_bytes = 0;
	std::streamoff number_of_bytes_address = output_stream.tellp();
	output_stream.write( (char*)&number_of_bytes, sizeof(int) );
	
	while( file_stream >> std::noskipws >> readChar ) {
		std::string charStrAux(1, readChar);
		charCode = code_map->find(charStrAux)->second;

		int codeLength = charCode.length();

		for( int i = 0; i < codeLength; i++ ){
			if( byteCounter == 8 ){
				if( file_stream.eof() ) break;

				output_stream.write( &byte_to_write, sizeof(char) );

				byteCounter = 0;
				byte_to_write = 0;
				number_of_bytes++;
			}

			byte_to_write = byte_to_write << 1;

			if( charCode[i] == '1' ){
				byte_to_write = byte_to_write | (char) 1;
			}

			byteCounter++;
		}
	}

	if( byteCounter != 8 ) {
		leftOverBits = (char) 8 - byteCounter;
		number_of_bytes++;
		byte_to_write = byte_to_write << leftOverBits;

		output_stream.write( (char*)&byte_to_write, sizeof(char) );
		output_stream.seekp( leftOverBitsAddress );
		output_stream.write( &leftOverBits, sizeof(char) );
		output_stream.seekp( number_of_bytes_address );
		output_stream.write( (char*)&number_of_bytes, sizeof(int) );
	}

	file_stream.close();

	output_stream.close();

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

void Utils::write_tree_to_file( std::ofstream& output_stream, node* treeRoot ) {
	std::vector<char> tree;

	Utils::write_tree(treeRoot, tree);

	int treeSize = tree.size();

	output_stream.write((char*)&treeSize, sizeof(int));
	output_stream.write(tree.data(), treeSize);
}

void Utils::write_tree(node* n, std::vector<char>& tree) {
	if( n == nullptr ) {
		tree.push_back( NULL_NODE );
	} else if( (n->left == nullptr) && (n->right == nullptr) ) {
		tree.push_back( LEAF_NODE );
		tree.push_back( n->character[0] );
	} else {
		tree.push_back( INTERNAL_NODE );
		Utils::write_tree(n->left, tree);
		Utils::write_tree(n->right, tree);
	}
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
#include <iostream>
#include <string>

#include "user_input.h"
#include "huffman_encoding.h"

int main() {
	int choice;
	
	std::cout << "Input 1 to encode or 2 to decode" << std::endl;
	std::cout << ">> ";
	std::cin >> choice;

	if( choice == 1 ) {
		std::string file_name_to_encode = UserInput::get_file_to_encode();

		std::string output_file_name = UserInput::get_output_file_name();

		Huffman::encode(file_name_to_encode, output_file_name);
	}

	if( choice == 2 ) {
		std::string file_name_to_decode = UserInput::get_file_to_decode();

		std::string output_file_name = UserInput::get_decoded_file_name();

		Huffman::decode(file_name_to_decode, output_file_name);
	}

	return 0;
}
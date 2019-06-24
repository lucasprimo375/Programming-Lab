#include <iostream>
#include <string>

#include "user_input.h"
#include "huffman_encoding.h"

int main() {
	std::string file_name_to_encode = UserInput::get_file_to_encode();

	std::string output_file_name = UserInput::get_output_file_name();

	Huffman::encode(file_name_to_encode, output_file_name);

	return 0;
}
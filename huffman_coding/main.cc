#include <iostream>
#include <string>

#include "user_input.h"
#include "huffman_encoding.h"

int main() {
	std::string file_name_to_encode = UserInput::get_file_to_encode();

	Huffman::encode(file_name_to_encode);

	return 0;
}
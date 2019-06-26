#include <iostream>
#include <string>

#include "user_input.h"
#include "huffman_encoding.h"
#include "utils.h"

int main() {
	UserInput::UserAction user_action = UserInput::get_user_action();
	while( user_action != UserInput::UserAction::Leave ) {
		switch( user_action ) {
			case UserInput::UserAction::Encode: {
				std::string file_name_to_encode = UserInput::get_file_to_encode();

				std::string output_file_name = UserInput::get_output_file_name();

				Huffman::encode(file_name_to_encode, output_file_name);
			
				break;
			}
		

			case UserInput::UserAction::Decode: {
				std::string file_name_to_decode = UserInput::get_file_to_decode();

				std::string output_file_name = UserInput::get_decoded_file_name();

				Huffman::decode(file_name_to_decode, output_file_name);
			
				break;
			}

			case UserInput::UserAction::Compare: {
				std::string first_file = UserInput::get_file_to_compare("first");

				std::string second_file = UserInput::get_file_to_compare("second");

				if( Utils::compare_files(first_file, second_file) )
					std::cout << std::endl << "The files are equal" << std::endl;
				else std::cout << std::endl << "The files are different" << std::endl;
			
				break;
			}
		}

		user_action = UserInput::get_user_action();
	}

	return 0;
}
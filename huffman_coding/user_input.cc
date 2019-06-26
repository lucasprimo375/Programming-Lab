#include <string>
#include <iostream>
#include <fstream>

#include "user_input.h"

std::string UserInput::get_file_to_encode() {
	std::string file_name;

	bool bad_file = true;

	while( bad_file ) {
		std::cout << std::endl << "Input the relative path of the file to be encoded, with its extension" << std::endl;
		std::cout << ">> ";

		std::cin >> file_name;

		std::ifstream file_to_encode;
		file_to_encode.open(file_name.c_str(), std::ifstream::in);

		if( !file_to_encode ){
			std::cout << std::endl << "Your input file could not be opened or does not exist" << std::endl;
		} else {
			bad_file = false;
		}

		file_to_encode.close();
	}

	return file_name;
}

std::string UserInput::get_output_file_name() {
	std::string output_file_name;
	
	std::cout << std::endl << "Input output file name" << std::endl;
	std::cout << ">> ";
	std::cin >> output_file_name;

	return output_file_name;
}

std::string UserInput::get_file_to_decode() {
	std::string file_name;

	bool bad_file = true;

	while( bad_file ) {
		std::cout << std::endl << "Input the relative path of the file to be decoded, with its extension huff" << std::endl;
		std::cout << ">> ";

		std::cin >> file_name;

		std::ifstream file_to_encode;
		file_to_encode.open(file_name.c_str(), std::ifstream::in);

		if( !file_to_encode ){
			std::cout << std::endl << "Your input file could not be opened or does not exist" << std::endl;
		} else {
			bad_file = false;
		}

		file_to_encode.close();
	}

	return file_name;	
}

std::string UserInput::get_decoded_file_name() {
	std::string output_file_name;
	
	std::cout << std::endl << "Input output file name, with its original extension" << std::endl;
	std::cout << ">> ";
	std::cin >> output_file_name;

	return output_file_name;
}

std::string UserInput::get_file_to_compare(std::string message) {
	std::string file = "";

	while( file == "" ) {
		std::cout << std::endl << "Input the " << message << " file name, with its extension" << std::endl;
		std::cout << ">> ";
		std::cin >> file;

		std::ifstream stream;
		stream.open( file.c_str(), std::ifstream::in );

		if( !stream ) {
			std::cout << std::endl << "Your file could not be opened or does not exist" << std::endl;
			file = "";
		}
	}

	return file;
}

UserInput::UserAction UserInput::get_user_action() {
	int action = 0;

	while( (action < 1) || (action > 4) ) {
		std::cout << std::endl << "Input 1 to encode, 2 to decode, 3 to compare two files or 4 to leave" << std::endl;
		std::cout << ">> ";
		std::cin >> action;
	}

	UserInput::UserAction user_action;

	switch( action ) {
		case 1:
			user_action = UserInput::UserAction::Encode;
			break;

		case 2:
			user_action = UserInput::UserAction::Decode;
			break;

		case 3:
			user_action = UserInput::UserAction::Compare;
			break;

		case 4:
			user_action = UserInput::UserAction::Leave;
			break;

		default:
			user_action = UserInput::UserAction::Encode;
			break;
	}

	return user_action;
}
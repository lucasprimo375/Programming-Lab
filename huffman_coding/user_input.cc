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
#include "user_input.h"

#include <iostream>
#include <string>

int get_vector_size(){
	int vector_size = 0;

	while(vector_size <= 0){
		std::cout << "Input vector size" << std::endl
					<< "Your choice: ";
		std::cin >> vector_size;
	}

	return vector_size;
}

int* get_min_max_values(){
	int min_value = 1;
	int max_value = 0;

	while(max_value < min_value){
		std::cout << "Input min value" << std::endl
					<< "Your choice: ";
		std::cin >> min_value;

		std::cout << "Input max value" << std::endl
					<< "Your choice: ";
		std::cin >> max_value;
	}

	int* limits = new int[2];

	limits[0] = min_value;
	limits[1] = max_value;

	return limits;
}

bool should_continue(){
	int number;

	std::cout << "Do you wish to run the program again?" << std::endl
				<< "Input positive number to continue or negative/zero to end" << std::endl
				<< "Your choice: ";
	std::cin >> number;

	return number > 0;
}

bool should_generate_bad_instance() {
	std::string input = "";

	while((input != "yes") && (input != "no")){
		std::cout << "Generate bad instances? (yes/no)" << std::endl
					<< ">> ";
		std::cin >> input;
	}

	return input == "yes";
}

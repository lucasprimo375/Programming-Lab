#include <iostream>
#include <string>

#include "user_input.h"
#include "utils.h"
#include "instance_type.h"

InstanceType get_instance_type(){
	return Random;
	int type = -1;

	while((type < 0) || (type > 3)){
		std::cout << "Input intance type (0-Random, 1-Worst Case 1, 2-Worst Case 2, 3-Real Text)" << std::endl
					<< ">> ";

		std::cin >> type;
	}

	switch(type){
		case 0: return Random;
		
		case 1:	return WorstCase1;

		case 2: return WorstCase2;

		case 3: return RealText;
		
		default: return Random;
	}
}

int get_text_size(){
	return 21;
	int text_size = 0;

	while(text_size <= 0){
		std::cout << "Input text size: " << std::endl
					<< ">> ";

		std::cin >> text_size;
	}

	return text_size;
}

int get_pattern_size(){
	return 2;
	int pattern_size = 0;

	while(pattern_size <= 0){
		std::cout << "Input pattern size: " << std::endl
					<< ">> ";

		std::cin >> pattern_size;
	}

	return pattern_size;
}

int* get_text_and_pattern_size(){
	int text_size = 1;
	int pattern_size = 2;

	while(text_size < pattern_size){
		text_size = get_text_size();
		pattern_size = get_pattern_size();
	}

	int* sizes = new int[2];

	sizes[0] = text_size;
	sizes[1] = pattern_size;

	return sizes;
}

int get_pattern_limit(){
	return 1;
	int limit = 0;

	while( (limit <= 0) || (limit > 26) ){
		std::cout << "Input the alphabet limit: " << std::endl
					<< ">> ";

		std::cin >> limit;
	}

	return limit;
}

int get_real_word_index() {
	int limit = -1;

	while( (limit < 0) || (limit > 35129) ){
		std::cout << "Input the real pattern index (0 - 35129): " << std::endl
					<< ">> ";

		std::cin >> limit;
	}

	return limit;	
}

bool should_continue() {
	return false;
	std::string answer = "bla";

	std::cout << std::endl;
	
	while( (answer != "y") && (answer != "n") ) {
		std::cout << "Would you like to continue the execution? (y, n)"
				<< std::endl
				<< ">> ";

		std::cin >> answer;
	}

	return answer == "y";
}
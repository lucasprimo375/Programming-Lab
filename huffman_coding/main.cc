#include <iostream>
#include <string>

#include <unordered_map>

#include "user_input.h"
#include "utils.h"

int main() {
	std::string file_name = UserInput::get_file_to_encode();

	std::unordered_map<char, int>* frequency_table = Utils::get_frequency_table(file_name);

	Utils::print_frequency_table(frequency_table);

	return 0;
}
#include <iostream>

#include "user_input.h"
#include "utils.h"

int main() {
	Utils::print_file( UserInput::get_file_to_encode() );

	return 0;
}
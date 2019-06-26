#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>

namespace UserInput {
	enum class UserAction { Encode, Decode, Compare, Leave };

	std::string get_file_to_encode();

	std::string get_output_file_name();

	std::string get_file_to_decode();

	std::string get_decoded_file_name();

	std::string get_file_to_compare(std::string message);

	UserInput::UserAction get_user_action();
};

#endif
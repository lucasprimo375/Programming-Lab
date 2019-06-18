#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <unordered_map>

namespace Utils {
	void print_file(std::string file_name);

	std::unordered_map<char, int>* get_frequency_table(std::string file_name);
	void insert_characters(std::unordered_map<char, int>* frequency_table, std::string line);
	void print_frequency_table(std::unordered_map<char, int>* frequency_table);
};

#endif
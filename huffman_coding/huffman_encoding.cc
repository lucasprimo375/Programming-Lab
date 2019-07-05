#include <string>
#include <unordered_map>
#include <iostream>

#include "huffman_encoding.h"
#include "utils.h"
#include "min_heap.h"
#include "node.h"

void Huffman::encode( std::string file_name_to_encode, std::string output_file_name ) {
	MinHeap* minHeap = Utils::build_frequency_min_heap( file_name_to_encode );

	while( minHeap->getSize() > 1 ) {
		node* na = minHeap->getMin();
		node* nb = minHeap->getMin();

		node* c = new node();
		c->character = na->character + nb->character;
		c->frequency = na->frequency + nb->frequency;
		c->left = na;
		c->right = nb;

		minHeap->addNode(c);
	}

	std::string* code = new std::string;

	node* root = minHeap->getMin();

	std::unordered_map<std::string, std::string>* code_map = new std::unordered_map<std::string, std::string>();

	if( root == nullptr ) {
		code_map->emplace("", "0");
	} else {
		Utils::generate_huffman_code( root, root, code, code_map );
	}

	bool result = Utils::write_coded_file( code_map, file_name_to_encode, output_file_name, root );

	if( !result ) {
		std::cout << "Your file could not be opened or does not exist" << std::endl;
	}
}

void Huffman::decode( std::string file_name_to_decode, std::string output_file_name ) {
	/*std::unordered_map<std::string, std::string>* code_map = Utils::build_code_map( file_name_to_decode );

	Utils::write_decoded_file( code_map, file_name_to_decode, output_file_name );*/

	Utils::decode( file_name_to_decode, output_file_name );
}
#include <string>
#include <unordered_map>
#include <iostream>

#include "huffman_encoding.h"
#include "utils.h"
#include "min_heap.h"
#include "node.h"

void Huffman::encode( std::string file_name_to_encode ) {
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

	Utils::print_code_map( code_map );
}
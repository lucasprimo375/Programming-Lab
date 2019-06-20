#include <string>
#include <unordered_map>

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

	//minHeap->print();

	Utils::print_huffman_tree( minHeap->getMin(), "" );
}
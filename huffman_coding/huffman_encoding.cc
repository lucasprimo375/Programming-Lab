#include <string>
#include <unordered_map>

#include "huffman_encoding.h"
#include "utils.h"
#include "min_heap.h"

void Huffman::encode( std::string file_name_to_encode ) {
	MinHeap* minHeap = Utils::build_frequency_min_heap( file_name_to_encode );

	minHeap->print();
}
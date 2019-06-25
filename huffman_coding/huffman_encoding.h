#ifndef HUFFMAN_ENCODING_H
#define HUFFMAN_ENCODING_H

namespace Huffman {
	void encode( std::string file_name_to_encode, std::string output_file_name );

	void decode( std::string file_name_to_decode, std::string output_file_name );
};

#endif
all: main.o user_input.o utils.o min_heap.o huffman_encoding.o
	g++ -o main main.o user_input.o utils.o min_heap.o huffman_encoding.o

main.o: main.cc user_input.h huffman_encoding.h utils.h
	g++ -c main.cc

utils.o: utils.cc utils.h min_heap.h node.h
	g++ -c utils.cc

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc

min_heap.o: min_heap.cc min_heap.h node.h
	g++ -c min_heap.cc

huffman_encoding.o: huffman_encoding.cc huffman_encoding.h utils.h node.h
	g++ -c huffman_encoding.cc
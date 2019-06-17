all: main.o user_input.o utils.o min_heap.o
	g++ -o main main.o user_input.o utils.o min_heap.o

main.o: main.cc user_input.h utils.h min_heap.h
	g++ -c main.cc

utils.o: utils.cc utils.h
	g++ -c utils.cc

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc

min_heap.o: min_heap.cc min_heap.h node.h
	g++ -c min_heap.cc
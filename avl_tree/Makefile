all: main.o avl.o
	g++ -o main main.o avl.o

main.o: main.cc avl.hpp
	g++ -c main.cc


avl.o: avl.cpp avl.hpp
	g++ -c avl.cpp -std=c++11
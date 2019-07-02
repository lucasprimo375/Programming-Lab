all: main.o avl.o
	g++ -o main main.o avl.o

main.o: main.cc avl.hpp
	g++ -c main.cc -std=c++11


avl.o: avl.cpp avl.hpp
	g++ -c avl.cpp -std=c++11

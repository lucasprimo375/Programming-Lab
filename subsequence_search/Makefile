all: main.o user_input.o
	g++ -o main main.o user_input.o

main.o: main.cc
	g++ -c main.cc

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc
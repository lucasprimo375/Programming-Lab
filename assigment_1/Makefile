all: main.o utils.o user_input.o
	g++ -o main main.o utils.o user_input.o

main.o: main.cc utils.h user_input.h
	g++ -c main.cc

utils.o: utils.cc utils.h
	g++ -c utils.cc -std=c++11

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc
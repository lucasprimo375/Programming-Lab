all: main.o user_input.o utils.o
	g++ -o main main.o user_input.o utils.o

main.o: main.cc utils.h
	g++ -c main.cc

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc

utils.o: utils.cc utils.h user_input.h real_instances.h
	g++ -c utils.cc -std=c++11 -w
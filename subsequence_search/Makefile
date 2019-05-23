all: main.o user_input.o utils.o instance_generator.o subsequence_search.o
	g++ -o main main.o user_input.o utils.o instance_generator.o subsequence_search.o

main.o: main.cc instance_generator.h
	g++ -c main.cc

user_input.o: user_input.cc user_input.h utils.h
	g++ -c user_input.cc

utils.o: utils.cc utils.h
	g++ -c utils.cc -std=c++11 -w

instance_generator.o: instance_generator.cc instance_generator.h utils.h real_instances.h user_input.h instance.h
	g++ -c instance_generator.cc

subsequence_search.o: subsequence_search.cc subsequence_search.h
	g++ -c subsequence_search.cc
all: main.o utils.o user_input.o generic_quick_sort.o index_based_quick_sort.o random_pivot_quick_sort.o
	g++ -o main main.o utils.o user_input.o generic_quick_sort.o index_based_quick_sort.o random_pivot_quick_sort.o

main.o: main.cc utils.h user_input.h  generic_quick_sort.h index_based_quick_sort.h random_pivot_quick_sort.o
	g++ -c main.cc

random_pivot_quick_sort.o: random_pivot_quick_sort.cc random_pivot_quick_sort.h
	g++ -c random_pivot_quick_sort.cc -std=c++11

index_based_quick_sort.o: index_based_quick_sort.cc index_based_quick_sort.h generic_quick_sort.h
	g++ -c index_based_quick_sort.cc

generic_quick_sort.o: generic_quick_sort.cc generic_quick_sort.h
	g++ -c generic_quick_sort.cc -std=c++11

utils.o: utils.cc utils.h
	g++ -c utils.cc -std=c++11

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc
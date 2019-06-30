#include <iostream>
#include "avl.hpp"

int main() {
	DicAVL D;

	inicializar(D);

	while(true){
		double chave;

		std::cout << std::endl << "entre a chave: ";
		std::cin >> chave;

		inserir(D, chave, 1);

		print(D.raiz);
	}

	return 0;
}
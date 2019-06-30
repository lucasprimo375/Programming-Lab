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

		std::cout << std::endl << "printando a árvore:" << std::endl;

		print(D.raiz);

		std::cout << std::endl << "procure um no: ";
		std::cin >> chave;

		Noh* n = procurar(D, chave);
		if(n != nullptr)
			std::cout << std::endl << "achou no com valor " << n->valor << std::endl;
		else std::cout << "não há nó com chave " << chave << std::endl;
	}

	return 0;
}
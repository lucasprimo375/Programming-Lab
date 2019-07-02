#include <iostream>
#include "avl.hpp"

int main() {
	DicAVL D;

	inicializar(D);

	while(true){
		int escolha;
		std::cout << std::endl << "1 - Inserir, 2 - Remover, 3 - Buscar, 4 - Print" << std::endl;
		std::cout << ">> ";
		std::cin >> escolha;

		switch(escolha){
			case 1:{
				double chave;

				std::cout << std::endl << "entre a chave: ";
				std::cin >> chave;

				inserir(D, chave, 1);

				break;
			}

			case 2:{
				double chave;

				std::cout << std::endl << "entre a chave: ";
				std::cin >> chave;

				Noh* noh = procurar(D, chave);

				remover(D, noh);

				break;	
			}

			case 3:{
				double chave;

				std::cout << std::endl << "entre a chave: ";
				std::cin >> chave;

				Noh* noh = procurar(D, chave);

				if(noh != nullptr)
					std::cout << std::endl << "achou no com valor " << noh->valor << std::endl;
				else std::cout << "não há nó com chave " << chave << std::endl;

				break;	
			}

			case 4:{
				std::cout << std::endl << "printando a árvore:" << std::endl;

				print(D.raiz);

				break;
			}
		}
	}

	/*inserir(D, 1, 1);
	inserir(D, 2, 1);
	inserir(D, 3, 1);
	inserir(D, 4, 1);

	print(D.raiz);

	Noh* noh = procurar(D, 2);

	remover(D, noh);

	std::cout << std::endl;

	print(D.raiz);*/

	return 0;
}
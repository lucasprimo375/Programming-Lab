#include <iostream>
#include "avl.hpp"

int main() {
	DicAVL D;

	inicializar(D);

	bool run = true;

	while(run){
		int escolha;
		std::cout << std::endl << "1 - Inserir, 2 - Remover, 3 - Buscar, 4 - Print, 5 - Sair" << std::endl;
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

			case 5:{
				run = false;
				break;
			}
		}
	}

	return 0;
}
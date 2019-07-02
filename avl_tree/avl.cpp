#include <cmath>
#include <iostream>

#include "avl.hpp"

void inicializar(DicAVL &D) {
	D.raiz = nullptr;
}

Noh* inserir(DicAVL &D, TC c, TV v) {
	Noh* n;
	
	D.raiz = inserirNoh(D.raiz, D.raiz, c, v, &n);

	return n;
}

Noh* inserirNoh(Noh* noh, Noh* pai, TC c, TV v, Noh** n){
	if(noh == nullptr){
		Noh* novoNoh = new Noh();
		novoNoh->chave = c;
		novoNoh->valor = v;
		novoNoh->esq = nullptr;
		novoNoh->dir = nullptr;
		novoNoh->pai = pai;
		novoNoh->h = 1;

		*n = novoNoh;

		return novoNoh;
	}

	if(c > noh->chave) noh->dir = inserirNoh(noh->dir, noh, c, v, n);
	else if (c < noh->chave) noh->esq = inserirNoh(noh->esq, noh, c, v, n);
	else return noh;

	noh->h = 1 + maiorSubAltura(noh);

	int Dif = dif(noh);

	if (Dif > 1 && c < noh->esq->chave)
        return rotacaoDireita(noh);
  
    if (Dif < -1 && c > noh->dir->chave)
        return rotacaoEsquerda(noh);
  
    if (Dif > 1 && c > noh->esq->chave){
        noh->esq = rotacaoEsquerda(noh->esq);
        return rotacaoDireita(noh);
    }
  
    if (Dif < -1 && c < noh->dir->chave){
        noh->dir = rotacaoDireita(noh->dir);
        return rotacaoEsquerda(noh);
    }  
  
    return noh;
}

Noh* procurar(DicAVL &D, TC c) {
	Noh* noh = D.raiz;

	while( noh != nullptr ) {
		if( c == noh->chave ) return noh;

		if( (c > noh->chave) ) noh = noh->dir;
		else noh = noh->esq;
	}

	return nullptr;
}

void remover(DicAVL &D, Noh* n) {
	D.raiz = removerNoh(D.raiz, n->chave);
}

Noh* removerNoh(Noh* noh, int chave){
	if(noh == nullptr) return noh;

	if(chave < noh->chave)
		noh->esq = removerNoh(noh->esq, chave);
	else if(chave > noh->chave)
		noh->dir = removerNoh(noh->dir, chave);
	else {
		if((noh->dir == nullptr) || (noh->esq == nullptr)){
			Noh* filho = (noh->esq == nullptr ? noh->dir : noh->esq);
			Noh* pai = noh->pai;

			if(filho == nullptr){
				std::cout << "caso 1" << std::endl;
				if(pai->esq == noh) pai->esq = nullptr;
				else pai->dir = nullptr;

				delete noh;

				noh = nullptr;

				return consertar(noh);
			} else {
				std::cout << "caso 2" << std::endl;
				if(pai->esq == noh) pai->esq = filho;
				else pai->dir = filho;
				
				filho->pai = pai;

				delete noh;

				noh = filho;

				return consertar(noh);
			}
			delete filho;
		} else {
			std::cout << "caso 3" << std::endl;
			Noh* menor = menorNoh(noh->dir);

			/*noh->chave = menor->chave;

			noh->dir = removerNoh(noh->dir, menor->chave);*/

			if(menor->pai != noh) menor->pai->esq = nullptr;

			Noh* pai = noh->pai;
			Noh* esq = noh->esq;
			Noh* dir = noh->dir;

			esq->pai = menor;
			menor->esq = esq;

			if(menor->pai != noh) {
				dir->pai = menor;
				menor->dir = dir;
			}

			menor->pai = pai;

			if(pai->dir == noh) pai->dir = menor;
			else pai->esq = menor;

			delete noh;

			noh = menor;

			return consertar(noh);
		}
	}
}

Noh* consertar(Noh* noh){
	if(noh == nullptr) return noh;

	noh->h = maiorSubAltura(noh) + 1;

	int Dif = dif(noh);

	if((Dif > 1) && (dif(noh->esq) >= 0)) return rotacaoDireita(noh);

	if((Dif > 1) && (dif(noh->esq) < 0)){
		noh->esq = rotacaoEsquerda(noh->esq);
		return rotacaoDireita(noh);
	}

	if((Dif < -1) && (dif(noh->dir) <= 0)) return rotacaoEsquerda(noh);

	if((Dif < -1) && (dif(noh->dir) > 0)){
		noh->dir = rotacaoDireita(noh->dir);
		return rotacaoEsquerda(noh);
	}

	return noh;
}

Noh* menorNoh(Noh* noh){
	if(noh->esq == nullptr) return noh;

	return menorNoh(noh->esq);
}

Noh* sucessor(Noh* noh){
	if(noh->dir != nullptr) return menorNoh(noh->dir);

	Noh* y = noh->pai;

	while( ( y != nullptr ) && ( noh == y->dir ) ){
		noh = y;
		y = noh->pai;
	}

	return y;
}

void terminar(DicAVL &D) {

}

Noh* rotacaoDireita(Noh* y) {
	Noh* x = y->esq;
    x->pai = y->pai;
    y->esq = x->dir;
 
    if (y->esq != NULL)
        y->esq->pai = y;
 
    x->dir = y;
    y->pai = x;
 
    if (x->pai != NULL) {
        if (x->pai->dir == y) {
            x->pai->dir = x;
        }
        else {
            x->pai->esq = x;
        }
    }
 
    y->h = maiorSubAltura(y) + 1;
    
    x->h = maiorSubAltura(x) + 1;

    return x;
}

Noh* rotacaoEsquerda(Noh* x) {
	Noh* y = x->dir;
    y->pai = x->pai;
    x->dir = y->esq;
 
    if (x->dir != NULL)
        x->esq->pai = x;
 
    y->esq = x;
    x->pai = y;
 
    if (y->pai != NULL) {
        if (y->pai->esq == x) {
            y->pai->esq = y;
        }
        else {
            y->pai->dir = y;
        }
    }
 
    x->h = maiorSubAltura(x) + 1;
    
    y->h = maiorSubAltura(y) + 1;

    return y;
}

int dif(Noh* noh) {
	int esq = 0;
	int dir = 0;

	if( noh->esq != nullptr ) esq = noh->esq->h;

	if( noh->dir != nullptr ) dir = noh->dir->h;

	return esq - dir;
}

int maiorSubAltura(Noh* pai) {
	int esq = 0;
	int dir = 0;

	if( pai->esq != nullptr ) esq = pai->esq->h;

	if( pai->dir != nullptr ) esq = pai->dir->h;

	return esq > dir ? esq : dir;	
}

void print(Noh* n) {
	std::cout << n->chave << std::endl;

	if( n->esq != nullptr )
		print( n->esq );
	
	if( n->dir != nullptr )
		print( n->dir );
}
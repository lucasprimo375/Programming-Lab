#include <cmath>
#include <iostream>

#include "avl.hpp"

void inicializar(DicAVL &D) {
	D.raiz = nullptr;
}

Noh* inserir(DicAVL &D, TC c, TV v) {
	Noh* novoNoh = new Noh();
	novoNoh->esq = nullptr;
	novoNoh->dir = nullptr;
	novoNoh->pai = nullptr;
	novoNoh->h = 1;
	novoNoh->chave = c;
	novoNoh->valor = v;

	if( D.raiz == nullptr ) {
		D.raiz = novoNoh;

		return novoNoh;
	}

	Noh* noh = D.raiz;
	Noh* pai = nullptr;
	bool dir;

	while( noh != nullptr ) {
		if( c == noh->chave ) return nullptr;

		pai = noh;

		if( (c > noh->chave) ) {
			dir = true;
			noh = noh->dir;
		} else {
			dir = false;
			noh = noh->esq;
		}
	}

	novoNoh->pai = pai;

	if( novoNoh->chave > pai->chave ) pai->dir = novoNoh;
	else pai->esq = novoNoh;

	Noh* z = pai;

	while( z != nullptr ) {
		z->h = maiorSubAltura(z) + 1;

		int Dif = dif(z);

		bool x = true;

		if (Dif > 1 && c < z->esq->chave){
			x = false;
			z = rotacaoDireita(z);
		}
  
	    if (Dif < -1 && c > z->dir->chave) {
	    	x = false;
			z = rotacaoEsquerda(z);
	    }
	  
	    if(Dif > 1 && c > z->esq->chave) {
	    	x = false;
	        z->esq = rotacaoEsquerda(z->esq);  
      		z = rotacaoDireita(z);
	    }  
	  
	    if(Dif < -1 && c < z->dir->chave) {
	    	x = false;
	        z->dir = rotacaoDireita(z->dir);  
	        z = rotacaoEsquerda(z);  
	    }

	    if(x)
	    	z = z->pai;
	    // else std::cout << "mode: " << std::endl;

	}

	return novoNoh;
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

}

void terminar(DicAVL &D) {

}

Noh* rotacaoDireita(Noh* x) {
	Noh *y = x->esq;  
    Noh *z = y->dir;  
  
    y->dir = x;  
    x->esq = z;  
  
    x->h = maiorSubAltura(x) + 1;
    y->h = maiorSubAltura(y) + 1;  
  
    return y;  
}

Noh* rotacaoEsquerda(Noh* x) {
	Noh *y = x->dir;  
    Noh *z = y->esq;  
  
    y->esq = x;  
    x->dir = z;  
  
    x->h = maiorSubAltura(x) + 1;
    y->h = maiorSubAltura(y) + 1;  
  
    return y;  
}

int dif(Noh* pai) {
	int esq = 0;
	int dir = 0;

	if( pai->esq != nullptr ) esq = pai->esq->h;

	if( pai->dir != nullptr ) dir = pai->dir->h;

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
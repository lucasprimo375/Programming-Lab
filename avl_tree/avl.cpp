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

}

void terminar(DicAVL &D) {

}

Noh* rotacaoDireita(Noh* y) {
	Noh *x = y->esq;  
    Noh *z = x->dir;  
  
    x->dir = y;  
    y->esq = z;  
  
    y->h = maiorSubAltura(y) + 1;  
    x->h = maiorSubAltura(x) + 1;  
  
    return x;
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
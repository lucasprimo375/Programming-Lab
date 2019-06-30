#ifndef AVL_HPP
#define AVL_HPP

typedef double TC;
typedef float TV;

struct Noh {
	TC chave;
	TV valor;
	Noh* esq;
	Noh* dir;
	Noh* pai;
	int h;
};

struct DicAVL {
	Noh* raiz;
};

void inicializar(DicAVL &D);

Noh* inserir(DicAVL &D, TC c, TV v);

Noh* inserirNoh(Noh* noh, Noh* pai, TC c, TV v, Noh** n);

Noh* procurar(DicAVL &D, TC c);

void remover(DicAVL &D, Noh* n);

void terminar(DicAVL &D);

Noh* rotacaoDireita(Noh* y);

Noh* rotacaoEsquerda(Noh* x);

int dif(Noh* noh);

int maiorSubAltura(Noh* pai);

void print(Noh* n);

#endif
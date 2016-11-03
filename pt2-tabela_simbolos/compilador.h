#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABB_interface.h"

#define INT 1
#define STRING 2


typedef struct Desc{
	struct Lista *inicio, *lista;
}Descritor;

typedef struct Atributo{
	char nomeId[20];
	Descritor *l;
	int tipo, valor;
}Atributo;

typedef struct Lista{
	char nomeId[20];
	struct Lista *prox;
}Lista;

typedef struct Simbolo{
	int tipo, posicao;
	char nomeId[20];
}Simbolo;

typedef struct No{
	struct Simbolo *dados;
	struct No *esquerda, *direita;
}No;

/*********************************/
/**********Funcoes Lista**********/
int consulta(Descritor *l, char x[20]);
int insere(Descritor **l, char x[20]);
void imprime(Descritor *l);

/**********Funcoes Arvore*********/
void insereArvore(Descritor *l, int tipo);

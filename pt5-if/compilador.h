#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABB_interface.h"

#define INT 1
#define STRING 2

#define ICONST_0 1000
#define ICONST_1 1001
#define ICONST_2 1002
#define ICONST_3 1003
#define ICONST_4 1004
#define ICONST_5 1005
#define ICONST_M1 1006

#define BIPUSH 999
#define ILOAD 998
#define ISTORE 997
#define IADD 996
#define IMUL 995
#define IDIV 994
#define ISUB 993
#define NEG 992
#define INC 991
#define LDC 990
#define CONST 100

#define IINVOKE 989
#define IGETSTATIC 988
#define JINVOKE 987
#define SINV 986
#define IICMPEQ 985
#define IICMPNE 984
#define IICMPLT 983
#define IICMPLE 982
#define IICMPGT 981
#define IICMPGE 980
#define IGOTO 979
#define SINVLN  978

typedef struct Desc{
	struct Lista *inicio, *lista;
}Descritor;

typedef struct Atributo{
	char nomeId[20];
	Descritor *l;
	int tipo, valor, label;
	char *literal;
	struct l_lista *listaV, *listaF;
}Atributo;

typedef struct Lista{
	char nomeId[20];
	struct Lista *prox;
}Lista;

struct l_lista{
	int elemento;
	struct l_lista *prox, *anterior;
}l_lista;

typedef struct Simbolo{
	int tipo, posicao;
	char nomeId[20];
}Simbolo;

typedef struct No{
	struct Simbolo *dados;
	struct No *esquerda, *direita;
}No;

typedef struct Instrucao{
	int label, inst, op1, op2;
	char str[100];
}Instrucao;

/*********************************/
/**********Funcoes Lista**********/
int consulta(Descritor *l, char x[20]);
int insere(Descritor **l, char x[20]);
void imprime(Descritor *l);

/**********Funcoes Arvore*********/
void insereArvore(Descritor *l, int tipo);
void imprimeAuxArvore();

/**********Funcoes Instrucao*********/
void imprimeVetorInstrucao();
int buscaSimb(Atributo* varSimbolo);
void adicionarInstrucao(int instrucao, int n);
void inserirVetorInst(int inst, int label, int op1, int op2);
void inserirInstLit(int x, char *literal);

void corrigir(struct l_lista *l1, int a);
void criaLista(struct l_lista **dest, int v);
int proxInst();
int novoLabel();

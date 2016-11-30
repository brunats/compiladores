# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include"ABB_interface.h"

#define INT 0
#define STRING 1

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
#define ISUB 995
#define IMUL 994
#define IDIV 993
#define INEG 992
#define LDC 991
#define IINV 990
#define IGET 989
#define SINV 988
#define IICMPEQ 987
#define IICMPNE 986
#define IICMPLT 985
#define IICMPLE 984
#define IICMPGT 983
#define IICMPGE 982
#define IGOTO 981
#define SINVLN  980
#define CONST 2



typedef struct Desc{
	struct Lista *inicio;
	struct Lista *lista;
}Descritor;

typedef struct Instrucao{
	int label, inst, op1, op2 ;
	char *str;
}Instrucao;

typedef struct Atributo{
	char nomeId[20];
	Descritor *l;
	int tipo;
	int valor;
	char *lit;
	int label;
	struct llista *listaV, *listaF;
}Atributo;

typedef struct Lista{
   char nomeId[20];
   struct Lista *prox;
}Lista;


typedef struct Simbolo{
	int tipo;
	char nomeId[20];
	int posicao;
}Simbolo;

struct llista{
	int element;
	struct llista *prox;
	struct llista *anterior;
} llista;

typedef struct No{
    struct Simbolo *dados;
    struct No *esquerda;
    struct No *direita;
}No;

void imprimeVetInstrucao(char nome[100]);
int frameFind(Atributo* varSimbolo);
void adicionarInstrucao(int instrucao, int n);
int novoLabel();
void corrigir(struct llista *l1 , int etiqueta);
void merge(struct llista **destino,struct llista *l1 ,struct llista *l2);

//Funcoes da lista
int consulta(Descritor *l, char x[20]);
int insere(Descritor **l, char x[20]);
void imprime(Descritor *l);

//Funcoes da Arvore
void insereArvore(Descritor *l,int tipo);


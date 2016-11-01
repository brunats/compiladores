#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUCESSO 1
#define FRACASSO 0
#define MAIOR 1
#define MENOR -1
#define IGUAL 0
#define SIM 1
#define NAO 0

typedef struct ABB *pABB,**ppABB;

int criaABB(ppABB pp,int tamInfo);
int insereABB(pABB p,void *novo,int(*comparaElemElem)(void *k,void *e));
int removeABB(pABB p,void *chave,int (*comparaChaveElem)(void *e1,void *e2));
int buscaABB(pABB p,void *chave,void *destino,int (*comparaChaveElem)(void *e1,void *e2));
int buscaRaizABB(pABB p);
int alturaABB(pABB p);
int testaVaziaABB(pABB p);
void reiniciaABB(pABB p);
void destroiABB(ppABB pp);
void imprimeArvore(pABB p,void(*imprimeNo)(void* no));

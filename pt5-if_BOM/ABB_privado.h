#include <stdlib.h>
typedef struct noABB
{
    struct noABB *dir;
    struct noABB *esq;
    void *dados;
}NoABB,*pNoABB;

typedef struct ABB
{
    int tamInfo;
    pNoABB raiz;
}ABB;

int auxReinicia(pNoABB p);

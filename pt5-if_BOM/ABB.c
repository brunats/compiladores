#include "ABB_privado.h"
#include "ABB_interface.h"
/******************************************************************************************/
int criaABB(ppABB pp,int tamInfo)
{
    (*pp) = (pABB )malloc(sizeof(ABB));
    if((*pp) == NULL)
     return FRACASSO;
    (*pp)->tamInfo = tamInfo;
    (*pp)->raiz = NULL;
    return SUCESSO;
}
/*******************************************************************************************/
int buscaABB(pABB p,void *chave,void *destino,int(*comparaChaveElem)(void *k,void *e))
{
    pNoABB aux;
    if(p == NULL) /*se a árvore não foi criada*/
     return FRACASSO;
     if(testaVaziaABB(p) == SIM) /*se a árvore estiver vazia*/
       return FRACASSO;
       aux = p->raiz;
       while(aux != NULL && comparaChaveElem(chave,aux->dados) != IGUAL)
       {
           if(comparaChaveElem(chave,aux->dados) == MENOR)
           {
               aux = aux->esq;
           }
           else aux = aux->dir;
       }
       if(aux == NULL) /*não encontrado*/
       return FRACASSO;
       memcpy(destino,aux->dados,p->tamInfo);
       return SUCESSO;
}
/********************************************************************************************/
int insereABB(pABB p,void *novo,int(*comparaElemElem)(void *e1,void *e2))
{
    pNoABB ant = NULL, aux = NULL;
    if(p == NULL) /*se a árvore não foi criada*/
     return FRACASSO;
     aux = p->raiz;
     while(aux != NULL)
     {
         ant = aux;
         if(comparaElemElem(novo,aux->dados) == MAIOR)
         aux = aux->dir;
         else if(comparaElemElem(novo,aux->dados) == MENOR)
         aux = aux->esq;
         else if(comparaElemElem(novo,aux->dados) == IGUAL)
         {
             printf("\n!!!ERRO Chave igual!!!\nEsta chave ja foi inserida!\n");
             return FRACASSO;
         }
     }
    aux = (pNoABB )malloc(sizeof(NoABB));
    if(aux == NULL) return FRACASSO;
    aux->dados = malloc(p->tamInfo);
    if(aux->dados == NULL)
    {
        free(aux);  aux = NULL;
        return FRACASSO;
    }
    memcpy(aux->dados,novo,p->tamInfo);
    aux->esq = NULL;
    aux->dir = NULL;
    if(ant != NULL) /*se for inserir a folha da árvore*/
    {
        if(comparaElemElem(novo,ant->dados) == MAIOR)
         ant->dir = aux;
        else if(comparaElemElem(novo,ant->dados) == MENOR)
         ant->esq = aux;
      return SUCESSO;
    }
    else /*se a árvore estiver vázia*/
    p->raiz = aux;
  return SUCESSO;
}
/******************************************************************************************/
int removeABB(pABB p,void *chave,int(*comparaChaveElem)(void *k,void *e))
{
    /*Remoção:
    casos:
    1) Remoção de um nó sem filhos
    2) Remoção de um nó com um único filho(esquerdo ou direito)
    3) Remoção de um nó com dois filhos substituído pelo nó Sucessor(ou Antecessor) vem
       vem na sequência da ordenação.
    */
    pNoABB aux,ant,suc,pai_suc,x;
    ant = NULL;
    if(p == NULL) /*se a árvore não foi criada*/
      return FRACASSO;
      if(testaVaziaABB(p) == SIM) /*se a árvore estiver vazia*/
         return FRACASSO;
         aux = p->raiz;
         while(aux != NULL && comparaChaveElem(chave,aux->dados) != IGUAL)
         {
             ant = aux;
             if(comparaChaveElem(chave,aux->dados) == MENOR)
                aux = aux->esq;
                else  aux = aux->dir;
         }
         if(aux == NULL) /*não encontrou*/
            return FRACASSO;
            if(aux->esq == NULL && aux ->dir == NULL) /*caso 1*/
            {
                if(ant == NULL)
                  p->raiz = NULL;
                  else
                  {
                      if(comparaChaveElem(chave,ant->dados) == MENOR)
                      {
                        ant->esq = NULL;
                      }
                      else  ant->dir = NULL;
                  }
            }
            else if(aux->esq == NULL || aux->dir == NULL) /*caso 2*/
            {
                if(ant == NULL) /*remoção da raiz*/
                {
                    if(aux->esq == NULL)
                       p->raiz = aux->dir;
                    else   p->raiz = aux->esq;
                }
                else
                {
                    if(aux->esq == NULL)
                       x = aux->dir;
                    else  x = aux->esq;
                    if(ant->esq == aux)
                       ant->esq = x;
                    else ant->dir = x;
                }
            }
            else /*caso 3*/
            {
                suc = aux->dir;
                pai_suc = aux;
                while(suc->esq != NULL)
                {
                    pai_suc = suc;
                    suc = suc->esq;
                }
                pai_suc->esq = suc->dir;
                suc->esq = aux->esq;
                suc->dir = aux->dir;
                if(ant == NULL) /*remoção da raiz com dois filhos*/
                {
                    p->raiz = suc;
                }
                else
                {
                  if(ant->esq == aux)
                    ant->esq = suc;
                    else  ant->dir = suc;
                }
            }
            free(aux->dados);
            free(aux);
            return SUCESSO;
}
/******************************************************************************************/
int testaVaziaABB(pABB p)
{
    if(p->raiz == NULL)
     return SIM;
     else
      return NAO;
}
/******************************************************************************************/
void reiniciaABB(pABB p)
{
    auxReinicia(p->raiz);
    p->raiz = NULL;
}
/******************************************************************************************/
int auxReinicia(pNoABB p)
{
    if(p != NULL)
    {
        auxReinicia(p->esq);
        auxReinicia(p->dir);
        free(p->dados);
        free(p);
    }
    else
    return FRACASSO;
}
/******************************************************************************************/
void destroiABB(ppABB pp)
{
    reiniciaABB(*pp);
    free(*pp);
    *pp = NULL;
}
/*****************************************************************************************/
void exibirPreOrdem(pNoABB pRaiz, void (*imprimeNo)(void* no)){
    if(pRaiz != NULL){
        imprimeNo(pRaiz->dados);
        exibirPreOrdem(pRaiz->esq,imprimeNo);
        exibirPreOrdem(pRaiz->dir,imprimeNo);
    }
}
void imprimeArvore(pABB p,void(*imprimeNo)(void* no)){
    if( p!= NULL){
        printf("\nId\tPosicao\tTipo\t\n");
        exibirPreOrdem(p->raiz,imprimeNo);
	}
}



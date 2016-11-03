#include "compilador.h"

pABB tabela;
int flag_tabela = 0;
int posId = 0;

/*********************************/
int compara(void *e1, void *e2){
	Simbolo *v1, *v2;
	v1 = (Simbolo *)e1;
	v2 = (Simbolo *)e2;

	if(strcmp(v1->nomeId, v2->nomeId) > 0)
		return MAIOR;
	else{
		if(strcmp(v1->nomeId, v2->nomeId) < 0)
			return MENOR;
		else
			return IGUAL;
	}
}
void imprimeNo(void *info){
	Simbolo *aux;
	aux = (Simbolo *)info;
	printf("\n%s\t%i\t%i", aux->nomeId, aux->posicao, aux->tipo);
}

void imprimeAuxArvore(){
	imprimeArvore(tabela, imprimeNo);
}

void insereArvore(Descritor *l, int tipo){
	Simbolo* s;
	struct Lista* aux;
	//tabela vazia
	if(!flag_tabela){
		criaABB(&tabela, sizeof(Simbolo));
		flag_tabela++;
	}
	aux = l->inicio;
	while(aux!=NULL){
		s = (Simbolo *)malloc(sizeof(Simbolo));

		s->posicao = posId;
		s->tipo = tipo;
		strcpy(s->nomeId, aux->nomeId);
		
		posId++;
		if(insereABB(tabela, s, compara) == FRACASSO)
			printf("\nl:%i | Variavel '%s' jah declarada.", cont_lin, s->nomeId);
		aux = aux->prox;
		
	}
}

int consulta(Descritor *l, char x[20]){
	Lista *p;
	p = l->inicio;
	while(strcmp(p->nomeId, x)!=0){
		if(p == l->lista)
			return 0; //achou
		p=p->prox;
	}
	return 1;//nao achou
}

void liberar(Descritor **l){
	Lista *aux;
	while((*l)->inicio != NULL){
		aux = (*l)->inicio;
		(*l)->inicio = aux->prox;
		free(aux);
	}
	free((*l)->inicio);
	*l = NULL;
}

int insere(Descritor **l, char x[20]){
	Lista *p;

	p=((Lista *)malloc(sizeof(Lista)));
	p->prox = NULL;
	strncpy(p->nomeId, x, 20*sizeof(char));
	if( (*l) == NULL){ //lista vazia, cria e add
		(*l) = (Descritor *)malloc(sizeof(Descritor));
		(*l)->inicio = p;
		(*l)->lista = p;
	}else{ //lista nao vazia
		//procura se ja existe
		if(consulta(*l, x) == 1){
			printf("Id jah inserido.\n");
			return -1;
		}
		(*l)->lista->prox = p;
		(*l)->lista = p;
	}
}

void imprime(Descritor *l){
	Lista *p;
	p = l->inicio;
	printf("\nLista:\n");
	while(p!=NULL){
		printf("%s\n",p->nomeId);
		p = p->prox;
	}
	printf("----------------------\n");
}
/*
int main(){
	Descritor *l = NULL;
	char teste[20];
	Atributo *a;

	strcpy(teste, "var_1");
	insere(&l, teste);

	strcpy(teste, "var_2");
	insere(&l, teste);

	strcpy(teste, "var_3");
	insere(&l, teste);

	imprime(l);
	a = (Atributo *)malloc(sizeof(Atributo));
	strcpy(a->nomeId, "Teste_Var");
	a->tipo = STRING;
	a->l = l;
	a->valor = 0;
	insereArvore(a->l,0);

    imprimeAuxArvore();
	liberar(&l);

	strcpy(teste, "var_1.1");
	insere(&l, teste);

	strcpy(teste, "var_2.1");
	insere(&l, teste);

	strcpy(teste, "var_3.1");
	insere(&l, teste);
	imprime(l);
    
    strcpy(a->nomeId, "Teste_Var");
	a->tipo = STRING;
	a->l = l;
	a->valor = 0;
	insereArvore(a->l,0);

    insereArvore(a->l,0);

   	imprimeAuxArvore();
	return 0;
}
*/
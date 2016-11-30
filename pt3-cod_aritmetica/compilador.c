#include "compilador.h"

pABB tabela;
int flag_tabela = 0;
int posId = 0;
Instrucao vetInst[1000];
int c_inst = 0;

/*****************************************************************************/
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
			printf("Variavel '%s' jah declarada.", s->nomeId);
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

void inserirVetorInst(int inst, int label, int op1, int op2){
	vetInst[c_inst].inst = inst;
	vetInst[c_inst].label = label;
	vetInst[c_inst].op1 = op1;
	vetInst[c_inst].op2 = op2;
	c_inst++;
}

void imprimeVetorInstrucao(){
	int i=0;
	FILE *arq;
	arq = fopen("java.txt", "w+");
	while(i<c_inst){
		switch(vetInst[i].inst){
			case BIPUSH:
				fprintf(arq,"bipush %d\n",vetInst[i].op1); 
				break;
			case ILOAD:
				fprintf(arq,"iload %d\n",vetInst[i].op1); 
				break;
			case ISTORE:
				fprintf(arq,"iload %d\n",vetInst[i].op1);
				break;
			case IADD:
				fprintf(arq, "iadd\n"); 
				break;
			case IMUL:
				fprintf(arq, "imul\n");
				break;
			case IDIV:
				fprintf(arq, "idiv\n");
				break;
			case ISUB:
				fprintf(arq, "isub\n");
				break;
			case ICONST_0:
				fprintf(arq, "iconst_0\n");
				break;
			case ICONST_1: 
				fprintf(arq, "iconst_1\n");
				break;
			case ICONST_2:
				fprintf(arq, "iconst_2\n");
				break;
			case ICONST_3:
				fprintf(arq, "iconst_3\n");
				break;
			case ICONST_4:
				fprintf(arq, "iconst_4\n");
				break;	
			case ICONST_5:
				fprintf(arq, "iconst_5\n");
				break;
			case ICONST_M1:
				fprintf(arq, "iconst_m1\n");
				break;
		}
		i++;
	}
	fclose(arq);
}

int buscaSimb(Atributo* a){
	Simbolo *tmp, *aux;
	tmp = (Simbolo *)malloc(sizeof(Simbolo));
	aux = (Simbolo *)malloc(sizeof(Simbolo));

	strcpy(aux->nomeId, a->nomeId);
	buscaABB(tabela, aux, tmp, compara);
	return tmp->posicao;
}

void adicionarInstrucao(int i, int n){
	switch(i){
		case CONST:
			switch(n){
				case -1:
					inserirVetorInst(ICONST_M1, -1, -1, -1);
					break;
				case 0:
					inserirVetorInst(ICONST_0, -1, -1, -1);
					break;
				case 1:
					inserirVetorInst(ICONST_1, -1, -1, -1);
					break;
				case 2:
					inserirVetorInst(ICONST_2, -1, -1, -1);
					break;
				case 3:
					inserirVetorInst(ICONST_3, -1, -1, -1);
					break;
				case 4:
					inserirVetorInst(ICONST_4, -1, -1, -1);
					break;
				case 5:
					inserirVetorInst(ICONST_5, -1, -1, -1);
					break;
				default:
					if( (n > -128) && (n < 127))
						inserirVetorInst(BIPUSH, -1, n, -1);
					else
						inserirVetorInst(LDC, -1, n, -1);
					break;
				}
			break;
		case ILOAD:
			inserirVetorInst(ILOAD, -1, n, -1);
			break;
		case ISTORE:
			inserirVetorInst(ISTORE, -1, n, -1);
			break;
		case IMUL:
			inserirVetorInst(IMUL, -1, n, -1);
			break;
		case IDIV:
			inserirVetorInst(IDIV, -1, n, -1);
			break;
		case INC:
			inserirVetorInst(INC, -1, n, -1);
			break;
		case IADD:
			inserirVetorInst(IADD, -1, -1, -1);
			break;
		case ISUB:
			inserirVetorInst(ISUB, -1, -1, -1);
			break;
	}
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
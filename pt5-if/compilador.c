#include "compilador.h"

pABB tabela;
int flag_tabela = 0;
int posId = 0;
Instrucao vetInst[1000];
int c_inst = 0;
int c_label = 1;

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

int novoLabel(){
	int x;
	vetInst[c_inst-1].label = c_label;
	x = c_label;
	c_label++;
	return x;
}

int proxInst(){
	return c_inst+1;
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
	printf("----------------------\n");
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

void inserirInstLit(int x, char *literal){
	printf("\n%s\n\n",literal);
	vetInst[c_inst].inst = x;
	vetInst[c_inst].label = -1;
	vetInst[c_inst].op1 = -1;
	vetInst[c_inst].op2 = -1;
	vetInst[c_inst].str = malloc(strlen(literal)*sizeof(char));
	strcpy(vetInstrucoes[c_inst].str,literal);
	c_inst++;
}

void imprimeVetorInstrucao(){
	int i=0;
	FILE *arq;
	arq = fopen("java.txt", "w+");
	fprintf(arq,".class public %s\n",strtok(string,"."));
	fprintf(arq,".super java/lang/Object\n\n
					.method public <init>()V\n
					   aload_0\n
					   invokenonvirtual java/lang/Object/<init>()V\n
					   return\n   
					.end method\n\n
					.method public static main([Ljava/lang/String;)V\n
					   .limit stack 8\n
					   .limit locals %d\n",posID*1);
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
			case IINVOKE: 
				fprintf(arq, "   invokevirtual java/io/PrintStream/print(I)V\n"); 
				break;
			case JINVOKE: 
				fprintf(arq, "   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
				break;
			case IGETSTATIC: 
				fprintf(arq, "   getstatic java/lang/System/out Ljava/io/PrintStream;\n");
				break;
			case IINV:
				fprintf(arq, "   invokevirtual java/io/PrintStream/print(I)V\n"); 
				break;
			case SINV:
				fprintf(arq, "   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n"); 
				break;
			case IGET:
				fprintf(arq, "   getstatic java/lang/System/out Ljava/io/PrintStream;\n"); 
				break;
			case IICMPEQ :
				fprintf(arq,"   if_icmpeq l%d\n",vetInstrucoes[i].op1); 
				break;
			case IICMPNE :
				fprintf(arq,"   if_icmpne l%d\n",vetInstrucoes[i].op1); 
				break;
			case IICMPLT :
				fprintf(arq,"   if_icmplt l%d\n",vetInstrucoes[i].op1); 
				break;
			case IICMPLE :
				fprintf(arq,"   if_icmple l%d\n",vetInstrucoes[i].op1); 
				break;
			case IICMPGT : 
				fprintf(arq,"   if_icmpgt l%d\n",vetInstrucoes[i].op1); 
				break;
			case IICMPGE : 
				fprintf(arq,"   if_icmpge l%d\n",vetInstrucoes[i].op1); 
				break;
			case IGOTO :
				fprintf(arq,"   goto l%d\n",vetInstrucoes[i].op1); 
				break;
		}
		if (vetInstrucoes[i].label != -1){
			fprintf(arq, "l%d:\n",vetInstrucoes[i].label);
		}
		i++;
	}
	fprintf(arq, "\nreturn\n.end method");
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
			inserirVetorInst(ILOAD, -1, n, -1);	break;
		case ISTORE:
			inserirVetorInst(ISTORE, -1, n, -1); break;
		case IMUL:
			inserirVetorInst(IMUL, -1, n, -1); break;
		case IDIV:
			inserirVetorInst(IDIV, -1, n, -1); break;
		case INC:
			inserirVetorInst(INC, -1, n, -1); break;
		case IADD:
			inserirVetorInst(IADD, -1, -1, -1); break;
		case ISUB:
			inserirVetorInst(ISUB, -1, -1, -1);	break;
		case IINVOKE:
			inserirVetorInst(IINVOKE,-1,-1,-1);	break;
		case IGETSTATIC:
			inserirVetorInst(IGETSTATIC,-1,-1,-1); break;
		case JINVOKE:
			inserirVetorInst(JINVOKE,-1,-1,-1);	break;
		case SINV:
			inserirVetorInst(SINV,-1,-1,-1); break;
		case IICMPEQ : 
			inserirVetorInst(IICMPEQ,-1,-1,-1); break;
		case IICMPNE : 
			inserirVetorInst(IICMPNE,-1,-1,-1); break;
		case IICMPLT : 
			inserirVetorInst(IICMPLT,-1,-1,-1);	break;
		case IICMPLE : 
			inserirVetorInst(IICMPLE,-1,-1,-1); break;
		case IICMPGT : 
			inserirVetorInst(IICMPGT,-1,-1,-1); break;
		case IICMPGE : 
			inserirVetorInst(IICMPGE,-1,-1,-1); break;
		case IGOTO : 
			inserirVetorInst(IGOTO,-1,n,-1); break; 
	}
}

void criaLista(struct l_lista **dest, int v){
	struct l_lista temp;
	temp.prox = NULL;
	temp.anterior = NULL;
	temp.elemento = valor;
	if((*destino) == NULL){
		*destino = (struct l_lista *) malloc sizeof(struct l_lista);
		memcpy(*destino, &temp, sizeof(struct l_lista));
	}
}

void corrigir(struct l_lista *l1, int a){
	while(l1->anterior != NULL)
		l1 = l1->anterior;
	while(l1 != NULL){
		vetInst[l1->elemento-1].op1 = a;
		l1=l1->prox;
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
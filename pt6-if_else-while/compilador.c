#include "compilador.h"

pABB tabela;
int flag_tabela = 0;
int posID = 1;
int contadorInstrucoes = 0;
Instrucao vetInstrucoes[500];
int contLabel = 1;

int novoLabel(){
	int aux ;
	vetInstrucoes[contadorInstrucoes-1].label = contLabel;
	aux = contLabel;
	contLabel++;
	return aux;
}

int proxInst(){	
	return contadorInstrucoes+1;
}

int compara(void *e1,void *e2){
    Simbolo *v1,*v2 ;
    v1 = (Simbolo *)e1;
    v2 = (Simbolo *)e2;

    if(strcmp(v1->nomeId,v2->nomeId) > 0)
        return MAIOR;
    else if(strcmp(v1->nomeId,v2->nomeId) < 0)
        return MENOR;
    else
        return IGUAL;
}

void imprimeNo(void *info){
    Simbolo *aux;
    aux = (Simbolo *)info; 
    printf("\n%s\t%i\t%i",aux->nomeId,aux->posicao,aux->tipo);
    
}
void imprimeAuxArvore(){
	imprimeArvore(tabela,imprimeNo);
}

void insereArvore(Descritor *l,int tipo){
    Simbolo *s;
    Lista *aux;

    if(flag_tabela == 0){
        criaABB(&tabela,sizeof(Simbolo));
        flag_tabela++;
    }

    aux = l->inicio;
    while(aux!=NULL){
        s = (Simbolo *)malloc(sizeof(Simbolo));
        s->posicao = posID;
        s->tipo = tipo;
        strcpy(s->nomeId,aux->nomeId);
        posID++;
	insereABB(tabela,s,compara);
        aux = aux->prox;
        
    }
}

int consulta(Descritor *l, char x[20]){
   Lista *p;

   p = l->inicio;

   while(strcmp(p->nomeId,x)!=0){
	   if (p == l->lista)
			return(0);
		//printf("%scu\n",p->nomeId);
		p = p->prox;

	}


   return (1);
}

void liberar(Descritor **l){
	Lista *aux;
	while((*l)->inicio != NULL ){
		aux = (*l)->inicio;
		
		(*l)->inicio = aux->prox;
		free(aux);
	}
	free((*l)->inicio);
	//free((*l)->lista);
	*l = NULL;
}

int insere(Descritor **l, char x[20]){
   Lista *p;

   p = ((Lista *) malloc (sizeof(Lista)));
   p->prox = NULL;
   strncpy(p->nomeId,x,20*sizeof(char));
   if( (*l) == NULL ){
	   (*l) = (Descritor *)malloc(sizeof(Descritor));
	   (*l)->inicio  = p;
	   (*l)->lista = p;
   }else/* if( (*l)->inicio->prox == NULL){
	  (*l)->inicio->prox = p;
	  (*l)->lista = p;
   }else*/{
	   if(consulta(*l,x)){
		   printf("\nja tem esse id\n");
		   return -1;
	   }
	   (*l)->lista->prox = p;
	   (*l)->lista = p;

   }
}

void imprime(Descritor *l){
   Lista *p;
   p = l->inicio;

   printf("\nImprime:\n");
   while(p!=NULL){
	   printf("%s\n",p->nomeId);
		p = p->prox;
	}
	printf("Fecha imprime.\n");
}

void insereVetInstrucao(int inst, int label, int op1, int op2){
	vetInstrucoes[contadorInstrucoes].inst = inst;
	vetInstrucoes[contadorInstrucoes].label = label;
	vetInstrucoes[contadorInstrucoes].op1 = op1;
	vetInstrucoes[contadorInstrucoes].op2 = op2;
	contadorInstrucoes++;
}
	
int frameFind(Atributo* varSimbolo){
	Simbolo* tmp = (Simbolo*) malloc(sizeof(Simbolo));
	Simbolo* aux = (Simbolo*) malloc(sizeof(Simbolo));

	strcpy(aux->nomeId,varSimbolo->nomeId);

	buscaABB(tabela, aux, tmp, compara);

	return tmp->posicao;
}

void imprimeVetInstrucao(char nome[100]){
	int i=0;
	FILE *arquivo;
	arquivo = fopen("instrucoes.j","w+");
	
	fprintf (arquivo,".class public %s\n",strtok(nome,"."));
	fprintf (arquivo,".super java/lang/Object\n\n");
	fprintf (arquivo,".method public <init>()V\n");
	fprintf (arquivo,"   aload_0\n\n");
	fprintf (arquivo,"   invokenonvirtual java/lang/Object/<init>()V\n");
	fprintf (arquivo,"   return\n");
	fprintf (arquivo,".end method\n\n");
	fprintf (arquivo,".method public static main([Ljava/lang/String;)V\n");
	fprintf (arquivo,"   .limit stack 20\n");
	fprintf (arquivo,"   .limit locals %d\n\n",posID*1);
	for(i;i<contadorInstrucoes;i++){
		switch(vetInstrucoes[i].inst){
			case BIPUSH: fprintf (arquivo,"   bipush %d\n",vetInstrucoes[i].op1) ; break ;
			case LDC: if(vetInstrucoes[i].op1 != -1) fprintf(arquivo, "   ldc %d\n",vetInstrucoes[i].op1);else fprintf(arquivo, "   ldc %s\n",vetInstrucoes[i].str); break;
			case ICONST_M1: fprintf (arquivo,"   iconst_m1\n"); break ;
			case ICONST_0: fprintf (arquivo,"   iconst_0\n"); break ;
			case ICONST_1: fprintf (arquivo,"   iconst_1\n"); break ;
			case ICONST_2: fprintf (arquivo,"   iconst_2\n"); break ;
			case ICONST_3: fprintf (arquivo,"   iconst_3\n"); break ;
			case ICONST_4: fprintf (arquivo,"   iconst_4\n"); break ;
			case ICONST_5: fprintf (arquivo,"   iconst_5\n"); break ;
			case ILOAD: fprintf(arquivo, "   iload %d\n",vetInstrucoes[i].op1); break ;
			case ISTORE: fprintf(arquivo, "   istore %d\n",vetInstrucoes[i].op1); break ;
			case IADD: fprintf(arquivo, "   iadd\n") ; break ;
			case ISUB: fprintf(arquivo, "   isub\n"); break ;
			case IMUL: fprintf(arquivo, "   imul\n"); break ;
			case IDIV: fprintf(arquivo, "   idiv\n"); break ;
			case IINV: fprintf(arquivo, "   invokevirtual java/io/PrintStream/print(I)V\n"); break ;
			case SINV: fprintf(arquivo, "   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n"); break ;
			case IGET: fprintf(arquivo, "   getstatic java/lang/System/out Ljava/io/PrintStream;\n"); break ;
			case IICMPEQ : fprintf(arquivo,"   if_icmpeq l%d\n",vetInstrucoes[i].op1); break;
			case IICMPNE : fprintf(arquivo,"   if_icmpne l%d\n",vetInstrucoes[i].op1); break;
			case IICMPLT : fprintf(arquivo,"   if_icmplt l%d\n",vetInstrucoes[i].op1); break;
			case IICMPLE : fprintf(arquivo,"   if_icmple l%d\n",vetInstrucoes[i].op1); break;
			case IICMPGT : fprintf(arquivo,"   if_icmpgt l%d\n",vetInstrucoes[i].op1); break;
			case IICMPGE : fprintf(arquivo,"   if_icmpge l%d\n",vetInstrucoes[i].op1); break;
			case IGOTO : fprintf(arquivo,"   goto l%d\n",vetInstrucoes[i].op1); break;
			case IINC:	fprintf(arquivo, "   iinc %d +1\n",vetInstrucoes[i].op1); break;
			case IDEC:	fprintf(arquivo, "   iinc %d -1\n",vetInstrucoes[i].op1); break;
		}
		
		if (vetInstrucoes[i].label != -1){
			fprintf(arquivo, "l%d:\n",vetInstrucoes[i].label);
		}
	}	
	fprintf (arquivo,"\nreturn\n");
	fprintf (arquivo,".end method");
	fclose(arquivo);	
	
	printf("------ numero de instrucoes: %d\n", contadorInstrucoes);	
}

void adicionaInstrucaoLiteral(int i, char *lit){
	vetInstrucoes[contadorInstrucoes].inst = i;
	vetInstrucoes[contadorInstrucoes].label = -1;
	vetInstrucoes[contadorInstrucoes].op1 = -1;
	vetInstrucoes[contadorInstrucoes].op2 = -1;
	vetInstrucoes[contadorInstrucoes].str = malloc(strlen(lit)*sizeof(char));
	strcpy(vetInstrucoes[contadorInstrucoes].str,lit);
	contadorInstrucoes++;
}

void adicionarInstrucao(int instrucao, int n){
	switch(instrucao){
		case CONST:
			switch(n){
				case -1: 
					insereVetInstrucao(ICONST_M1,-1,-1,-1);
					break;
				case 0: 
					insereVetInstrucao(ICONST_0,-1,-1,-1);
					break;
				case 1: 
					insereVetInstrucao(ICONST_1,-1,-1,-1);
					break;
				case 2: 
					insereVetInstrucao(ICONST_2,-1,-1,-1);
					break;
				case 3: 
					insereVetInstrucao(ICONST_3,-1,-1,-1);
					break;
				case 4: 
					insereVetInstrucao(ICONST_4,-1,-1,-1);
					break;
				case 5: 
					insereVetInstrucao(ICONST_5,-1,-1,-1);
					break;
				default:
					if(n<127 && n>-128)
						insereVetInstrucao(BIPUSH,-1,n,-1);
					else
						insereVetInstrucao(LDC,-1,n,-1);
					break;
				
				}
			break;
		
		case ILOAD:
			insereVetInstrucao(ILOAD,-1,n,-1);
			break;
		case ISTORE:
			insereVetInstrucao(ISTORE,-1,n,-1);
			break;
		case IADD:
			insereVetInstrucao(IADD,-1,-1,-1);
			break;
		case ISUB:
			insereVetInstrucao(ISUB,-1,-1,-1);
			break;
		case IMUL:
			insereVetInstrucao(IMUL,-1,-1,-1);
			break;
		case IDIV:
			insereVetInstrucao(IDIV,-1,-1,-1);
			break;
		case IINV:
			insereVetInstrucao(IINV,-1,-1,-1);
			break;
		case IGET:
			insereVetInstrucao(IGET,-1,-1,-1);
			break;
		case SINV:
			insereVetInstrucao(SINV,-1,-1,-1);
			break;
		case IICMPEQ : 
			insereVetInstrucao(IICMPEQ,-1,-1,-1); 
			break;
		case IICMPNE : 
			insereVetInstrucao(IICMPNE,-1,-1,-1); 
			break;
		case IICMPLT : 
			insereVetInstrucao(IICMPLT,-1,-1,-1);
			break;
		case IICMPLE : 
			insereVetInstrucao(IICMPLE,-1,-1,-1); 
			break;
		case IICMPGT : 
			insereVetInstrucao(IICMPGT,-1,-1,-1); 
			break;
		case IICMPGE : 
			insereVetInstrucao(IICMPGE,-1,-1,-1); 
			break;
		case IGOTO : 
			insereVetInstrucao(IGOTO,-1,n,-1); 
			break;
		 
		case IDEC:
			insereVetInstrucao(IDEC,-1,n,-1); 
				break; 
	}
}

/*********************************************************************************************************/

void criaLista(struct llista **destino,int valor){
	struct llista temp;
	temp.prox = NULL;
	temp.anterior = NULL;
	temp.element = valor;
	if ((*destino) == NULL){
		*destino = (struct llista *) malloc (sizeof(struct llista));
		memcpy(*destino,&temp,sizeof(struct llista));
	}
}

void corrigir(struct llista *l1 , int etiqueta){
	while (l1->anterior != NULL){
		l1 = l1->anterior;
	}
	while (l1 != NULL){
		vetInstrucoes[l1->element-1].op1 = etiqueta;
		l1 = l1->prox;
	}
}

void merge(struct llista **destino,struct llista *l1 ,struct llista *l2){
	while(l1->anterior != NULL){
		l1 = l1->anterior ;	
	}
	while(l2->anterior != NULL){
		l2 = l2->anterior ;
	}
	int flag,tam = 0;
	struct llista *temp, *aux;
	temp = (struct llista*) malloc (sizeof(struct llista));
	temp->anterior = NULL;
	temp->prox = NULL;
	if (l1->element < l2->element){
		temp->element= l1->element ;
		l1 = l1->prox;
		tam++ ;
	}else{
		temp->element = l2->element ;
		l2 = l2->prox;
		tam++ ;
	}
	while (temp != NULL){
		*destino = (struct llista*) realloc((*destino),tam*sizeof(struct llista)) ;
		memcpy(*destino,temp,sizeof(struct llista));
		if(tam > 1){
			(*destino)->anterior = aux;
			(*destino)->anterior->prox = *destino ;
		}
		if( l1 != NULL && l2 != NULL){
			if(l1->element < l2->element){
				temp->element = l1->element ;
				l1 = l1->prox;
				tam++;
			}else{
				temp->element = l2->element;
				l2 = l2->prox;
				tam++;
			}
		}else{
			if( l1 != NULL){
				temp->element = l1->element;
				l1 = l1->prox;
				tam++; 
			}else{
				if( l2 != NULL){
					temp->element = l2->element;
					l2 = l2->prox;
					tam++;
				}else{
					temp = NULL ;
				}
			}
		}
		aux = (*destino) ;
		if( temp != NULL){	
		*destino = (*destino)->prox ; 
		}  
	}
}
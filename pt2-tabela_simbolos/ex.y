%{
#include <stdio.h>
#include <stdlib.h>
#include "compilador.h"
#define YYSTYPE struct Atributo
%}

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TLIT TID TPVIRG TREAD TPRINT TATR TWHILE TELSE TIF TRET TSTRING TINT TFCHA TACHA TVOID TVIRG TNOT TOR TAND TDIF TIGUAL TMENOR TMAIOR TMAIORIGUAL TMENORIGUAL TPLIN

%%
Programa:	ListaFuncoes BlocoPrincipal
		| BlocoPrincipal
		;

ListaFuncoes:	ListaFuncoes Funcao
		| Funcao
		;

Funcao:		TipoRetorno TID TAPAR DeclParametros TFPAR BlocoPrincipal
		| TipoRetorno TID TAPAR TFPAR BlocoPrincipal
		;

TipoRetorno:	Tipo
		| TVOID
		;

DeclParametros:	DeclParametros TVIRG Parametro
		| Parametro
		;

Parametro:	Tipo TID
		;

BlocoPrincipal:	TACHA Declaracoes ListaCmd TFCHA
		| TACHA ListaCmd TFCHA
		;

Declaracoes:	Declaracoes Declaracao {imprimeAuxArvore();}
		| Declaracao
		;

Declaracao:	Tipo ListaId TPVIRG {insereArvore($2.l, $1.tipo); /*printf("bla declaracao\n");*/}
		;

Tipo:		TINT {$$.tipo = INT;}
		| TSTRING {$$.tipo = STRING;}
		;

ListaId:	ListaId TVIRG TID {insere(&$1.l, $3.nomeId);/*imprime($1.l)*/ $$.l = $1.l;}
		| TID{$$.l = NULL; insere(&$$.l, $1.nomeId);}
		;

Bloco:		TACHA ListaCmd TFCHA
		;

ListaCmd:	ListaCmd Comando
		| Comando
		;

Comando:	CmdSe
		| CmdEnquanto
		| CmdAtrib
		| CmdEscrita
		| CmdLeitura
		| ChamadaFuncao
		| Retorno
		;

Retorno:	TRET ExprAritmetica TPVIRG
		;

CmdSe:		TIF TAPAR ExprLogica TFPAR Bloco
		| TIF TAPAR ExprLogica TFPAR Bloco TELSE Bloco
		;

CmdEnquanto:	TWHILE TAPAR ExprLogica TFPAR Bloco
		;

CmdAtrib:	TID TATR ExprAritmetica TPVIRG
		| TID TATR TLIT TPVIRG
		;

CmdEscrita:	TPRINT TAPAR ExprAritmetica TFPAR TPVIRG
		| TPRINT TAPAR TLIT TFPAR TPVIRG
		;

CmdLeitura:	TREAD TAPAR TID TFPAR TPVIRG
		;

ChamadaFuncao:	TID TAPAR LParametros TFPAR TPVIRG
		| TID TAPAR TFPAR TPVIRG
		;

LParametros:	LParametros TVIRG ExprAritmetica
		| ExprAritmetica
		;
		
ExprAritmetica:	ExprAritmetica TADD Termo
		| ExprAritmetica TSUB Termo
		| Termo
		;

Termo: 		Termo TMUL Fator
		| Termo TDIV Fator
		| Fator
		;

Fator:		TNUM 
		| TID {/*$$.listaId = criarLista($1.nomeId);*/}
		| ChamadaFuncao
		| TAPAR ExprAritmetica TFPAR {/*$$ = $2*/}
		| TSUB Fator
		;

ExprLogica:	RelTermo TAND ExprLogica
		| RelTermo TOR ExprLogica
		| RelTermo
		;

RelTermo:	TNOT RelTermo
		| RelFator
		;

RelFator:	TAPAR ExprLogica TFPAR
		| ExprRelacional
		;

ExprRelacional:	ExprAritmetica TMAIORIGUAL ExprAritmetica
		| ExprAritmetica TMENORIGUAL ExprAritmetica
		| ExprAritmetica TMAIOR ExprAritmetica
		| ExprAritmetica TMENOR ExprAritmetica
		| ExprAritmetica TIGUAL ExprAritmetica
		| ExprAritmetica TDIF ExprAritmetica
		;  
%%
#include "lex.yy.c"

int yyerror (char *str){
	printf("%s - antes %s\n", str, yytext); exit(0);
} 		 

int yywrap(){
	printf("\n\nSintaticamente Correto.\n");
	return 1;
}

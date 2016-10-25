%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TLIT TID TPVIRG TREAD TPRINT TATR TWHILE TELSE TIF TRET TSTRING TINT TFCHA TACHA TVOID TVIRG TNOT TOR TAND TDIF TIGUAL TMENOR TMAIOR TMAIORIGUAL TMENORIGUAL

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

Declaracoes:	Declaracoes Declaracao 
		| Declaracao
		;

Declaracao:	Tipo ListaId TPVIRG
		;

Tipo:		TINT
		| TSTRING
		;

ListaId:	ListaId TVIRG TID
		| TID
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
		| TID
		| ChamadaFuncao
		| TAPAR ExprAritmetica TFPAR
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
	printf("lin :%i %s - antes %s\n", lin, str, yytext);
	exit(0);
} 		 

int yywrap(){
	printf("Sintaticamente Correto.\n");
	return 1;
}

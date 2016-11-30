%{
#include <stdio.h>
#include <stdlib.h>
#include "compilador.h"
#define YYSTYPE struct Atributo

%}

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TFIM TIGUAL TMENORIGUAL TMAIORIGUAL TATRIBUICAO TMENOR TMAIOR TAND TOR TDIF TNOT TID TLIT TVOID TVIRG TACHA TFCHA TINT TSTRING TPVIRG TRET TIF TELSE TWHILE TPRINT TREAD

%%

Programa: ListaFuncoes BlocoPrincipal
	|BlocoPrincipal
	;
ListaFuncoes: ListaFuncoes Funcao
	|Funcao
	;
Funcao: TipoRetorno TID TAPAR DeclParametros TFPAR BlocoPrincipal
	|TipoRetorno TID TAPAR TFPAR BlocoPrincipal
	;
TipoRetorno: Tipo 
	| TVOID
	;
DeclParametros: DeclParametros TVIRG Parametro { }
	|Parametro
	;
Parametro: Tipo TID
	;
BlocoPrincipal: TACHA Declaracoes ListaCmd TFCHA
	|TACHA ListaCmd TFCHA
	;
Declaracoes: Declaracoes Declaracao
	| Declaracao
	;
Declaracao: Tipo ListaId TPVIRG {insereArvore($2.l,$1.tipo);imprimeAuxArvore();/*liberar(&$$.l);*/}
	;
Tipo: TINT {$$.tipo = INT;}
	|TSTRING{$$.tipo = STRING;}
	;
ListaId: ListaId TVIRG TID {insere(&$1.l,$3.nomeId);/*imprime($1.l)*/;$$.l = $1.l;}
	|TID{$$.l = NULL; insere(&$$.l,$1.nomeId);}
	;
Bloco: TACHA ListaCmd TFCHA
	;
ListaCmd: ListaCmd Comando
	|Comando
	;
Comando: CmdSe
	|CmdEnquanto
	|CmdAtrib
	|CmdEscrita
	|CmdLeitura
	|ChamadaProcedimento
	|Retorno
	;
Retorno: TRET ExpressaoAritmetica TPVIRG
	;
CmdSe: TIF TAPAR ExpressaoLogica TFPAR L Bloco {corrigir($3.listaV,$5.label);corrigir($3.listaF,novoLabel());}
	|TIF TAPAR ExpressaoLogica TFPAR L Bloco N TELSE L Bloco
	;
CmdEnquanto: TWHILE TAPAR ExpressaoLogica TFPAR Bloco
	;
CmdAtrib: TID TATRIBUICAO ExpressaoAritmetica TPVIRG {adicionarInstrucao(ISTORE,frameFind(&$1));}
	|TID TATRIBUICAO TLIT TPVIRG
	;
CmdEscrita: TPRINT M TAPAR ExpressaoAritmetica TFPAR TPVIRG {adicionarInstrucao(IINV,-1);}
	|TPRINT M TAPAR TLIT TFPAR TPVIRG {adicionaInstrucaoLiteral(LDC,$4.lit);adicionarInstrucao(SINV,-1);printf("hue");}
	;
M: {adicionarInstrucao(IGET,-1);}
	;
CmdLeitura: TREAD TAPAR TID TFPAR TPVIRG
	;
ChamadaProcedimento: ChamadaFuncao TPVIRG
	;
ChamadaFuncao: TID TAPAR ListaParametros TFPAR
	| TID TAPAR TFPAR
	;
ListaParametros: ListaParametros TVIRG ExpressaoAritmetica
	|ExpressaoAritmetica
	;

ExpressaoLogica: TLogico TAND L ExpressaoLogica {corrigir($1.listaV, $3.label); $$.listaF = NULL; merge(&$$.listaF,$4.listaF,$1.listaF);$$.listaV = $4.listaV;}
		|TLogico TOR L ExpressaoLogica {corrigir($1.listaF, $3.label);$$.listaV = NULL; merge(&$$.listaV,$4.listaV,$1.listaV);$$.listaF = $4.listaF;}
		|TLogico {$$.listaF = $1.listaF ; $$.listaV = $1.listaV;}
		;
		
L: {$$.label = novoLabel();}
	;
N: 
	;

TLogico: TNOT TLogico {$$.listaV = $2.listaF ; $$.listaF = $2.listaV;}
	|TAPAR ExpressaoLogica TFPAR {$$.listaV = $2.listaV ; $$.listaF = $2.listaF;}
	|ExpressaoRelacional{$$.listaV = $1.listaV ; $$.listaF = $1.listaF;}
	;

ExpressaoRelacional: ExpressaoAritmetica TMAIORIGUAL ExpressaoAritmetica {criaLista(&$$.listaV,proxInst());criaLista(&$$.listaF,proxInst()+1);adicionarInstrucao(IICMPGE,-1);adicionarInstrucao(IGOTO,-1);}
	|ExpressaoAritmetica TMENORIGUAL ExpressaoAritmetica {criaLista(&$$.listaV,proxInst());criaLista(&$$.listaF,proxInst()+1);adicionarInstrucao(IICMPLE,-1);adicionarInstrucao(IGOTO,-1);}
	|ExpressaoAritmetica TMAIOR ExpressaoAritmetica {printf("proximas Insts: %d, %d",proxInst(),proxInst()+1);criaLista(&$$.listaV,proxInst());criaLista(&$$.listaF,proxInst()+1);adicionarInstrucao(IICMPGT,-1);adicionarInstrucao(IGOTO,-1);}
	|ExpressaoAritmetica TMENOR ExpressaoAritmetica {criaLista(&$$.listaV,proxInst());criaLista(&$$.listaF,proxInst()+1);adicionarInstrucao(IICMPLT,-1);adicionarInstrucao(IGOTO,-1);}
	|ExpressaoAritmetica TIGUAL ExpressaoAritmetica {criaLista(&$$.listaV,proxInst());criaLista(&$$.listaF,proxInst()+1);adicionarInstrucao(IICMPEQ,-1);adicionarInstrucao(IGOTO,-1);} 
	|ExpressaoAritmetica TDIF ExpressaoAritmetica {criaLista(&$$.listaV,proxInst());criaLista(&$$.listaF,proxInst()+1);adicionarInstrucao(IICMPNE,-1);adicionarInstrucao(IGOTO,-1);}
	;


ExpressaoAritmetica: Expr
	;

Expr: Expr TADD Termo {adicionarInstrucao(IADD,-1);}
	| Expr TSUB Termo {adicionarInstrucao(ISUB,-1);}
	| Termo
	;
Termo: Termo TMUL Fator {adicionarInstrucao(IMUL,-1);}
	| Termo TDIV Fator {adicionarInstrucao(IDIV,-1);}
	| Fator
	;
Fator: TNUM {printf("w%dw",$1.valor);adicionarInstrucao(CONST,$1.valor);printf("e%de",$1.valor);}
	| TAPAR Expr TFPAR //{$$ = $2;}
	| TSUB Fator
	|TID {adicionarInstrucao(ILOAD,frameFind(&$1));}
	|ChamadaFuncao
	;
%%
#include "lex.yy.c"

int yyerror (char *str)
{
	printf("%s - antes %s\n", str, yytext);
	
} 		 

int yywrap()
{
	return 1;
}

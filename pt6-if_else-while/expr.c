#include <stdio.h>
#include <string.h>


extern FILE *yyin;
int main(int argc, char *argv[]){
	yyin = fopen(argv[1],"r+");
	yyparse();
	imprimeVetInstrucao(argv[1]);
	return 0;
}


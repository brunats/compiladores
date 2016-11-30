delim	[ \t]
ws	{delim}+
digito	[0-9]
num	{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
letra	[A-z]
id	({letra}|\_)({digito}|{letra}|\_)*
literal \".*\"

%%
{ws}	{}
"{"	{printf("{");return TACHA;}
"}"	{printf("}");return TFCHA;}
"+"	{printf("+");return TADD;}
"-"	{printf("-");return TSUB;}
"*"	{printf("*");return TMUL;}
"/"	{printf("/");return TDIV;}
"("	{printf("(");return TAPAR;}
")"	{printf(")");return TFPAR;}
"=="	{printf("==");return TIGUAL;}
"<="	{printf("<=");return TMENORIGUAL;}
">="	{printf(">=");return TMAIORIGUAL;}
"="	{printf("=");return TATRIBUICAO;}
"<"	{printf("<");return TMENOR;}
">"	{printf(">");return TMAIOR;}
"&&"	{printf("&&");return TAND;}
"||"	{printf("||");return TOR;}
"!="	{printf("!=");return TDIF;}
"!"	{printf("!");return TNOT;}
","	{printf(",");return TVIRG;}
"int"	{printf("int");return TINT;}
"if"	{printf("if");return TIF;}
"else"	{printf("else");return TELSE;}
"while"	{printf("while");return TWHILE;}
"print"	{printf("Print");return TPRINT;}
"read"	{printf("read");return TREAD;}
"return"	{printf("return");return TRET;}
";"		{printf(";");return TPVIRG;}
"string"	{printf("string");return TSTRING;}
"void"		{printf("void");return TVOID;}
{id}		{strncpy(yylval.nomeId,yytext,20*sizeof(char)); printf("id");return TID;}
{literal}	{yylval.lit = malloc(strlen(yytext)*sizeof(char));strcpy(yylval.lit,yytext);printf("\t literal");return TLIT;}
{num}		{printf("%s",yytext);yylval.valor = atoi(yytext); return TNUM;} 

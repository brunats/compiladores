delim	[ \t\r]
qli [\n]
ws	{delim}+
digito	[0-9]
num	{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
letra	[A-z]
id	({letra}|\_)({digito}|{letra}|\_)*
comLi \\.*{qli}
comBl \/\*.*\*\/
literal \".*\"

%%
{ws}		{}
"{"			{return TACHA;}
"}"			{return TFCHA;}
"++"		{return TINC;}
"+="		{return TATSUM;}
"+"			{return TADD;}
"--"		{return TDEC;}
"-="		{return TATSUB;}
"-"			{return TSUB;}
"*"			{return TMUL;}
"/"			{return TDIV;}
"("			{return TAPAR;}
")"			{return TFPAR;}
"=="		{return TIGUAL;}
"<="		{return TMENORIGUAL;}
">="		{return TMAIORIGUAL;}
"="			{return TATRIBUICAO;}
"<"			{return TMENOR;}
">"			{return TMAIOR;}
"&&"		{return TAND;}
"||"		{return TOR;}
"!="		{return TDIF;}
"!"			{return TNOT;}
","			{return TVIRG;}
"int"		{return TINT;}
"if"		{return TIF;}
"else"		{return TELSE;}
"while"		{return TWHILE;}
"print"		{return TPRINT;}
"read"		{return TREAD;}
"return"	{return TRET;}
";"			{return TPVIRG;}
"string"	{return TSTRING;}
"void"		{return TVOID;}
{id}		{strncpy(yylval.nomeId,yytext,20*sizeof(char)); return TID;}
{literal}	{yylval.lit = malloc(strlen(yytext)*sizeof(char));strcpy(yylval.lit,yytext); return TLIT;}
{num}		{yylval.valor = atoi(yytext); return TNUM;} 
{comLi}		{printf("");}
{comBl}		{printf("comentario bloco aqui");}
{qli}		{}

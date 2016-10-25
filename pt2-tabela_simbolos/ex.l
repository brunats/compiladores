delim	[ \t\n\r]
ws	{delim}+
digito	[0-9]
num	{digito}+(\.{digito}*(E[+-]?{digito}+)?)?
letra	[A-z]
id	{letra}({digito}|{letra})*
literal \".*\"

%%
{ws}		{}
"+"		{return TADD;}
"-"		{return TSUB;}
"*"		{return TMUL;}
"/"		{return TDIV;}
"("		{return TAPAR;}
")"		{return TFPAR;}
">="		{return TMAIORIGUAL;}
"<="		{return TMENORIGUAL;}
">"		{return TMAIOR;}
"<"		{return TMENOR;}
"=="		{return TIGUAL;}
"!="		{return TDIF;}
"&&"		{return TAND;}
"||"		{return TOR;}
"!"		{return TNOT;}
","		{return TVIRG;}
"void"		{return TVOID;}
"{"		{return TACHA;}
"}"		{return TFCHA;}
"int"		{return TINT;}
"string"	{return TSTRING;}
"return"	{return TRET;}
"if"		{return TIF;}
"else"		{return TELSE;}
"while"		{return TWHILE;}
"="		{return TATR;}
"print"		{return TPRINT;}
"read"		{return TREAD;}
";"		{return TPVIRG;}

{id}		{strcpy(yylval.nomeId, yytext); return TID;}
{literal}	{return TLIT;}
{num}		{return TNUM;} 
.		{printf("Erro  -> %s\n", yytext); exit(0);}
%%

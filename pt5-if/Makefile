%.c:%.y
%.c:%.l

all: comp

comp: ex.tab.c expr.c ABB.c
	gcc ex.tab.c expr.c compilador.c ABB.c -o $@

ex.tab.c: lex.yy.c ex.y
	bison ex.y

lex.yy.c: ex.l
	flex ex.l

mrproper: rm -rf ex.tab.c comp lex.yy.c 
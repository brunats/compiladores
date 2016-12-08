%.c:%.y
%.c:%.l

all:comp

comp: expr.tab.c expr.c ABB.c
	gcc expr.tab.c expr.c compilador.c ABB.c -o $@

expr.tab.c: lex.yy.c expr.y
	bison expr.y

lex.yy.c: expr.l
	flex expr.l

clear:
	@rm -f lex.yy.c expr.tab.c comp

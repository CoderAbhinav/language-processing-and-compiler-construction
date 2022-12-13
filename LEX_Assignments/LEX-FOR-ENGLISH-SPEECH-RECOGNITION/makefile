scanner:main.c	scanner_predef.h lex.yy.c
	gcc main.c lex.yy.c -ll -o scanner

lex.yy.c:
	english.l
	lex english.l

clean:
	rm scanner
	rm lex.yy.c
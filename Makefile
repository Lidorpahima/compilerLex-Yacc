parser: parser.tab.c lex.yy.c ast.c
	gcc -o parser parser.tab.c lex.yy.c ast.c -ll

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

lex.yy.c: scanner.l
	flex scanner.l

clean:
	rm -f parser lex.yy.c parser.tab.c parser.tab.h

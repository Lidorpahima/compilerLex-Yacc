CC = gcc
CFLAGS = -Wall -g

OBJECTS = parser.tab.o lex.yy.o ast.o 

compiler: $(OBJECTS)
	$(CC) $(CFLAGS) -o compiler $(OBJECTS)

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c

test: compiler
	./compiler test.code

clean:
	rm -f compiler lex.yy.c parser.tab.c parser.tab.h *.o

.PHONY: all clean test

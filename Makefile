CC = gcc
CFLAGS = -Wall -g

OBJECTS = hw1.tab.o lex.yy.o ast.o 

compiler: $(OBJECTS)
	$(CC) $(CFLAGS) -o compiler $(OBJECTS)

lex.yy.c: hw1.l hw1.tab.h
	flex hw1.l

hw1.tab.c hw1.tab.h: hw1.y
	bison -d hw1.y

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c

test: compiler
	./compiler test.code

clean:
	rm -f compiler lex.yy.c hw1.tab.c hw1.tab.h *.o

.PHONY: all clean test

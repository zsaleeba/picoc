CC=gcc
CFLAGS=-Wall -g -DUNIX_HOST #-DDEBUG_EXPRESSIONS #-DDEBUG_LEXER
LIBS=-lm

TARGET	= picoc
SRCS	= picoc.c table.c lex.c parse.c expression.c heap.c type.c variable.c clibrary.c library_unix.c platform.c platform_unix.c math_library.c
OBJS	:= $(SRCS:%.c=%.o)

all: depend $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

test:	all
	(cd tests; make test)

clean:
	rm -f $(TARGET) $(OBJS) *~

count:
	cat picoc.h picoc.c table.c lex.c parse.c expression.c heap.c type.c variable.c | grep -v '^[ 	]*/\*' | grep -v '^[ 	]*$$' | wc

depend:
	$(CC) -MM $(SRCS) >.depend

-include .depend

CC=gcc
CFLAGS=-Wall -g #-DDEBUG_LEXER #-DDEBUG_HEAP -DDEBUG_LEXER
LIBS=-lm

TARGET	= picoc
SRCS	= picoc.c table.c lex.c parse.c intrinsic.c heap.c type.c variable.c str.c
OBJS	:= $(SRCS:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

test:	picoc
	(cd tests; make test)

clean:
	rm -f $(TARGET) $(OBJS) *~

count:
	wc $(SRCS) picoc.h

depend:
	$(CC) -MM $(SRCS) >.depend

-include .depend

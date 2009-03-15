CC=gcc
CFLAGS=-Wall -g
LIBS=-lm

TARGET	= picoc
SRCS	= picoc.c table.c lex.c parse.c expression.c heap.c type.c variable.c clibrary.c library_unix.c platform.c platform_unix.c
OBJS	:= $(SRCS:%.c=%.o)

all: depend $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

test:	all
	(cd tests; make test)

clean:
	rm -f $(TARGET) $(OBJS) *~

count:
	cat picoc.h picoc.c table.c lex.c parse.c expression.c heap.c type.c variable.c clibrary.c | grep -v '^[ 	]*/\*' | grep -v '^[ 	]*$$' | wc

depend:
	$(CC) -MM $(SRCS) >.depend

-include .depend

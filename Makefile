CC=gcc
CFLAGS=-Wall -g
LIBS=-lm

TARGET	= picoc
SRCS	= picoc.c table.c lex.c parse.c heap.c type.c variable.c clibrary.c platform_library.c platform_support.c
OBJS	:= $(SRCS:%.c=%.o)

all: depend $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

test:	picoc
	(cd tests; make test)

clean:
	rm -f $(TARGET) $(OBJS) *~

count:
	wc picoc.h picoc.c table.c lex.c parse.c heap.c type.c variable.c clibrary.c

depend:
	$(CC) -MM $(SRCS) >.depend

-include .depend

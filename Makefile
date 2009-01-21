CC=gcc
CFLAGS=-Wall -g
LIBS=-lm

TARGET	= picoc
SRCS	= picoc.c table.c str.c parse.c lex.c intrinsic.c heap.c
OBJS	:= $(SRCS:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

test:	picoc
	(cd test; make test)

clean:
	rm -f $(TARGET) $(OBJS) *~

count:
	wc $(SRCS) picoc.h

depend:
	$(CC) -MM $(SRCS) >.depend

-include .depend

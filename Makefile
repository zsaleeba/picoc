CC=gcc
CFLAGS=-Wall -g
LIBS=-lm

TARGET	= picoc
SRCS	= picoc.c table.c str.c parse.c lex.c
OBJS	:= $(SRCS:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJS) *~

count:
	wc $(SRCS) picoc.h

depend:
	$(CC) -MM $(SRCS) >.depend

-include .depend

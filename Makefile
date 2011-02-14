CC=gcc
CFLAGS=-Wall -pedantic -g -DUNIX_HOST
LIBS=-lm -lreadline

TARGET	= picoc
SRCS	= picoc.c table.c lex.c parse.c expression.c heap.c type.c \
	variable.c clibrary.c platform.c include.c \
	platform/platform_unix.c platform/library_unix.c \
	cstdlib/stdio.c cstdlib/math.c cstdlib/string.c cstdlib/stdlib.c \
	cstdlib/time.c cstdlib/errno.c cstdlib/ctype.c cstdlib/stdbool.c \
	cstdlib/unistd.c
OBJS	:= $(SRCS:%.c=%.o)

all: depend $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# rebuild the version number every time so we always have the
# correct subversion version
version.h:
	echo "#define PICOC_SUBVERSION_VERSION \"`svnversion`\"" > version.h

.PHONY: version.h

test:	all
	(cd tests; make test)

clean:
	rm -f $(TARGET) $(OBJS) version.h *~

count:
	@echo "Core:"
	@cat picoc.h picoc.c table.c lex.c parse.c expression.c platform.c heap.c type.c variable.c include.c | grep -v '^[ 	]*/\*' | grep -v '^[ 	]*$$' | wc
	@echo ""
	@echo "Everything:"
	@cat $(SRCS) *.h */*.h | wc

depend:
	touch version.h
	$(CC) -MM $(SRCS) >.depend

-include .depend

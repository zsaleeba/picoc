TESTS=	00_assignment.test \
	01_comment.test \
	02_printf.test

%.test: %.expect %.c ../picoc
	@echo Test: $*...
	-@../picoc $*.c 2>&1 >$*.output
	@if [ "x`diff -qu $*.expect $*.output`" != "x" ]; \
	then \
        	echo "error in test $*"; \
        	diff -u $*.expect $*.output; \
		exit 1; \
	fi; \
       	rm -f $*.output
	
%.output: %.c ../picoc
	@../picoc $< 2>&1 >$@

all: test

test: $(TESTS)
	@echo "test passed"

TESTS=	assignment.test \
	comment.test \
	printf.test

%.test: %.t
	@./picotest.sh $<

all: test

test: $(TESTS)
	@echo "test passed"

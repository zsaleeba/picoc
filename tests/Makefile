TESTS=	00_assignment.test \
	01_comment.test \
	02_printf.test \
	03_struct.test \
	04_for.test \
	05_array.test \
	06_case.test \
	07_function.test \
	08_while.test \
	09_do_while.test \
	10_pointer.test \
	11_precedence.test \
	12_hashdefine.test \
	13_integer_literals.test \
	14_if.test \
	15_recursion.test \
	16_nesting.test \
	17_enum.test \
	18_include.test \
	19_pointer_arithmetic.test \
	20_pointer_comparison.test \
	21_char_array.test \
	22_floating_point.test \
	23_type_coercion.test \
	24_math_library.test \
	25_quicksort.test \
	26_character_constants.test \
	28_strings.test \
	29_array_address.test \
        34_array_assignment.test

%.test: %.expect %.c
	@echo Test: $*...
	-@../picoc $*.c 2>&1 >$*.output
	@if [ "x`diff -qbu $*.expect $*.output`" != "x" ]; \
	then \
        	echo "error in test $*"; \
        	diff -u $*.expect $*.output; \
       		rm -f $*.output; \
		exit 1; \
	fi; \
       	rm -f $*.output
	
all: test

test: $(TESTS)
	@echo "test passed"

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE -DEBUG

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

hw10: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw10

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c


testall: test1 test2 test3
test1: hw10
	./hw10 4 | sort > output4
	diff -w output4 expected/expected4

test2: hw10
	./hw10 8 | sort > output8
	diff -w output8 expected/expected8

test3: hw10
	./hw10 11 | sort > output11
	diff -w output11 expected/expected11

clean: # remove all machine generated files
	rm -f hw10 *.o output?

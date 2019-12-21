WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --log-file=vallog --leak-check=full --verbose
TESTFALGS = 

SRCS = memory.c
OBJS = $(SRCS:%.c=%.o)

hw17: $(OBJS)
	$(GCC) $(OBJS) -o hw18

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1

test1: hw18
	./hw18 inputs/maze1 inputs > output1
	diff -w output1 expected/expected1


clean: # remove all machine generated files
	rm -f hw17 *.o output? vallog testgen
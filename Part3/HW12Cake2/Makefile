WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_CREATELIST -DTEST_ELIMINATE -DTEST_DELETENODE -DDEBUG

SRCS = main.c hw12.c
OBJS = $(SRCS:%.c=%.o)

hw12: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw12

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

#testmemory: hw08
#	$(VAL) ./hw08 inputs/test1.bin > output1
#	$(VAL) ./hw08 inputs/test2.bin > output2
#	$(VAL) ./hw08 inputs/test3.bin > output3
#	$(VAL) ./hw08 inputs/test4.bin > output4
#	$(VAL) ./hw08 inputs/test5.bin > output5
#testing only input3 and output3

testall: test1 test2 test3

test1: hw12
	./hw12 6 3 > output1
	diff output1 expected/expected1

test2: hw12
	./hw12 6 4 > output2
	diff output2 expected/expected2

test3: hw12
	./hw12 25 7 > output3
	diff output3 expected/expected3

clean: # remove all machine generated files
	rm -f hw12 *.o output?

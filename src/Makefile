CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
OUTFILE=./test.out
DEBUG_FLAGS=-g -O0 -fprofile-arcs -ftest-coverage --coverage
TST_LIBS = -lcheck -lsubunit -lrt -lpthread -lm

OS := $(shell uname -s)
ifeq ($(OS), Darwin)
	CC += -D OS_MAC
	TST_LIBS =$(shell pkg-config --libs check)
endif
ifeq ($(OS), linux)
	CC += -D OS_LINUX
	TST_LIBS =-lcheck -lsubunit -lrt -lpthread -lm
endif

all: clean my_math.a test

test.o: test.c 
	$(CC) $(CFLAGS) -c $^

test: test.o my_math.a
	$(CC) $< -L. -lmy_math $(TST_LIBS) -o $(OUTFILE)
	$(OUTFILE)

my_math.o: my_math.h my_math.c
	$(CC) $(CFLAGS) -c $^

my_math.a: my_math.o
	ar rcs my_math.a $^
	ar rcs libmy_math.a $^
	ranlib my_math.a
	ranlib libmy_math.a

gcov_report: clean
	$(CC) $(DEBUG_FLAGS) $(CFLAGS) -c my_math.h my_math.c
	ar rcs libmy_math.a my_math.o
	ranlib libmy_math.a
	$(CC) $(DEBUG_FLAGS) $(CFLAGS) -c test.c
	$(CC) $(DEBUG_FLAGS) test.o libmy_math.a -L. -lmy_math $(TST_LIBS) -o $(OUTFILE)
	$(OUTFILE)
	gcov my_math.c
	lcov -t "my_math" -o my_math.info -c -d .
	genhtml -o report my_math.info
	open report/index.html

CPPLINT.cfg:
	cp ../CPPLINT.cfg CPPLINT.cfg
	cp ../cpplint.py cpplint.py

lint: CPPLINT.cfg
	@clear
	python3 cpplint.py --extensions=c *.c
	python3 cpplint.py --extensions=c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.h
	rm -f CPPLINT.cfg
	rm -f cpplint.py

valgrind_check:
	CK_FORK=no valgrind --leak-check=full --tool=memcheck --track-origins=yes -s --show-leak-kinds=all -v $(OUTFILE)

clean:
	rm -f *.o *.a *.so *.gch *.gcno *.gcda *.gcov *.info *.out CPPLINT.cfg my_math
	rm -rf report/
	rm -rf test.out.dSYM/


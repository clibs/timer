#
#	Arguments Makefile
#
 
CFILES   = src/timer.c
HFILES   = src/timer.h
CFLAGS   = -Wall -Wextra
TESTFILE = src/test/test.c
TESTEXE  = src/test/timer_test

all: $(CFILES) $(HFILES) $(TESTFILE)
	gcc $(CFLAGS) $(CFILES) $(TESTFILE) -o $(TESTEXE)

run: all
	./$(TESTEXE)


# timer Makefile
#
# This builds a simple test to check this timer's precision
# A simple 'make run' will do

CFILES   = src/timer.c
HFILES   = src/timer.h
CFLAGS   = -Wall -Wextra
TESTFILE = src/test/test.c
TESTEXE  = src/test/timer_test

all: $(CFILES) $(HFILES) $(TESTFILE)
	gcc $(CFLAGS) $(CFILES) $(TESTFILE) -o $(TESTEXE) $(LDFLAGS)

run: all
	./$(TESTEXE)


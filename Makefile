#
#	Arguments Makefile
#

CFILES   = src/timer.c
HFILES   = src/timer.h
CFLAGS   = -Wall -Wextra
TESTFILE = src/test/test.c
TESTEXE  = src/test/timer_test
LDFLAGS  = -lrt

all: $(CFILES) $(HFILES) $(TESTFILE)
	gcc $(CFLAGS) $(CFILES) $(TESTFILE) -o $(TESTEXE) $(LDFLAGS)

run: all
	./$(TESTEXE)


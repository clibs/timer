
test: test.c src/timer.c
	$(CC) $^ -o $@ -Wall -Wextra

clean:
	rm -f test

.PHONY: clean


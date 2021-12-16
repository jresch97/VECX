CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -I../

all: vecx_tests.out

vecx_tests.out: vecx_tests.c
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm -f vecx_tests.out
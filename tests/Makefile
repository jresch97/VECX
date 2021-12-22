CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -I../

all: vecx_tests.out vec3x_tests.out

vecx_tests.out: vecx_tests.c
	$(CC) $(CFLAGS) -o $@ $^ -lm

vec3x_tests.out: vec3x_tests.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f vecx_tests.out vec3x_tests.out
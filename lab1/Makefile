# Set the C compiler to `gcc` (GNU Compiler Collection)
CC=gcc

# Settings to use for the compilation
CFLAGS= -Wall -Wconversion -g

all: hello_world types format_strings pointers arrays exercise2 exercise3

hello_world: src/hello_world.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

types: src/types.c
	"$(CC)" $(CFLAGS) -Wno-unused-variable -o $@ src/$@.c

format_strings: src/format_strings.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

pointers: src/pointers.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

arrays: src/arrays.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

exercise2: src/exercise2.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

exercise3: src/exercise3.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

.PHONY: clean
clean:
	rm hello_world types format_strings pointers arrays exercise2 exercise3 2>/dev/null || true

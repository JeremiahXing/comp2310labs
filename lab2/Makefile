# Set the C compiler to `gcc` (GNU Compiler Collection)
CC=gcc

# Settings to use for the compilation
CFLAGS=-Wall -Wconversion -g

all: bitwise-and-shifts grades loops copy1 copy2 lines wordcount string-util print-ptrs swap-v1 swap-v2 return2 sum strcmp strlen

bitwise-and-shifts: src/bitwise-and-shifts.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

grades: src/grades.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

loops: src/loops.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

copy1: src/copy1.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

copy2: src/copy2.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

lines: src/lines.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

wordcount: src/wordcount.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

string-util: src/string-util.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

print-ptrs: src/print-ptrs.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

swap-v1: src/swap-v1.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

swap-v2: src/swap-v2.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

return2: src/return2.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

sum: src/sum.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

strcmp: src/strcmp.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

strlen: src/strlen.c
	"$(CC)" $(CFLAGS) -o $@ src/$@.c

.PHONY: clean
clean:
	rm bitwise-and-shifts grades loops copy1 copy2 lines wordcount string-util print-ptrs swap-v1 swap-v2 return2 sum strcmp strlen 2>/dev/null || true

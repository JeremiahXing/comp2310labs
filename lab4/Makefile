CC = gcc
CFLAGS = -Og
LDLIBS = -lpthread

PROGS = forks shellx procmask1 child_handler kill_children snooze
LIB = src/csapp.c

all: $(PROGS)

$(PROGS):
	"$(CC)" $(CFLAGS) -o $@ src/$@.c $(LIB) $(LDLIBS)

clean:
	rm -f $(PROGS)


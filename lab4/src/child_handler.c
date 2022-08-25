/*
 * forks.c - Examples of Unix process control
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "csapp.h"

#define N 5

int ccount = 0;

/*
 * child_handler - SIGCHLD handler that reaps one terminated child
 */

void child_handler(int sig) {
    pid_t pid;
    while(ccount > 0)
    {
        pid = Wait(NULL);
        Sio_puts("handler reaped child ");
        Sio_putl((long)pid);
        Sio_puts("\n");
        ccount--;
    }
}

void funct_hand() {
    pid_t pid[N];
    int i;
    ccount = N;
    sigset_t mask, prev;
    // Sigaddset(&mask, SIGCHLD);
    Signal(SIGCHLD, child_handler);

    for (i = 0; i < N; i++) {
        if ((pid[i] = Fork()) == 0) {
            Sleep(1);
            exit(0); /* Child exits */
        }
    }
    while (ccount > 0) /* Parent spins */
        Sigsuspend(&mask);
}

int main(int argc, char* argv[]) {
    funct_hand();
    return 0;
}

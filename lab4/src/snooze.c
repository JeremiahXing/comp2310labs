#include <unistd.h>
#include "csapp.h"
#include <stdlib.h>
#include <stdio.h>

void sig_handler(int sig){
    return ;
}

unsigned int wakeup(unsigned int secs)
{
    int left = sleep(secs);
    if (left)
        printf("slept %i of %i secs\n",secs-left, secs);
    else
        printf("wake up after %i secs\n", secs);
}

int main(int argc, char** argv){
    Signal(SIGINT, sig_handler);
    int time = atoi(argv[1]);
    wakeup(time);
    return 0;
}
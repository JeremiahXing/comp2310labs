#include <stdio.h>
#include <malloc.h>

int main(int argc, char **argv){
    printf("There are %d arguments\n", argc);
    printf("%s\n", argv[0]);
    return 0;
}
#include <stdio.h>

int main() {
    int x = 5;
    int *p = &x;

    printf("before update:\n");
    printf("x = %i\n", x);
    printf("p = %p\n", p);

    *p = 7;

    printf("after update:\n");
    printf("x = %i\n", x);
    printf("p = %p\n", p);
    return 0;
}

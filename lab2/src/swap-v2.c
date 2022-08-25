#include <stdio.h>

void swap_v2(int *a, int *b) {
    printf("(swap_v2) a = %i, b = %i\n", *a, *b);
    return;
}

int main() {
    int a = 2;
    int b = 3;

    swap_v2(&a, &b);
    printf("(main) a = %i, b = %i\n", a, b);

    return 0;
}

#include <stdio.h>

void swap_v1(int a, int b) {
    int temp = b;
    b = a;
    a = temp;

    printf("(swap_v1) a = %i, b = %i\n", a, b);

    return;
}

int main() {
    int a = 2;
    int b = 3;

    swap_v1(a, b);
    printf("(main) a = %i, b = %i\n", a, b);

    return 0;
}

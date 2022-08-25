#include <stdio.h>

int return2(int *r2) {
    *r2 = 10;
    return *r2 + 10;
}

int main() {
    int ret1 = 50;
    int ret2 = return2(&ret1);
    printf("ret1 = %i, ret2 = %i\n", ret1, ret2);
    return 0;
}

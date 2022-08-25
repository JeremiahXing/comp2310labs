#include <stdio.h>

int main() {
    int counter = 2;

    for(; counter > 1; counter--) {
        printf("counter = %i\n", counter);
    }

    while (1) {
        printf("counter = %i\n", counter);
        break;
    }

    return 0;
}

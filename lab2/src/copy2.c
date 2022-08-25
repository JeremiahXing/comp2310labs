#include <stdio.h>

int main() {
    int c;

    // Your task is to condense the following statements into as fewer as you can

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}

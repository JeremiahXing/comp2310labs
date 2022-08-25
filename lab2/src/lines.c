#include <stdio.h>

int main() {
    // We can declare multiple comma-separated variables in a single statement
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            nl++;
        }
    }
    printf("%i\n", nl);

    return 0;
}

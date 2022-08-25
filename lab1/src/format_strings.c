#include <stdio.h>

int main() {
    printf("%%c (char) = %c\n", 'a');
    printf("%%i (int) = %i\n", 82421);
    printf("%%x (int) = %x\n", 82421);
    printf("%%g (float) = %g\n", 6.674e-11);  // 'e-11' specifies power of 10 (10^(-11) in this case)
    printf("%%s (string) = %s\n", "Hello, world!");
    printf("%%p (pointer) = %p\n", "Hello, world!");

    return 0;
}

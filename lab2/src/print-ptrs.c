#include <stdio.h>

int main() {
    int marks[4] = {70, 80, 90, 100};

    printf("address of marks[0] = %p\n", &marks[0]);
    printf("address of marks[1] = %p\n", &marks[1]);

    // type conversions
    // marks point to the first element of the marks array, so marks[0]
    char *byte0 = (char*) marks;
    char *byte1 = (char*) marks + 1;
    char *byte2 = (char*) marks + 2;
    char *byte3 = (char*) marks + 3;

    printf("\n");

    // print statements
    printf("address of byte0 in marks[0] = %p\n", byte0);
    printf("address of byte1 in marks[0] = %p\n", byte1);
    printf("address of byte2 in marks[0] = %p\n", byte2);
    printf("address of byte3 in marks[0] = %p\n", byte3);

    return 0;
}

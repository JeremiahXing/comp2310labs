#include <stdio.h>

int main() {
    int marks = 100;

    switch (marks / 10) {
        case 10:
        case 9:
        case 8:
            printf("Your Grade : HD\n");
            break;
        case 7:
            printf("Your Grade : D\n");
            break;
        case 6:
            printf("Your Grade : CR\n");
            break;
        case 5:
            printf("Your Grade : P\n");
            break;
        default:
            printf("Your Grade : F\n");
    }

    return 0;
}

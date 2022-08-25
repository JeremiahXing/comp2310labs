#include <stdio.h>

int str_len(char *s) {
    int len = 0;
    while(*s != '\0')
    {
        len++;
        s++;
    }

    return len;
}

int main() {
    char str[] = "HELLO";
    int length = str_len(str);
    printf("length = %i\n", length);
    return 0;
}

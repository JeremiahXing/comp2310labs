#include <stdio.h>

int str_cmp(char *s, char *t) {
    int i = 0;

    // write the code to compare the two strings here
    while(*s && *t){
        if (*s == *t)
        {
            s += 1;
            t += 1;
        }
        else 
            return *s - *t;
    }
    i = *s == '\0' ? *t : *s;
    return i;
}

int main() {
    char str1[] = "HELLO";
    char str2[] = "HELLOafsds";

    int result = str_cmp(str1, str2);
    printf("result = %i\n", result);

    return 0;
}

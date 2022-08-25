#include <stdio.h>

int main() {
    // bitwise operators test begin
    int k = 255;
    printf("k = %i\n",k);

    k = k & 0xFF;
    printf("k = %i\n",k);

    k = k & 0xF;
    printf("k = %i\n",k);

    k = k | 0xFF;
    printf("k = %i\n",k);
    // bitwise operator test end

    // shift operator test begin
    int initial_number = 1;
    int shift_amount = 10;

    // notice the placement of the left shift operator (<<) in relation to the initial_number and shift_amount
    int new_number = initial_number << shift_amount;
    printf("new_number = %i\n", new_number);

    new_number = new_number / 512;
    shift_amount = initial_number;

    // notice the placement of the right shift operator (>>) in relation to the new_number and shift_amount
    int another_number = new_number >> shift_amount;
    printf("another_number = %i\n", another_number);

    return 0;
}

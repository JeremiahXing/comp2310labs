#include <stdio.h>

int main() {
    int array[] = { 4, 2, 9, 23 };

    // print the address of `array`
    printf("array = %p\n", array);

    // print the contents of `array`
    printf("array = { %i, %i, %i, %i }\n", array[0], array[1], array[2], array[3]);

    // double the element at index 2
    array[2] = array[2] * 2;

    // set element at index 3 to value 1
    array[3] = 1;

    // print out the new contents
    printf("array = { %i, %i, %i, %i }\n", array[0], array[1], array[2], array[3]);

    // unlike pointers, sizeof on an array will get the array length in bytes
    printf("sizeof(array) = %li\n", sizeof(array));

    // we can get the length of the array by dividing by the size of the elements
    printf("length(array) = %li\n", sizeof(array) / sizeof(int));

    // but once the array 'decays' to a pointer, we can no longer access the length!
    // the length is tracked by the compiler, not stored in memory. Once the compiler
    // loses track of where the data came from, we don't know the length.

    // Because an array is so much like a pointer, C lets us directly assign
    // an array type to a pointer type (but not the other way round!).
    int *decayed_ptr = array;

    // is the same memory location as what we printed for `array`?
    printf("decayed_ptr = %p\n", decayed_ptr);

    // are the contents the same as `array`?
    printf("decayed_ptr = { %i, %i, %i, %i }\n", decayed_ptr[0], decayed_ptr[1], decayed_ptr[2], decayed_ptr[3]);

    // is this the same as what we printed for `sizeof(array)`?
    printf("sizeof(decayed_ptr) = %li\n", sizeof(decayed_ptr));

    // is this the same as what we printed for `length(array)`?
    printf("length(decayed_ptr) = %li\n", sizeof(decayed_ptr) / sizeof(int));

    return 0;
}

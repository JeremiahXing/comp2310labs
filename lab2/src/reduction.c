#include <stdio.h>
#include <string.h>

int reduce1(int *array, int length) {
	int result = 0;
	for (int i = 0; i < length; i++)
		result += array[i];
	return result;
}

int reduce2(int *array, int length) {
	int result = 1;
	for (int i = 0; i < length; i++)
		result *= array[i];
	return result;
}

//Declare a function pointer that points to a function that takes an int array as the first argument
//and an int as second argument that specifies the length of the array

int reduce(int * array, int length, int (*red)(int *array, int length)) {
	// return an int result by calling the red function and supplying the proper arguments
}

int main(int argc, char *argv[]) {
	int (*red)(int *array, int length);
	int reduction_type;
	int samples[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	if (argc > 1 && strcmp(argv[1], "-r1") == 0) 
		reduction_type = 1;
	if (argc > 1 && strcmp(argv[1], "-r2") == 0) 
		reduction_type = 2;
	
	// Write an if/else block that assign the function pointer red a pointer to reduce1 if reduction_type is 1
    // or a pointer to reduce2 if reduction_type is 2
	// make sure you cast reduce1 and reduce2 to the correct function pointer type
	if (reduction_type == 1) {
		red = (int (*)(int*, int))reduce1;
	} else {
		red = (int (*)(int*, int))reduce2;
	}
	
	// call the reduce function and supply the correct arguments
	int result = reduce(samples, 10, red);
	printf("result = %d \n", result);
	return 0;
}

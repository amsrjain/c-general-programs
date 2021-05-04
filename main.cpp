#include <stdio.h>
#include <string.h>

// external functions

// Matrix tests
void matrix_test_1(void);
void matrix_test_2(void);


// Main function that calls sub functions for various trials
int main(void) {
	printf("Hello World! \n");

	/* Multiply two matrix of size 2x3 and 3x4 */
	matrix_test_1();

	/* Multiply two matrix of size 6x3 and 3x9 */
	matrix_test_2();

	return 1;
}
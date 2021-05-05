#include <stdio.h>
#include <string.h>

// external functions

// Matrix tests
void matrix_test_1(void);
void matrix_test_2(void);

void string_test_1(void);
void string_test_2(void);
void string_test_3(void);

// Main function that calls sub functions for various trials
int main(void) {
	printf("Hello World! \n");

	/* test to Multiply two matrix of size 2x3 and 3x4 */
	matrix_test_1();

	/* test to Multiply two matrix of size 6x3 and 3x9 */
	matrix_test_2();

	/* test if string has all unique characters */
	string_test_1();

	/* test if a string is a permutation of another */
	string_test_2();

	/* test if two strings are maximum one edit away */
	string_test_3();

	return 1;
}
#include <stdio.h>
#include <string.h>

#include "Matrix.h"

// test_1 inputs
int matrixA[2][3] = { { 2,1,4 }, { 0,1,1 } };
int matrixB[3][4] = { { 6,3,-1,0 }, { 1,1,0,4 }, {-2,5,0,2} };
int matrixX[2][4];

// expected test result values
int matrixTest_1[2][4] = { { 5,27,-2,12 }, { -1,6,0,6 } };

// test_1 inputs
int matrixC[6][3] = { { 2,1,-4 }, { 0,-1,1 }, { -3,2,5 }, { 9,-8,7 }, { -4,3,1 }, { 7,2,-1 } };
int matrixD[3][9] = { { 6,3,-1,0,4,3,8,-7,1 }, { -2,-3,5,4,9,-6,1,0,7 }, {-2,-5,0,2,-6,1,3,-12,-10} };
int matrixY[6][9];

// expected test result values
int matrixTest_2[6][9] = { { 18,23,3,-4,41,-4,5,34,49 }, { 0,-2,-5,-2,-15,7,2,-12,-17 }, { -32,-40,13,18,-24,-16,-7,-39,-39 },
						   { 56,16,-49,-18,-78,82,85,-147,-117}, { -32,-26,19,14,5,-29,-26,16,7}, { 40,20,3,6,52,8,55,-37,31 } };

/* 
* Multiply two matrix of size 2x3 and 3x4 
*/
void matrix_test_1 (void) {

	Matrix_instance_t	matrix_a, matrix_b, matrix_x, matrix_test_1;

	matrix_a = { (void*)matrixA,  2, 3 };
	matrix_b = { (void*)matrixB,  3, 4 };
	matrix_x = { (void*)matrixX,  2, 4 };

	matrix_test_1 = { (void*)matrixTest_1,  2, 4 };

	printf("\n MATRIX TEST 1 -------------------------- \n");

	printf("\nmatrix_a:");
	Matrix_print(&matrix_a);

	printf("\nmatrix_b:");
	Matrix_print(&matrix_b);

	Matrix_multiply_by_ptr(&matrix_a, &matrix_b, &matrix_x);

	printf("\nmatrix_x: == matrx_a X matrix_b");
	Matrix_print(&matrix_x);

	if (Matrix_compare(&matrix_x, &matrix_test_1))
		printf("Result: PASS");
	else
		printf("Result: FAIL");

	printf("\n -------------------------------------- \n");

}


/*
* Multiply two matrix of size 2x3 and 3x4
*/
void matrix_test_2(void) {

	Matrix_instance_t	matrix_c, matrix_d, matrix_y, matrix_test_2;

	matrix_c = { (void*)matrixC,  6, 3 };
	matrix_d = { (void*)matrixD,  3, 9 };
	matrix_y = { (void*)matrixY,  6, 9 };

	matrix_test_2 = { (void*)matrixTest_2,  6, 9 };

	printf("\n MATRIX TEST 2 -------------------------- \n");

	printf("\nmatrix_c:");
	Matrix_print(&matrix_c);

	printf("\nmatrix_d:");
	Matrix_print(&matrix_d);

	Matrix_multiply_by_ptr(&matrix_c, &matrix_d, &matrix_y);

	printf("\nmatrix_y: == matrix_c X matrix_d");
	Matrix_print(&matrix_y);

	if (Matrix_compare(&matrix_y, &matrix_test_2))
		printf("Result: PASS");
	else
		printf("Result: FAIL");

	printf("\n -------------------------------------- \n");

}

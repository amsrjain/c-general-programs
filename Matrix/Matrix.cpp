#include <stdio.h>
#include <string.h>

#include "Matrix.h"

// macro to access value using ptr to matrix
#define MATRIX_VAL(matrix, row, col) (*((int *)matrix->pMatrix + (row * matrix->num_col) + col))

/*
 * Function to print a matrix of any size
 */
void Matrix_print(Matrix_instance_t *matrix) {
	int row, col;

	printf("\nsize: %d X %d:", matrix->num_row, matrix->num_col);

	for (row = 0; row < matrix->num_row; row++) {
		printf("\n | ");
		for (col = 0; col < matrix->num_col; col++)
			printf("%3d ", *((int *)matrix->pMatrix + (row * matrix->num_col) + col));
		printf("|");
	}

	printf("\n");
}

/* 
 * Function to compare two matrix and return true/false.
 * This is needed for test functions
 */
bool Matrix_compare(Matrix_instance_t* matrix_a,
					Matrix_instance_t* matrix_b) {
	
	int i, j;

	// matrix size should be same
	if ((matrix_a->num_row != matrix_b->num_row) || 
		(matrix_a->num_col != matrix_b->num_col)) {

		return false;
	}

	// compare the 2 matrices
	for (i = 0; i < matrix_a->num_row; i++) {
		for (j = 0; j < matrix_a->num_col; j++) {
			if (MATRIX_VAL(matrix_a, i, j) != MATRIX_VAL(matrix_b, i, j)) {
				return false;
			}
		}
	}

	return true;
}

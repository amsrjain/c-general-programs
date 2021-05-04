#include <stdio.h>
#include <string.h>

#include "Matrix.h"

// macro to access value using ptr to matrix
#define MATRIX_VAL(matrix, row, col) (*((int *)matrix->pMatrix + (row * matrix->num_col) + col))

/*
 *  Function to multiply two matrix of any compatible size
 */
void Matrix_multiply_by_ptr(Matrix_instance_t* matrix_a,
							Matrix_instance_t* matrix_b,
							Matrix_instance_t* matrix_x) {
	int i, j, k;

	// check matrix size compatibility
	if (matrix_a->num_col != matrix_b->num_row) {
		printf("\nERROR: Input matrix size incompatible for multiplication. [%d][%d] x [%d][%d]",
			matrix_a->num_row, matrix_a->num_col,
			matrix_b->num_row, matrix_b->num_col);
		return;
	}

	// ensure that result matrix is correct size
	if ((matrix_x->num_row != matrix_a->num_row) ||
		(matrix_x->num_col != matrix_b->num_col)) {
		printf("\nERROR: Output matrix size incompatible for multiplication. [%d][%d]",
			matrix_x->num_row, matrix_x->num_col);
		return;
	}

	// multiply the 2 matrices and store result in output matrix
	for (i = 0; i < matrix_a->num_row; i++) {
		for (k = 0; k < matrix_b->num_col; k++) {

			MATRIX_VAL(matrix_x, i, k) = 0;

			for (j = 0; j < matrix_a->num_col; j++) {	// or matrix_b->num_row
				MATRIX_VAL(matrix_x, i, k) += MATRIX_VAL(matrix_a, i, j) * MATRIX_VAL(matrix_b, j, k);
			}
		}
	}
}

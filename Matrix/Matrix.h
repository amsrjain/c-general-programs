#pragma once

typedef struct tagMatrix {
	void*			pMatrix;
	unsigned char	num_row;
	unsigned char	num_col;
} Matrix_instance_t;


// function prototypes
void Matrix_print(Matrix_instance_t* matrix);
bool Matrix_compare(Matrix_instance_t* matrix_a, Matrix_instance_t* matrix_b);

void Matrix_multiply_by_ptr (
	Matrix_instance_t* matrix_a,
	Matrix_instance_t* matrix_b,
	Matrix_instance_t* matrix_c);
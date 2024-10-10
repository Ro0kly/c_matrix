#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  bool r2 = !s21_matrix_correct(B);
  bool r3 = !s21_matrix_correct(result);
  
  if (r1 || r2 || r3) {
    status = WRONG_MATRIX;
  } else if (!s21_matrices_same_size(A, B) || !s21_matrices_same_size(A, result)) {
    status = CALCULATION_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return status;
}
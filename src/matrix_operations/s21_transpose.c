#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  bool r2 = !s21_matrix_correct(result);
  if (r1 || r2) {
    status = WRONG_MATRIX;
  } else if (A->rows != result->columns || A->columns != result->rows) {
    status = CALCULATION_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return status;
}
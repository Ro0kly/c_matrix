#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  if (r1) {
    status = WRONG_MATRIX;
  } else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return status;
}
#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  int r1 = !s21_matrix_correct(A);
  int r2 = !s21_matrix_correct(B);
  if (r1 || r2) {
    status = FAILURE;
  } else if (!s21_matrices_same_size(A, B)) {
    status = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          status = FAILURE;
        }
      }
    }
  }
  return status;
}
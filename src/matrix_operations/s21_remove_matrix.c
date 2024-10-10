#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  int r1 = !s21_matrix_correct(A);
  if (r1) {
    return;
  }
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
    A->matrix[i] = NULL;
  }
  free(A->matrix);
  A->matrix = NULL;
}
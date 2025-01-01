#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  bool r2 = !s21_matrix_correct(B);

  if (r1 || r2) {
    status = WRONG_MATRIX;
  } else if (A->columns != B->rows) {
    status = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, B->columns, result);
    int i_index = 0, j_index = 0;
    while (i_index != A->rows && j_index != B->columns) {
      for (int i = 0, j = 0; i < A->columns && j < B->rows; i++, j++) {
        result->matrix[i_index][j_index] +=
            A->matrix[i_index][i] * B->matrix[j][j_index];
      }

      if (j_index == B->columns - 1) {
        i_index++;
        j_index = 0;
      } else {
        j_index++;
      }
    }
  }
  return status;
}

// for (int i = 0; i < A->rows; i++) {
//   for (int j = 0; j < B->columns; j++) {
//     result->matrix[i][j] =
//   }
// }
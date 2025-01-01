#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  if (r1) {
    status = WRONG_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else if (A->rows == 1 || A->columns == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = A->matrix[0][0];
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double res = 0;
        matrix_t tmp = {0};
        s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
        s21_minor_matrix(A, i, j, &tmp);
        double det = 0;
        s21_determinant(&tmp, &det);
        res = det * pow(-1, i + j);
        result->matrix[i][j] = res;
        s21_remove_matrix(&tmp);
      }
    }
  }
  return status;
}
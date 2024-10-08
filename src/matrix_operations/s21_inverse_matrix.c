#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result){
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  bool r2 = !s21_matrix_correct(result);
  if (r1 || r2) {
    status = WRONG_MATRIX;
  } else if (A->rows != result->rows || A->columns != result->columns) {
    status = CALCULATION_ERROR;
  } else {
double det = 0;
  s21_determinant(A,&det);
  if (det != 0) {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows,A->columns,&tmp);
    if (s21_calc_complements(A,&tmp) == OK) {
      s21_transpose(&tmp, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->rows; j++) {
        result->matrix[i][j] *= -1;
      }
    }
    s21_remove_matrix(&tmp);
    } else {
      status = CALCULATION_ERROR;
    }
  } else {
    status = CALCULATION_ERROR;
  }
  }
  return status;
}
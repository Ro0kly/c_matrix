#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  if (r1) {
    status = WRONG_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else {
    double det = 0;
    s21_determinant(A, &det);
    if (A->rows == 1 || A->columns == 1) {
      s21_create_matrix(A->rows, A->columns, result);
      result->matrix[0][0] = 1 / A->matrix[0][0];
    } else if (det != 0) {
      matrix_t complements = {0};
      matrix_t transpose = {0};
      s21_calc_complements(A, &complements);
      s21_transpose(&complements, &transpose);
      s21_mult_number(&transpose, 1.0 / det, result);
      s21_remove_matrix(&complements);
      s21_remove_matrix(&transpose);
    } else {
      status = CALCULATION_ERROR;
    }
  }
  return status;
}
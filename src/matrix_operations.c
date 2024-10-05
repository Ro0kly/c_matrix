#include "matrix_operations.h"
#define SUCCESS 1
#define FAILURE 0

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  operation_status status = OK;
  if (result == NULL || result->matrix != NULL || rows <= 0 || columns <= 0) {
    status = WRONG_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = malloc(columns * sizeof(double));
    }
  }
  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    return;
  }
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
    A->matrix[i] = NULL;
  }
  free(A->matrix);
  A->matrix = NULL;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  int bad_rule_1 =
      A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0;
  int bad_rule_2 =
      B == NULL || B->matrix == NULL || B->rows <= 0 || B->columns <= 0;
  int bad_rule_3 = A->rows != B->rows || A->columns != B->columns;
  if (bad_rule_1 || bad_rule_2 || bad_rule_3) {
    result = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] != B->matrix[i][j]) {
          result = FAILURE;
          break;
        }
      }
    }
  }
  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  bool r2 = !s21_matrix_correct(B);
  bool r3 = !s21_matrix_correct(result);
  bool r4 = !s21_matrices_same_size(A, B);
  bool r5 = !s21_matrices_same_size(A, result);
  if (r1 || r2 || r3) {
    status = WRONG_MATRIX;
  } else if (r4 || r5) {
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

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  bool r2 = !s21_matrix_correct(B);
  bool r3 = !s21_matrix_correct(result);
  bool r4 = !s21_matrices_same_size(A, B);
  bool r5 = !s21_matrices_same_size(A, result);
  if (r1 || r2 || r3) {
    status = WRONG_MATRIX;
  } else if (r4 || r5) {
    status = CALCULATION_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return status;
}
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

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  int r1 = !s21_matrix_correct(A);
  int r2 = !s21_matrix_correct(B);
  int r3 = !s21_matrices_same_size(A, B);

  if (r1 || r2 || r3) {
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

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  bool r2 = !s21_matrix_correct(result);
  bool r3 = !s21_matrices_same_size(A, result);
  if (r1 || r2) {
    status = WRONG_MATRIX;
  } else if (r3) {
    status = CALCULATION_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  bool r2 = !s21_matrix_correct(B);
  bool r3 = !s21_matrix_correct(result);
  bool r4 = A->columns != B->rows;
  bool r5 = A->rows != result->rows || B->columns != result->columns;
  if (r1 || r2 || r3) {
    status = WRONG_MATRIX;
  } else if (r4 || r5) {
    status = CALCULATION_ERROR;
  } else {
    // for (int i = 0; i < A->rows; i++) {
    //   for (int j = 0; j < B->columns; j++) {
    //     result->matrix[i][j] =
    //   }
    // }
    int i_index = 0, j_index = 0;
    while (i_index != A->rows && j_index != B->columns) {
      
      for (int i = 0, j = 0; i < A->columns && j < B->rows; i++, j++) {
        result->matrix[i_index][j_index] += A->matrix[i_index][i] * B->matrix[j][j_index];
      }

      if (j_index == B->columns-1) {
        i_index++;j_index=0;
      } else {
        j_index++;
      }
    }
  }
  return status;
}
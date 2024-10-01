#include "matrix_operations.h"
#define SUCCESS 1
#define FAILURE 0

void print_line_break() { printf("\n"); }

int s21_print_matrix(matrix_t *matrix) {
  operation_status status = OK;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    status = WRONG_MATRIX;
  } else {
    printf("matrix rows: %d", matrix->rows);
    print_line_break();
    printf("matrix columns: %d", matrix->columns);
    print_line_break();
    for (int i = 0; i < matrix->rows; i++) {
      for (int j = 0; j < matrix->columns; j++) {
        printf("%lf ", matrix->matrix[i][j]);
      }
      print_line_break();
    }
  }
  print_line_break();
  return status;
}

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
    printf("matrix create address: %p\n", &result);
  }
  return status;
}

int s21_fill_matrix(matrix_t *matrix, double value) {
  operation_status status = OK;
  printf("matrix fill address: %p\n", &matrix);
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    status = WRONG_MATRIX;
  } else {
    printf("ok\n");
    printf("matrix r: %d\n", matrix->rows);
    printf("matrix c: %d\n", matrix->columns);
    printf("matrix 0 element: %lf\n", matrix->matrix[0][0]);
    for (int i = 0; i < matrix->rows; i++) {
      for (int j = 0; j < matrix->columns; j++) {
        // printf("i: %d, j: %d\n", i, j);
        matrix->matrix[i][j] = value;
      }
    }
  }
  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    return;
  }
  printf("matrix remove address: %p\n", &A);
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
  if (bad_rule_1 || bad_rule_2) {
    printf("bad\n");
    result = FAILURE;
  } else {
    bool rule = A->rows == B->rows && A->columns == B->columns;
    if (rule) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (A->matrix[i][j] != B->matrix[i][j]) {
            printf("break\n");
            result = FAILURE;
            break;
          }
        }
      }
    } else {
      result = FAILURE;
    }
  }
  return result;
}
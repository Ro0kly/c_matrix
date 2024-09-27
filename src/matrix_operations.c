#include "matrix_operations.h"

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
  }
  return status;
}

int s21_fill_matrix(matrix_t *matrix, double value) {
  operation_status status = OK;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    status = WRONG_MATRIX;
  } else {
    for (int i = 0; i < matrix->rows; i++) {
      for (int j = 0; j < matrix->columns; j++) {
        matrix->matrix[i][j] = value;
      }
    }
  }
  return status;
}
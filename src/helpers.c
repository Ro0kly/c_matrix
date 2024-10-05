#include "matrix_operations.h"

void print_line_break() { printf("\n"); }

bool s21_matrix_correct(matrix_t *matrix) {
  int rule_1 = matrix != NULL && matrix->matrix != NULL;
  int rule_2 = matrix->rows > 0 && matrix->columns > 0;
  return rule_1 && rule_2;
}
bool s21_matrices_same_size(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
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
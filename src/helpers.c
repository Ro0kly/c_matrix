#include "matrix_operations.h"

int s21_2x2_determinant(matrix_t *matrix, double *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(matrix);
  bool r2 = matrix->rows != matrix->columns;
  bool r3 = result == NULL;
  if (r1) {
    status = WRONG_MATRIX;
  } else if (r2 || r3) {
    status = CALCULATION_ERROR;
  } else {
    *result = matrix->matrix[0][0] * matrix->matrix[1][1] -
              matrix->matrix[0][1] * matrix->matrix[1][0];
  }
  return status;
}

int s21_3x3_determinant(matrix_t *matrix, double *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(matrix);
  bool r2 = matrix->rows != matrix->columns;
  bool r3 = result == NULL;
  if (r1) {
    status = WRONG_MATRIX;
  } else if (r2 || r3) {
    status = CALCULATION_ERROR;
  } else {
    printf("---------------start-minors----------------\n");
    for (int i = 0; i < matrix->columns; i++) {
      matrix_t tmp_matrix_2x2 = {0};
      double determinant_2x2 = 0;
      s21_create_matrix(2, 2, &tmp_matrix_2x2);
      s21_minor_matrix(matrix, i, &tmp_matrix_2x2);
      s21_print_matrix(&tmp_matrix_2x2);
      s21_2x2_determinant(&tmp_matrix_2x2, &determinant_2x2);
      printf("minor: %lf\n\n", determinant_2x2);
      *result += determinant_2x2 * pow(-1, 1 + (i + 1)) * matrix->matrix[0][i];
      s21_remove_matrix(&tmp_matrix_2x2);
    }
    printf("---------------end-minors----------------\n");
  }
  return status;
}

int s21_minor_matrix(matrix_t *matrix, int exclude_column_index,
                              matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(matrix);
  bool r2 = !s21_matrix_correct(result);
  if (r1 || r2) {
    status = WRONG_MATRIX;
  } else {
    int new_i = 0, new_j = 0;
    for (int i = 0; i < matrix->rows; i++) {
      for (int j = 0; j < matrix->columns; j++) {
        if (i != 0 && j != exclude_column_index) {
          result->matrix[new_i][new_j] = matrix->matrix[i][j];
          if (new_j == result->columns - 1) {
            new_i += 1;
            new_j = 0;
          } else {
            new_j += 1;
          }
        }
      }
    }
  }
  return status;
}

bool s21_matrix_correct(matrix_t *matrix) {
  int rule_1 = matrix != NULL && matrix->matrix != NULL;
  if (!rule_1) {
    return false;
  }
  int rule_2 = matrix->rows > 0 && matrix->columns > 0;
  if (!rule_2) {
    return false;
  }
  return true;
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
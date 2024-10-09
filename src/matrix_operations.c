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

int s21_transpose(matrix_t *A, matrix_t *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  bool r2 = !s21_matrix_correct(result);
  bool r3 = A->rows != result->columns || A->columns != result->rows;
  if (r1 || r2) {
    status = WRONG_MATRIX;
  } else if (r3) {
    status = CALCULATION_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return status;
}

double s21_determinant_recursive(matrix_t *A) {
  bool r1 = !s21_matrix_correct(A);
  if (r1) {
    return 0;
  }
  double det = 0;
  for (int i = 0; i < A->columns; i++) {
    matrix_t m = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &m);
    s21_minor_matrix(A, i, &m);
    s21_print_matrix(&m);
    if (m.rows == 2 && m.columns == 2) {
      double res = 0;
      s21_2x2_determinant(&m, &res);
      det += pow(-1, 1 + i + 1) * A->matrix[0][i] * res;
    } else {
      det += pow(-1, 1 + i + 1) * A->matrix[0][i] * s21_determinant_recursive(&m);
    }
  }
  return det;
}

int s21_determinant(matrix_t *A, double *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  bool r2 = result == NULL;
  if (r1) {
    status = WRONG_MATRIX;
  } else if (r2) {
    status = CALCULATION_ERROR;
  } else {
    if (A->rows == 2 && A->columns == 2) {
      s21_2x2_determinant(A, result);
    } else {
      *result = s21_determinant_recursive(A);
    }
  }
  return status;
}

//EXAMPLE

// double find_det(matrix_t *A, double *total) {
//   *total = 0;
//   double det5x5 = 0;
//   for (int i = 0; i < A->columns; i++) {
//     matrix_t w = {0};
//     double det4x4 = 0;
//     s21_create_matrix(A->rows - 1, A->columns - 1, &w);
//     s21_minor_matrix(A, i, &w);
//     s21_print_matrix(&w);
//     for (int j = 0; j < w.columns; j++) {
//       matrix_t m = {0};
//       double det3x3 = 0;
//       s21_create_matrix(w.rows - 1, w.columns - 1, &m);
//       s21_minor_matrix(&w, j, &m);
//       s21_print_matrix(&m);
//       for (int r = 0; r < m.columns; r++) {
//         matrix_t n = {0};
//         double det2x2 = 0;
//         s21_create_matrix(m.rows - 1, m.columns - 1, &n);
//         s21_minor_matrix(&m, r, &n);
//         s21_print_matrix(&n);
//         s21_2x2_determinant(&n, &det2x2);
//         det3x3 += det2x2 * m.matrix[0][r] * pow(-1, 1 + r + 1);
//       }
//       det4x4 += det3x3 * w.matrix[0][j] * pow(-1, 1 + j + 1);
//     }
//     det5x5 += det4x4 * A->matrix[0][i] * pow(-1, 1 + i + 1);
//   }
//   printf("tot: %lf", det5x5);
//   return 0;
// }

// 5x5: Total = -142
// 1st: 3 * -116 = -348 +

// 2nd: 4 * -180 = -720 -
//-240 +
//-135 -
// 60   +
// 135  -

// 3d: 2 * -45 = -90 +
//-176 +
//-225 -
// 32   +
// 126  -

// 4th: 1 * -68 = -68 -
// 64  +
// 300 -
// 96  +
//-72 -

// 5th: 4 * -123 = -492
//-48 +
// 225 -
// 126 +
//-24 -
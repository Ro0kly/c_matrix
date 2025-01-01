#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  operation_status status = OK;
  bool r1 = !s21_matrix_correct(A);
  if (r1) {
    status = WRONG_MATRIX;
  } else if (!result) {
    status = CALCULATION_ERROR;
  } else if (A->rows == 1 || A->columns == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2 && A->columns == 2) {
    s21_2x2_determinant(A, result);
  } else if (A->rows == A->columns) {
    *result = s21_determinant_recursive(A);
  }
  return status;
}

// EXAMPLE

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
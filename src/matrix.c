#include <time.h>

#include "matrix_operations.h"

int main() {
  matrix_t matrix_a = {0};
  s21_create_matrix(3, 3, &matrix_a);

  matrix_a.matrix[0][0] = 9;
  matrix_a.matrix[0][1] = 2;
  matrix_a.matrix[0][2] = 3;

  matrix_a.matrix[1][0] = 1;
  matrix_a.matrix[1][1] = 6;
  matrix_a.matrix[1][2] = 4;

  matrix_a.matrix[2][0] = 2;
  matrix_a.matrix[2][1] = -2;
  matrix_a.matrix[2][2] = -4;

  s21_print_matrix(&matrix_a);
  double res = 0;
  s21_determinant(&matrix_a, &res);
  printf("res: %lf", res);
  return 0;
}

// matrix_a.matrix[0][0] = 3;
//   matrix_a.matrix[0][1] = 4;
//   matrix_a.matrix[0][2] = 2;
//   matrix_a.matrix[0][3] = 1;
//   matrix_a.matrix[0][4] = 4;

//   matrix_a.matrix[1][0] = 4;
//   matrix_a.matrix[1][1] = 5;
//   matrix_a.matrix[1][2] = 3;
//   matrix_a.matrix[1][3] = 1;
//   matrix_a.matrix[1][4] = 3;

//   matrix_a.matrix[2][0] = 5;
//   matrix_a.matrix[2][1] = 6;
//   matrix_a.matrix[2][2] = 5;
//   matrix_a.matrix[2][3] = 5;
//   matrix_a.matrix[2][4] = 5;

//   matrix_a.matrix[3][0] = 4;
//   matrix_a.matrix[3][1] = 2;
//   matrix_a.matrix[3][2] = 1;
//   matrix_a.matrix[3][3] = 4;
//   matrix_a.matrix[3][4] = 1;

//   matrix_a.matrix[4][0] = 4;
//   matrix_a.matrix[4][1] = 6;
//   matrix_a.matrix[4][2] = 7;
//   matrix_a.matrix[4][3] = 1;
//   matrix_a.matrix[4][4] = 3; // 5x5

// matrix_a.matrix[0][0] = 9;
//   matrix_a.matrix[0][1] = 1;
//   matrix_a.matrix[0][2] = 2;
//   matrix_a.matrix[0][3] = 3;

//   matrix_a.matrix[1][0] = 6;
//   matrix_a.matrix[1][1] = 4;
//   matrix_a.matrix[1][2] = 2;
//   matrix_a.matrix[1][3] = -2;

//   matrix_a.matrix[2][0] = -4;
//   matrix_a.matrix[2][1] = 4;
//   matrix_a.matrix[2][2] = 1;
//   matrix_a.matrix[2][3] = 5;

//   matrix_a.matrix[3][0] = 7;
//   matrix_a.matrix[3][1] = 2;
//   matrix_a.matrix[3][2] = 3;
//   matrix_a.matrix[3][3] = 2; // 4x4

// matrix_a.matrix[0][0] = 9;
// matrix_a.matrix[0][1] = 2;
// matrix_a.matrix[0][2] = 3;

// matrix_a.matrix[1][0] = 1;
// matrix_a.matrix[1][1] = 6;
// matrix_a.matrix[1][2] = 4;

// matrix_a.matrix[2][0] = 2;
// matrix_a.matrix[2][1] = -2;
// matrix_a.matrix[2][2] = -4; // 3x3

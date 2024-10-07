#include "matrix_operations.h"

int main() {
  matrix_t matrix_a = {0};
  s21_create_matrix(3, 2, &matrix_a);
  matrix_a.matrix[0][0] = 1;
  matrix_a.matrix[0][1] = 4;
  matrix_a.matrix[1][0] = 2;
  matrix_a.matrix[1][1] = 5;
  matrix_a.matrix[2][0] = 3;
  matrix_a.matrix[2][1] = 6;

  s21_print_matrix(&matrix_a);

  matrix_t matrix_b = {0};
  s21_create_matrix(2, 2, &matrix_b);
  matrix_b.matrix[0][0] = 1;
  matrix_b.matrix[0][1] = -1;
  //matrix_b.matrix[0][2] = 1;
  matrix_b.matrix[1][0] = 2;
  matrix_b.matrix[1][1] = 3;
  //matrix_b.matrix[1][2] = 4;
  s21_print_matrix(&matrix_b);

  matrix_t res = {0};
  s21_create_matrix(3, 2, &res);
  printf("status: %d\n", s21_mult_matrix(&matrix_a, &matrix_b, &res));
  s21_print_matrix(&res);
  return 0;
}

// matrix_t matrix_a = {0};
// s21_create_matrix(3, 3, &matrix_a);
// matrix_a.matrix[0][0] = 1;
// matrix_a.matrix[0][1] = 2;
// matrix_a.matrix[0][2] = 3;
// matrix_a.matrix[1][0] = 4;
// matrix_a.matrix[1][1] = 5;
// matrix_a.matrix[1][2] = 6;
// matrix_a.matrix[2][0] = 1;
// matrix_a.matrix[2][1] = 2;
// matrix_a.matrix[2][2] = 3;

// s21_print_matrix(&matrix_a);

// matrix_t matrix_b = {0};
// s21_create_matrix(3, 3, &matrix_b);
// matrix_b.matrix[0][0] = 2;
// matrix_b.matrix[0][1] = 3;
// matrix_b.matrix[0][2] = 1;
// matrix_b.matrix[1][0] = 4;
// matrix_b.matrix[1][1] = 5;
// matrix_b.matrix[1][2] = 3;
// matrix_b.matrix[2][0] = 5;
// matrix_b.matrix[2][1] = 7;
// matrix_b.matrix[2][2] = 8;
// s21_print_matrix(&matrix_b);
#include "matrix_operations.h"

int main() {
  matrix_t matrix_a = {0};
  s21_create_matrix(4, 4, &matrix_a);
  s21_fill_matrix(&matrix_a, 5);
  s21_print_matrix(&matrix_a);

  matrix_t matrix_b = {0};
  s21_create_matrix(4, 4, &matrix_b);
  s21_fill_matrix(&matrix_b, 2);
  s21_print_matrix(&matrix_b);

  matrix_t matrix_res = {0};
  s21_create_matrix(4, 4, &matrix_res);

  // printf("eq: %d", s21_eq_matrix(&matrix,&matrix_b));
  int status = s21_sub_matrix(&matrix_a, &matrix_b, &matrix_res);
  printf("status: %d\n",status);
  s21_print_matrix(&matrix_res);

  return 0;
}
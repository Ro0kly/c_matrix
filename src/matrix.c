#include "matrix_operations.h"

int main() {
  matrix_t matrix = {0};
  printf("matrix A address: %p\n", &matrix);
  s21_create_matrix(4, 4, &matrix);
  printf("matrix A address after create: %p\n", &matrix);
  s21_fill_matrix(&matrix, 4.1234567);
  s21_print_matrix(&matrix);
  //s21_remove_matrix(&matrix);

  printf("matrix A address after remove: %p\n", &matrix);

  matrix_t matrix_b = {0};
  printf("matrix B address: %p\n", &matrix_b);
  s21_create_matrix(4, 4, &matrix_b);
  s21_fill_matrix(&matrix_b, 4.1234567);
  s21_print_matrix(&matrix_b);
  //s21_remove_matrix(&matrix_b);

  printf("eq: %d", s21_eq_matrix(&matrix,&matrix_b));
  return 0;
}
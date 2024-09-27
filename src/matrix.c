#include "matrix_operations.h"

int main() {
  matrix_t *matrix = NULL;
  matrix = malloc(sizeof(matrix_t));
  s21_create_matrix(3, 3, matrix);
  s21_fill_matrix(matrix, 4);
  s21_print_matrix(matrix);
  return 0;
}
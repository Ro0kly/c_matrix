#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum { OK, WRONG_MATRIX, CALCULATION_ERROR } operation_status;

int s21_print_matrix(matrix_t *matrix);
int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_fill_matrix(matrix_t *matrix, double value);
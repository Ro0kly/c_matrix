#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum { OK, WRONG_MATRIX, CALCULATION_ERROR } operation_status;

int s21_print_matrix(matrix_t *matrix);
bool s21_matrix_correct(matrix_t *matrix);
bool s21_matrices_same_size(matrix_t *A, matrix_t *B);
int s21_fill_matrix(matrix_t *matrix, double value);
int s21_2x2_determinant(matrix_t *matrix, double *result);
int s21_3x3_determinant(matrix_t *matrix, double *result);
int s21_minor_matrix(matrix_t *matrix, int exclude_column_index, matrix_t *result);
// void find_det(matrix_t *A, double *result, double mult, double high_minor_val);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
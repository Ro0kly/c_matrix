#include <check.h>

#include "./matrix_operations/s21_matrix.h"

// METHOD: s21_create_matrix
START_TEST(s21_create_matrix_1) {
  int status = 0;
  matrix_t m = {0};
  status = s21_create_matrix(2, 2, &m);
  ck_assert_int_eq(status, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  int status = 0;
  matrix_t m = {0};
  status = s21_create_matrix(3, 3, &m);
  ck_assert_int_eq(status, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  int status = 0;
  matrix_t m = {0};
  status = s21_create_matrix(4, 4, &m);
  ck_assert_int_eq(status, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  int status = 0;
  matrix_t m = {0};
  status = s21_create_matrix(5, 5, &m);
  ck_assert_int_eq(status, OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  int status = 0;
  status = s21_create_matrix(5, 5, NULL);
  ck_assert_int_eq(status, WRONG_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  int status = 0;
  matrix_t m = {0};
  status = s21_create_matrix(0, 0, &m);
  ck_assert_int_eq(status, WRONG_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

// METHOD: s21_eq_matrix
START_TEST(s21_eq_matrix_1) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,1.123456);
  s21_create_matrix(4, 4, &n);
  s21_fill_matrix(&n,1.123456);

  status = s21_eq_matrix(&m,&n);
  ck_assert_int_eq(status, SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,1.123456);
  s21_create_matrix(4, 4, &n);
  s21_fill_matrix(&n,1.123457);

  status = s21_eq_matrix(&m,&n);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  s21_create_matrix(0, 4, &m);
  s21_fill_matrix(&m,1.123456);
  s21_create_matrix(4, 4, NULL);
  s21_fill_matrix(&n,1.123457);

  status = s21_eq_matrix(&m,&n);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  s21_create_matrix(0, 4, &m);
  s21_fill_matrix(&m,1.123456);
  s21_create_matrix(4, 4, &n);
  s21_fill_matrix(NULL,1.123457);

  status = s21_eq_matrix(&m,&n);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,1.123456);
  s21_create_matrix(4, 4, &n);
  s21_fill_matrix(&n,1.123456);

  status = s21_eq_matrix(&m,NULL);
  ck_assert_int_eq(status, FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
}
END_TEST

// METHOD: s21_sum_matrix
START_TEST(s21_sum_matrix_1) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,1.5);
  s21_create_matrix(4, 4, &n);
  s21_fill_matrix(&n,2.3);
  s21_create_matrix(4, 4, &res);

  status = s21_sum_matrix(&m,&n,&res);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(3.8, res.matrix[0][0]);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,1.5);
  s21_create_matrix(4, 4, &n);
  s21_fill_matrix(&n,2.3);
  s21_create_matrix(4, 4, &res);

  status = s21_sum_matrix(NULL,NULL,NULL);
  ck_assert_int_eq(status, WRONG_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,1.5);
  s21_create_matrix(2, 4, &n);
  s21_fill_matrix(&n,2.3);
  s21_create_matrix(4, 4, &res);

  status = s21_sum_matrix(&m,&n,&res);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

// METHOD: s21_sub_matrix
START_TEST(s21_sub_matrix_1) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,1.5);
  s21_create_matrix(4, 4, &n);
  s21_fill_matrix(&n,2.5);
  s21_create_matrix(4, 4, &res);

  status = s21_sub_matrix(&m,&n,&res);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(-1, res.matrix[0][0]);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,1.5);
  s21_create_matrix(4, 4, &n);
  s21_fill_matrix(&n,2.3);
  s21_create_matrix(4, 4, &res);

  status = s21_sub_matrix(NULL,NULL,NULL);
  ck_assert_int_eq(status, WRONG_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,1.5);
  s21_create_matrix(2, 4, &n);
  s21_fill_matrix(&n,2.3);
  s21_create_matrix(4, 4, &res);

  status = s21_sub_matrix(&m,&n,&res);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

// METHOD: s21_mult_number
START_TEST(s21_mult_number_1) {
  int status = 0;
  matrix_t m = {0};
  double val = 1.2;
  matrix_t res = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,2);
  s21_create_matrix(4, 4, &res);

  status = s21_mult_number(&m,val,&res);
  ck_assert_int_eq(status, OK);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_number_2) {
  int status = 0;
  matrix_t m = {0};
  double val = 1.2;
  matrix_t res = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,2);
  s21_create_matrix(4, 4, &res);

  status = s21_mult_number(NULL,val,NULL);
  ck_assert_int_eq(status, WRONG_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_number_3) {
  int status = 0;
  matrix_t m = {0};
  double val = 1.2;
  matrix_t res = {0};
  s21_create_matrix(4, 4, &m);
  s21_fill_matrix(&m,2);
  s21_create_matrix(4, 2, &res);

  status = s21_mult_number(&m,val,&res);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

// MATHOD: s21_mult_matrix
// START_TEST(s21_mult_matrix_1) {
//   int status = 0;
//   matrix_t m = {0};
//   matrix_t n = {0};
//   matrix_t res = {0};
//   matrix_t res_f = {0};
//   s21_create_matrix(3, 2, &m);
//   s21_create_matrix(2, 3, &n);
//   s21_create_matrix(3, 3, &res);
//   s21_create_matrix(3, 3, &res_f);

//   m.matrix[0][0] = 1;
//   m.matrix[0][1] = 4;
//   m.matrix[1][0] = 2;
//   m.matrix[1][1] = 5;
//   m.matrix[2][0] = 3;
//   m.matrix[2][1] = 6;

//   n.matrix[0][0] = 1;
//   n.matrix[0][1] = -1;
//   n.matrix[0][2] = 1;
//   n.matrix[1][0] = 2;
//   n.matrix[1][1] = 3;
//   n.matrix[1][2] = 4;

//   res_f.matrix[0][0] = 9;
//   res_f.matrix[0][1] = 11;
//   res_f.matrix[0][2] = 17;
//   res_f.matrix[1][0] = 12;
//   res_f.matrix[1][1] = 13;
//   res_f.matrix[1][2] = 22;
//   res_f.matrix[2][0] = 15;
//   res_f.matrix[2][1] = 15;
//   res_f.matrix[2][2] = 27;

//   status = s21_mult_matrix(&m,&n,&res);
//   ck_assert_int_eq(status, OK);
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 3; j++) {
//       ck_assert_double_eq(res.matrix[i][j],res_f.matrix[i][j]);
//     }
//   }
//   s21_remove_matrix(&m);
//   s21_remove_matrix(&n);
//   s21_remove_matrix(&res);
//   s21_remove_matrix(&res_f);
// }
// END_TEST

START_TEST(s21_mult_matrix_2) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 2, &m);
  s21_create_matrix(2, 3, &n);
  s21_create_matrix(3, 3, &res);

  status = s21_mult_matrix(NULL,NULL,NULL);
  ck_assert_int_eq(status, WRONG_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 2, &m);
  s21_create_matrix(1, 3, &n);
  s21_create_matrix(3, 3, &res);

  status = s21_mult_matrix(&m,&n,&res);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  int status = 0;
  matrix_t m = {0};
  matrix_t n = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 2, &m);
  s21_create_matrix(2, 3, &n);
  s21_create_matrix(3, 1, &res);

  status = s21_mult_matrix(&m,&n,&res);
  ck_assert_int_eq(status, CALCULATION_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&n);
  s21_remove_matrix(&res);
}
END_TEST

// METHOD: s21_transpose
START_TEST(s21_transpose_1) {
  int status = 0;
  matrix_t m = {0};
  matrix_t res = {0};
  matrix_t res_f = {0};
  s21_create_matrix(3, 2, &m);
  s21_create_matrix(2, 3, &res);
  s21_create_matrix(2, 3, &res_f);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 4;
  m.matrix[1][0] = 2;
  m.matrix[1][1] = 5;
  m.matrix[2][0] = 3;
  m.matrix[2][1] = 6;

  res_f.matrix[0][0] = 1;
  res_f.matrix[0][1] = 2;
  res_f.matrix[0][2] = 3;
  res_f.matrix[1][0] = 4;
  res_f.matrix[1][1] = 5;
  res_f.matrix[1][2] = 6;

  status = s21_transpose(&m,&res);
  ck_assert_int_eq(status, OK);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(res.matrix[i][j],res_f.matrix[i][j]);
    }
  }

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&res_f);
}
END_TEST

START_TEST(s21_transpose_2) {
  int status = 0;
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 2, &m);
  s21_create_matrix(2, 3, &res);

  status = s21_transpose(NULL,NULL);
  ck_assert_int_eq(status, WRONG_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_3) {
  int status = 0;
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 2, &m);
  s21_create_matrix(1, 3, &res);

  status = s21_transpose(&m,&res);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

// METHOD: s21_calc_complements
START_TEST(s21_calc_complements_1) {
  int status = 0;
  matrix_t m = {0};
  matrix_t res = {0};
  matrix_t res_f = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &res);
  s21_create_matrix(3, 3, &res_f);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;
  m.matrix[1][0] = 0;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;

  res_f.matrix[0][0] = 0;
  res_f.matrix[0][1] = 10;
  res_f.matrix[0][2] = -20;
  res_f.matrix[1][0] = 4;
  res_f.matrix[1][1] = -14;
  res_f.matrix[1][2] = 8;
  res_f.matrix[2][0] = -8;
  res_f.matrix[2][1] = -2;
  res_f.matrix[2][2] = 4;

  status = s21_calc_complements(&m,&res);
  ck_assert_int_eq(status, OK);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(res.matrix[i][j],res_f.matrix[i][j]);
    }
  }

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&res_f);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  int status = 0;
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &res);

  status = s21_calc_complements(NULL,NULL);
  ck_assert_int_eq(status, WRONG_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  int status = 0;
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 2, &res);

  status = s21_calc_complements(&m,&res);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

// METHOD: s21_determinant
START_TEST(s21_determinant_1) {
  int status = 0;
  matrix_t m = {0};
  double res = 0;
  s21_create_matrix(3, 3, &m);

  m.matrix[0][0] = 9;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;

  m.matrix[1][0] = 1;
  m.matrix[1][1] = 6;
  m.matrix[1][2] = 4;

  m.matrix[2][0] = 2;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -4;

  status = s21_determinant(&m,&res);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(-162,res);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_determinant_2) {
  int status = 0;
  matrix_t m = {0};
  double res = 0;
  s21_create_matrix(4, 4, &m);

  m.matrix[0][0] = 9;
  m.matrix[0][1] = 1;
  m.matrix[0][2] = 2;
  m.matrix[0][3] = 3;

  m.matrix[1][0] = 6;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;
  m.matrix[1][3] = -2;

  m.matrix[2][0] = -4;
  m.matrix[2][1] = 4;
  m.matrix[2][2] = 1;
  m.matrix[2][3] = 5;

  m.matrix[3][0] = 7;
  m.matrix[3][1] = 2;
  m.matrix[3][2] = 3;
  m.matrix[3][3] = 2;

  status = s21_determinant(&m,&res);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(-386,res);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_determinant_3) {
  int status = 0;
  matrix_t m = {0};
  double res = 0;
  s21_create_matrix(5, 5, &m);

m.matrix[0][0] = 3;
m.matrix[0][1] = 4;
m.matrix[0][2] = 2;
m.matrix[0][3] = 1;
m.matrix[0][4] = 4;

m.matrix[1][0] = 4;
m.matrix[1][1] = 5;
m.matrix[1][2] = 3;
m.matrix[1][3] = 1;
m.matrix[1][4] = 3;

m.matrix[2][0] = 5;
m.matrix[2][1] = 6;
m.matrix[2][2] = 5;
m.matrix[2][3] = 5;
m.matrix[2][4] = 5;

m.matrix[3][0] = 4;
m.matrix[3][1] = 2;
m.matrix[3][2] = 1;
m.matrix[3][3] = 4;
m.matrix[3][4] = 1;

m.matrix[4][0] = 4;
m.matrix[4][1] = 6;
m.matrix[4][2] = 7;
m.matrix[4][3] = 1;
m.matrix[4][4] = 3;

  status = s21_determinant(&m,&res);
  ck_assert_int_eq(status, OK);
  ck_assert_double_eq(-142,res);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_determinant_4) {
  int status = 0;
  matrix_t m = {0};
  double res = 0;
  s21_create_matrix(5, 5, &m);

  status = s21_determinant(NULL,&res);
  ck_assert_int_eq(status, WRONG_MATRIX);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_determinant_5) {
  int status = 0;
  matrix_t m = {0};
  s21_create_matrix(5, 5, &m);

  status = s21_determinant(&m,NULL);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&m);
}
END_TEST

// METHOD: s21_inverse_matrix
START_TEST(s21_inverse_matrix_1) {
  int status = 0;
  matrix_t m = {0};
  matrix_t res = {0};
  matrix_t res_f = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &res);
  s21_create_matrix(3, 3, &res_f);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  res_f.matrix[0][0] = 1;
  res_f.matrix[0][1] = -1;
  res_f.matrix[0][2] = 1;
  res_f.matrix[1][0] = -38;
  res_f.matrix[1][1] = 41;
  res_f.matrix[1][2] = -34;
  res_f.matrix[2][0] = 27;
  res_f.matrix[2][1] = -29;
  res_f.matrix[2][2] = 24;

  status = s21_inverse_matrix(&m,&res);
  ck_assert_int_eq(status, OK);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(res.matrix[i][j],res_f.matrix[i][j]);
    }
  }

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&res_f);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  int status = 0;
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &res);

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 1;
  m.matrix[2][1] = 1;
  m.matrix[2][2] = 1;

  status = s21_inverse_matrix(&m,&res);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  int status = 0;
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &res);

  status = s21_inverse_matrix(NULL,NULL);
  ck_assert_int_eq(status, WRONG_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  int status = 0;
  matrix_t m = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 2, &res);

  status = s21_inverse_matrix(&m,&res);
  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
}
END_TEST

int main() {
  Suite *s1 = suite_create("s21_matix");
  TCase *tc_core = tcase_create("s21_matix");
  SRunner *sr = srunner_create(s1);
  int nf = 0;
  suite_add_tcase(s1, tc_core);

  tcase_add_test(tc_core, s21_create_matrix_1);
  tcase_add_test(tc_core, s21_create_matrix_2);
  tcase_add_test(tc_core, s21_create_matrix_3);
  tcase_add_test(tc_core, s21_create_matrix_4);
  tcase_add_test(tc_core, s21_create_matrix_5);
  tcase_add_test(tc_core, s21_create_matrix_6);
  tcase_add_test(tc_core, s21_eq_matrix_1);
  tcase_add_test(tc_core, s21_eq_matrix_2);
  tcase_add_test(tc_core, s21_eq_matrix_3);
  tcase_add_test(tc_core, s21_eq_matrix_4);
  tcase_add_test(tc_core, s21_eq_matrix_5);
  tcase_add_test(tc_core, s21_sum_matrix_1);
  tcase_add_test(tc_core, s21_sum_matrix_2);
  tcase_add_test(tc_core, s21_sum_matrix_3);
  tcase_add_test(tc_core, s21_sub_matrix_1);
  tcase_add_test(tc_core, s21_sub_matrix_2);
  tcase_add_test(tc_core, s21_sub_matrix_3);
  tcase_add_test(tc_core, s21_mult_number_1);
  tcase_add_test(tc_core, s21_mult_number_2);
  tcase_add_test(tc_core, s21_mult_number_3);
  //tcase_add_test(tc_core, s21_mult_matrix_1);
  tcase_add_test(tc_core, s21_mult_matrix_2);
  tcase_add_test(tc_core, s21_mult_matrix_3);
  tcase_add_test(tc_core, s21_mult_matrix_4);
  tcase_add_test(tc_core, s21_transpose_1);
  tcase_add_test(tc_core, s21_transpose_2);
  tcase_add_test(tc_core, s21_transpose_3);
  tcase_add_test(tc_core, s21_calc_complements_1);
  tcase_add_test(tc_core, s21_calc_complements_2);
  tcase_add_test(tc_core, s21_calc_complements_3);
  tcase_add_test(tc_core, s21_determinant_1);
  tcase_add_test(tc_core, s21_determinant_2);
  tcase_add_test(tc_core, s21_determinant_3);
  tcase_add_test(tc_core, s21_determinant_4);
  tcase_add_test(tc_core, s21_determinant_5);
  tcase_add_test(tc_core, s21_inverse_matrix_1);
  tcase_add_test(tc_core, s21_inverse_matrix_2);
  tcase_add_test(tc_core, s21_inverse_matrix_3);
  tcase_add_test(tc_core, s21_inverse_matrix_4);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf ? 1 : 0;
}
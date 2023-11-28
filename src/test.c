#include <check.h>
#include <math.h>
#include <stdio.h>

#include "my_math.h"
#define PREC 0.000001f


START_TEST(test_abs) {
    int x = 0;
    long int stdx = 0;
    long int my_x = 0;

    // test zero
    stdx = abs(x);
    my_x = my_abs(x);
    ck_assert_int_eq(stdx, my_x);

    // test positive
    x = 26;
    stdx = abs(x);
    my_x = my_abs(x);
    ck_assert_int_eq(stdx, my_x);

    // test negative
    x = -26;
    stdx = abs(x);
    my_x = my_abs(x);
    ck_assert_int_eq(stdx, my_x);

    // test int_min
    x = INT32_MIN;
    stdx = abs(x);
    my_x = my_abs(x);
    ck_assert_int_eq(stdx, my_x);
}
END_TEST



START_TEST(test_fabs) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zero
    stdx = fabs(x);
    my_x = my_fabs(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative zero
    x = -0;
    stdx = fabs(x);
    my_x = my_fabs(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 26.62;
    stdx = fabs(x);
    my_x = my_fabs(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative real
    x = -sqrt(26.62);
    stdx = fabs(x);
    my_x = my_fabs(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative inf
    x = -INFINITY;
    my_x = my_fabs(x);
    ck_assert_ldouble_infinite(my_x);

    // test NaN
    x = NAN;
    my_x = my_fabs(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST



START_TEST(test_floor) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test 1: zero
    stdx = floor(x);
    my_x = my_floor(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test 2: negative zero
    x = -0;
    stdx = floor(x);
    my_x = my_floor(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test 3: positive
    x = 26.62;
    stdx = floor(x);
    my_x = my_floor(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test 3.1: positive
    x = pow(26.62, 0.62);
    stdx = floor(x);
    my_x = my_floor(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test 3.2: positive
    x = sin(26.62);
    stdx = floor(x);
    my_x = my_floor(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test 3.3: positive
    x = exp(266.62);
    stdx = floor(x);
    my_x = my_floor(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test 4: negative real
    x = -sqrt(26.62);
    stdx = floor(x);
    my_x = my_floor(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test 5: negative inf
    x = -INFINITY;
    my_x = my_floor(x);
    ck_assert_ldouble_infinite(my_x);

    // test 6: NaN
    x = NAN;
    my_x = my_floor(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST



START_TEST(test_ceil) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;
    // test zero
    stdx = ceil(x);
    my_x = my_ceil(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative zero
    x = -0;
    stdx = ceil(x);
    my_x = my_ceil(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 26.62;
    stdx = ceil(x);
    my_x = my_ceil(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = pow(26.62, 0.62);
    stdx = ceil(x);
    my_x = my_ceil(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = exp(26.62);
    stdx = ceil(x);
    my_x = my_ceil(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = sin(26.62);
    stdx = ceil(x);
    my_x = my_ceil(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative real
    x = -sqrt(26.26);
    stdx = ceil(x);
    my_x = my_ceil(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative inf
    x = -INFINITY;
    my_x = my_ceil(x);
    ck_assert_ldouble_infinite(my_x);

    // test NaN
    x = NAN;
    my_x = my_ceil(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST



START_TEST(test_fmod) {
    double x = 0.0, y = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zeros
    my_x = my_fmod(x, y);
    ck_assert_ldouble_nan(my_x);

    // test positive
    x = 26.62; y = 62;                              // 26.620000
    stdx = fmod(x, y);
    my_x = my_fmod(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive 2
    x = 1261; y = 62;                              // 26.620000
    stdx = fmod(x, y);
    my_x = my_fmod(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive 3
    x = pow(1261, 0.62); y = 62;
    stdx = fmod(x, y);
    my_x = my_fmod(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive 4
    x = sin(62); y = tan(62);
    stdx = fmod(x, y);
    my_x = my_fmod(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive 5
    x = exp(26); y = exp(0.62);
    stdx = fmod(x, y);
    my_x = my_fmod(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative real
    x = -sqrt(26.26); y = -92;
    stdx = fmod(x, y);                              // -5.124451
    my_x = my_fmod(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative zero y
    x = 26; y = -0;
    my_x = my_fmod(x, y);
    ck_assert_ldouble_nan(my_x);

    // test negative zero x
    x = -0; y = 62;
    stdx = fmod(x, y);                              // 0
    my_x = my_fmod(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test infs
    x = -INFINITY; y = INFINITY;
    my_x = my_fmod(x, y);
    ck_assert_ldouble_nan(my_x);

    // test x NaN
    x = NAN; y = 26.62;
    my_x = my_fmod(x, y);
    ck_assert_ldouble_nan(my_x);

    // test y NaN
    x = 26.62; y = NAN;
    my_x = my_fmod(x, y);
    ck_assert_ldouble_nan(my_x);

    // test y inf
    x = 62.62; y = INFINITY;
    stdx = fmod(x, y);                              // 62.620000
    my_x = my_fmod(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test x inf
    x = INFINITY; y = 62.62;
    my_x = my_fmod(x, y);
    ck_assert_ldouble_nan(my_x);

    // test crazy shit
    x = -INFINITY; y = NAN;
    my_x = my_fmod(x, y);
    ck_assert_ldouble_nan(my_x);

    // test maximum double
    x = 9999999999999999999999.0, y = 10;
    stdx = fmod(x, y);
    my_x = my_fmod(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);
}
END_TEST



START_TEST(test_sqrt) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zero
    stdx = sqrt(x);                                 // 0.000000
    my_x = my_sqrt(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 26.62;
    stdx = sqrt(x);                                 // 5.159457
    my_x = my_sqrt(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive less 0
    x = 0.62;
    stdx = sqrt(x);                                 // 0.787401
    my_x = my_sqrt(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative real
    x = -sqrt(26.26);
    my_x = my_sqrt(x);
    ck_assert_ldouble_nan(my_x);

    // test negative zero
    x = -0;
    stdx = sqrt(x);                                 // 0.000000
    my_x = my_sqrt(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative inf
    x = -INFINITY;
    stdx = sqrt(x);                                 // nan
    my_x = my_sqrt(x);
    ck_assert_ldouble_nan(my_x);

    // test NaN
    x = NAN;                               // nan
    my_x = my_sqrt(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST



START_TEST(test_pow) {
    double x = 0.0, y = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zeros
    stdx = pow(x, y);                               // 1.000000
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test + zero x and - odd integer
    x = 0; y = -63;
    my_x = my_pow(x, y);
    ck_assert_ldouble_infinite(my_x);

    // test + zero x and exponent is negative, finite, and is a non-integer
    x = 0; y = -62.26;
    my_x = my_pow(x, y);
    ck_assert_ldouble_infinite(my_x);

    // test + zero x and exponent is - inf
    x = 0; y = -INFINITY;
    my_x = my_pow(x, y);
    ck_assert_ldouble_infinite(my_x);

    // test + zero x and exponent is positive non-integer
    x = 0; y = 6.2;
    stdx = pow(x, y);
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative zero x
    x = -0; y = -63;
    my_x = my_pow(x, y);
    ck_assert_ldouble_infinite(my_x);

    // test negative zero y
    x = 26; y = -0;
    stdx = pow(x, y);
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test NAN and negative zero y
    x = NAN; y = -0;
    stdx = pow(x, y);
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test -1 and inf
    x = -1; y = INFINITY;
    stdx = pow(x, y);
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test 1 and nan
    x = 1; y = NAN;
    stdx = pow(x, y);
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 26.62; y = 6;
    stdx = pow(x, y);
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 0.62; y = 0.6;
    stdx = pow(x, y);
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = -0.62; y = 0.6;
    my_x = my_pow(x, y);
    ck_assert_ldouble_nan(my_x);

    // test positive
    x = 0.62; y = -0.6;
    stdx = pow(x, y);
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test base is finite and negative and exponent is finite and non-integer
    x = -26; y = 62.2;
    my_x = my_pow(x, y);
    ck_assert_ldouble_nan(my_x);

    // test negative reals
    x = -sqrt(26.26); y = -92;
    stdx = pow(x, y);                               // inf
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test real x
    x = -0.62; y = INFINITY;
    stdx = pow(x, y);                               // inf
    my_x = my_pow(x, y);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test infs
    x = -INFINITY; y = INFINITY;
    my_x = my_pow(x, y);
    ck_assert_ldouble_infinite(my_x);

    // test x NaN
    x = NAN; y = 26.62;
    my_x = my_pow(x, y);
    ck_assert_ldouble_nan(my_x);

    // test y NaN
    x = 26.62; y = NAN;
    my_x = my_pow(x, y);
    ck_assert_ldouble_nan(my_x);

    // test y inf
    x = 62.62; y = INFINITY;
    my_x = my_pow(x, y);
    ck_assert_ldouble_infinite(my_x);

    // test x inf
    x = INFINITY; y = 62.62;
    my_x = my_pow(x, y);
    ck_assert_ldouble_infinite(my_x);

    // test crazy shit
    x = -INFINITY; y = NAN;
    my_x = my_pow(x, y);
    ck_assert_ldouble_nan(my_x);

    const double test[15] = {+0., -0., 0.687, -0.687, 1., -1., 2., -2., 3., -3., 3.687, -3.687,
                        INFINITY, -INFINITY, NAN};
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            x = test[i];
            y = test[j];
            stdx = pow(x, y);
            my_x = my_pow(x, y);
            if (stdx != stdx) {
                ck_assert_ldouble_nan(my_x);
            } else if (stdx == stdx + 1) {
                ck_assert_ldouble_infinite(my_x);
            } else {
                ck_assert_ldouble_eq_tol(stdx, my_x, PREC);
            }
        }
    }
}
END_TEST



START_TEST(test_exp) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zero
    stdx = exp(x);
    my_x = my_exp(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test one
    x = 1;
    stdx = exp(x);
    my_x = my_exp(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 6.62;
    stdx = exp(x);
    my_x = my_exp(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative less 1
    x = -0.62;
    stdx = exp(x);
    my_x = my_exp(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative real
    x = -sqrt(26.26);
    stdx = exp(x);
    my_x = my_exp(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative zero
    x = -0;
    stdx = exp(x);
    my_x = my_exp(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative inf
    x = -INFINITY;
    stdx = exp(x);
    my_x = my_exp(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive inf
    x = INFINITY;
    my_x = my_exp(x);
    ck_assert_ldouble_infinite(my_x);

    // test NaN
    x = NAN;
    my_x = my_exp(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST



START_TEST(test_log) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zero
    my_x = my_log(x);
    ck_assert_ldouble_infinite(my_x);

    // test negative zero
    x = -0;
    my_x = my_log(x);
    ck_assert_ldouble_infinite(my_x);

    // test positive
    x = 26.62;
    stdx = log(x);
    my_x = my_log(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive less 0
    x = 0.687;
    stdx = log(x);
    my_x = my_log(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive less 0
    x = 0.000687;
    stdx = log(x);
    my_x = my_log(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative less 0
    x = -0.826;
    my_x = my_log(x);
    ck_assert_ldouble_nan(my_x);

    // test one
    x = 1;
    stdx = log(x);
    my_x = my_log(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative real
    x = -sqrt(26.26);
    my_x = my_log(x);
    ck_assert_ldouble_nan(my_x);

    // test negative inf
    x = -INFINITY;
    my_x = my_log(x);
    ck_assert_ldouble_nan(my_x);

    // test positive inf
    x = INFINITY;
    my_x = my_log(x);
    ck_assert_ldouble_infinite(my_x);

    // test NaN
    x = NAN;
    my_x = my_log(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST



START_TEST(test_acos) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zero
    x = 0;
    stdx = acos(x);
    my_x = my_acos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test one
    x = 1;
    stdx = acos(x);
    my_x = my_acos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 0.62;
    stdx = acos(x);
    my_x = my_acos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative
    x = -0.26;
    stdx = acos(x);
    my_x = my_acos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test 1/2
    x = 1/2;
    stdx = acos(x);
    my_x = my_acos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test -1/2
    x = -1/2;
    stdx = acos(x);
    my_x = my_acos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test sqrt(2)/2
    x = sqrt(2)/2;
    stdx = acos(x);
    my_x = my_acos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test -sqrt(2)/2
    x = -sqrt(2)/2;
    stdx = acos(x);
    my_x = my_acos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test sqrt(3)/2
    x = sqrt(3)/2;
    stdx = acos(x);
    my_x = my_acos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test -sqrt(3)/2
    x = sqrt(3)/2;
    stdx = acos(x);
    my_x = my_acos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test out positive
    x = 62.62;
    my_x = my_acos(x);
    ck_assert_ldouble_nan(my_x);

    // test out negative
    x = -26.26;
    my_x = my_acos(x);
    ck_assert_ldouble_nan(my_x);

    // test - inf
    x = -INFINITY;
    my_x = my_acos(x);
    ck_assert_ldouble_nan(my_x);

    // test + inf
    x = +INFINITY;
    my_x = my_acos(x);
    ck_assert_ldouble_nan(my_x);

    // test nan
    x = NAN;
    my_x = my_acos(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST



START_TEST(test_asin) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zero
    x = 0;
    stdx = asin(x);
    my_x = my_asin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test one
    x = 1;
    stdx = asin(x);
    my_x = my_asin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 0.62;
    stdx = asin(x);
    my_x = my_asin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative
    x = -0.26;
    stdx = asin(x);
    my_x = my_asin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test 1/2
    x = 1/2;
    stdx = asin(x);
    my_x = my_asin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test -1/2
    x = -1/2;
    stdx = asin(x);
    my_x = my_asin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test sqrt(2)/2
    x = sqrt(2)/2;
    stdx = asin(x);
    my_x = my_asin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test -sqrt(2)/2
    x = -sqrt(2)/2;
    stdx = asin(x);
    my_x = my_asin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test sqrt(3)/2
    x = sqrt(3)/2;
    stdx = asin(x);
    my_x = my_asin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test -sqrt(3)/2
    x = sqrt(3)/2;
    stdx = asin(x);
    my_x = my_asin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test out positive
    x = 62.62;
    my_x = my_asin(x);
    ck_assert_ldouble_nan(my_x);

    // test out negative
    x = -26.26;
    my_x = my_asin(x);
    ck_assert_ldouble_nan(my_x);

    // test - inf
    x = -INFINITY;
    my_x = my_asin(x);
    ck_assert_ldouble_nan(my_x);

    // test + inf
    x = +INFINITY;
    my_x = my_asin(x);
    ck_assert_ldouble_nan(my_x);

    // test nan
    x = NAN;
    my_x = my_asin(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST



START_TEST(test_atan) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zero
    x = 0;
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test one
    x = 1;
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 0.62;
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test sqrt(3)/3
    x = sqrt(3)/3;
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test sqrt(3)
    x = sqrt(3);
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test -sqrt(3)/3
    x = -sqrt(3)/3;
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test -sqrt(3)
    x = -sqrt(3);
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);


    // test negative
    x = -0.26;
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test big positive
    x = 62.62;
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test big negative
    x = -26.26;
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test - inf
    x = -INFINITY;
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test + inf
    x = +INFINITY;
    stdx = atan(x);
    my_x = my_atan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test nan
    x = NAN;
    my_x = my_atan(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST

START_TEST(test_cos) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zero
    x = 0;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test one
    x = 1;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 0.62;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative
    x = -0.26;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi
    x = MY_PI;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi
    x = -MY_PI;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi/3
    x = MY_PI/3;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi/3
    x = -MY_PI/3;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi/2
    x = MY_PI_2;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi/2
    x = -MY_PI_2;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi/4
    x = MY_PI_4;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi/4
    x = -MY_PI_4;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test big positive
    x = 62.62;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test big negative
    x = -26.26;
    stdx = cos(x);
    my_x = my_cos(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test - inf
    x = -INFINITY;
    my_x = my_cos(x);
    ck_assert_ldouble_nan(my_x);

    // test + inf
    x = +INFINITY;
    my_x = my_cos(x);
    ck_assert_ldouble_nan(my_x);

    // test nan
    x = NAN;
    my_x = my_cos(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST



START_TEST(test_sin) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zero
    x = 0;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test one
    x = 1;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 0.62;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi
    x = MY_PI;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi
    x = -MY_PI;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi/3
    x = MY_PI/3;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi/3
    x = -MY_PI/3;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi/2
    x = MY_PI_2;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi/2
    x = -MY_PI_2;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi/4
    x = MY_PI_4;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi/4
    x = -MY_PI_4;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative
    x = -0.26;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test big positive
    x = 62.62;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test big negative
    x = -26.26;
    stdx = sin(x);
    my_x = my_sin(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test - inf
    x = -INFINITY;
    my_x = my_sin(x);
    ck_assert_ldouble_nan(my_x);

    // test + inf
    x = +INFINITY;
    my_x = my_sin(x);
    ck_assert_ldouble_nan(my_x);

    // test nan
    x = NAN;
    my_x = my_sin(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST


START_TEST(test_tan) {
    double x = 0.0;
    long double stdx = 0.0;
    long double my_x = 0.0;

    // test zero
    x = 0;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test one
    x = 1;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive
    x = 0.62;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi
    x = MY_PI;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi
    x = -MY_PI;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi/3
    x = MY_PI/3;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi/3
    x = -MY_PI/3;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // // test positive pi/2
    // x = MY_PI_2;
    // stdx = tan(x);
    // my_x = my_tan(x);
    // ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // // test negative pi/2
    // x = -MY_PI_2;
    // stdx = tan(x);
    // my_x = my_tan(x);
    // ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test positive pi/4
    x = MY_PI_4;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative pi/4
    x = -MY_PI_4;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test negative
    x = -0.26;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test big positive
    x = 62.62;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test big negative
    x = -26.26;
    stdx = tan(x);
    my_x = my_tan(x);
    ck_assert_ldouble_eq_tol(stdx, my_x, PREC);

    // test - inf
    x = -INFINITY;
    my_x = my_tan(x);
    ck_assert_ldouble_nan(my_x);

    // test + inf
    x = +INFINITY;
    my_x = my_tan(x);
    ck_assert_ldouble_nan(my_x);

    // test nan
    x = NAN;
    my_x = my_tan(x);
    ck_assert_ldouble_nan(my_x);
}
END_TEST





Suite *string_suite(void) {
    Suite *s = suite_create("math.h base");
    TCase *simple_tc = tcase_create("Simple functions");
    TCase *exp_tc = tcase_create("Exponential functions");
    TCase *trig_tc = tcase_create("Trigonometrical functions");


    suite_add_tcase(s, simple_tc);
    tcase_add_test(simple_tc, test_abs);
    tcase_add_test(simple_tc, test_fabs);
    tcase_add_test(simple_tc, test_floor);
    tcase_add_test(simple_tc, test_ceil);
    tcase_add_test(simple_tc, test_fmod);
    tcase_add_test(simple_tc, test_sqrt);

    suite_add_tcase(s, exp_tc);
    tcase_add_test(exp_tc, test_pow);
    tcase_add_test(exp_tc, test_exp);
    tcase_add_test(exp_tc, test_log);

    suite_add_tcase(s, trig_tc);
    tcase_add_test(trig_tc, test_acos);
    tcase_add_test(trig_tc, test_asin);
    tcase_add_test(trig_tc, test_atan);
    tcase_add_test(trig_tc, test_cos);
    tcase_add_test(trig_tc, test_sin);
    tcase_add_test(trig_tc, test_tan);
    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = string_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}

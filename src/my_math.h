#ifndef SRC_MY_MATH_H_
#define SRC_MY_MATH_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MY_E 2.71828182845904523536028747135266250        /* e */
#define MY_LN1_25 0.22314355131420976485756568763463292   /* ln(2) */
#define MY_LN2 0.69314718055994528622676398299518041      /* ln(2) */
#define MY_LN10 2.30258509299404590109361379290930927     /* ln(10) */
#define MY_PI 3.14159265358979323846264338327950288       /* pi */
#define MY_PI_2 1.57079632679489661923132169163975144     /* pi/2 */
#define MY_PI_4 0.78539816339744830961566084581987572     /* pi/4 */
#define MY_ATAN0_5 0.46364760900080614902663000975735485  /* arctg(0.5) */
#define MY_ATAN1 0.78539816339744827899949086713604629    /* arctg(1) */
#define MY_ATAN1_5 0.98279372324732905408239957978366874  /* arctg(1.5) */
#define MY_INF 1.0 / 0.0
#define MY_NAN 0.0 / 0.0

typedef long double (*core_func)(double x);
typedef int (*taylor_deriv)(int i);

long int my_abs(int x);
long double my_acos(double x);
long double my_asin(double x);
long double my_atan(double x);
long double my_ceil(double x);
long double my_cos(double x);
long double my_exp(double x);
long double my_fabs(double x);
long double my_floor(double x);
long double my_fmod(double x, double y);
long double my_log(double x);
long double my_pow(double base, double exp);
long double my_sin(double x);
long double my_sqrt(double x);
long double my_tan(double x);
#endif  // SRC_MY_MATH_H_

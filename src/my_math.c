#include "my_math.h"

long int my_abs(int x) {
    return x >= 0 ? x : -x;
}

long double my_fabs(double x) {
    return x >= 0.0 ? x : -x;
}

long double my_floor(double x) {
    long double result = 0;
    if (x == MY_INF) {
        result = MY_INF;
    } else if (x == -MY_INF) {
        result = -MY_INF;
    } else if (x != x) {
        result = MY_NAN;
    } else if (x >= LLONG_MAX || x <= LLONG_MIN) {
        result = x;
    } else {
        long long number = (long long)x;
        result = (long double)number;
        if (x < 0 && result != x) {
        result -= 1;
        }
    }
    return result;
}

long double my_ceil(double x) {
    return (my_floor(x) == x) ? x : my_floor(x) + 1;
}

long double my_fmod(double x, double y) {
    long double result = 0;
    if (y == 0) {
        result = MY_NAN;
    } else if (x == MY_INF || x == -MY_INF) {
        result = MY_NAN;
    } else if (x != x || y != y) {
        result = MY_NAN;
    } else if (y == MY_INF || y == -MY_INF) {
        result = x;
    } else if (x == +0.0) {
        result = x;
    } else {
        if ((x / y) < 0) {
        result = x - y * (my_ceil(x / y));
        } else {
        result = x - y * (my_floor(x / y));
        }
    }
    return result;
}

long double my_fmax(long double x, long double y) {
    return (x > y) ? x : y;
}

long double tayl(taylor_deriv deriv_func, double x, int max_deg) {
    long double over_fact = 1.0, deg_x = 1, res = 0;
    for (int i = 0; i < max_deg; i++) {
        static long double deriv = 0;
        deriv = (double)deriv_func(i);
        over_fact /= my_fmax(1.0, (long double)i);
        res += deriv * deg_x * over_fact;
        deg_x *= x;
    }
    return res;
}

double trig_shift(double x) {
    double p_x = ((long double)x / (2 * MY_PI));
    return x - 2 * MY_PI * my_floor(p_x);
}

int sin_deriv(int i) {
    return (i % 2 == 0) ? 0 : (i % 4 == 1) ? 1 : -1;
}

long double my_sin(double x) {
    return tayl(sin_deriv, trig_shift(x), 30);
}

int cos_deriv(int i) {
    return (i % 2 == 1) ? 0 : (i % 4 == 0) ? 1 : -1;
}

long double my_cos(double x) {
    return tayl(cos_deriv, trig_shift(x), 30);
}

long double my_tan(double x) {
    return my_sin(x) / my_cos(x);
}

int exp_deriv(int i) {
    int res = 0;
    if (i >= 0)
        res = 1;
    return res;
}

long double simple_exp(double base, long long exp) {
    double res = 1.0;
    for (int i = 0; i < my_abs(exp); i++) {
        res = res * base;
    }
    if (exp < 0) {
        res = 1 / res;
    }
    return (long double)res;
}

long double my_exp(double x) {
    long double result = 0;
    long long i = (long long)x;
    if (x == MY_INF) {
        result = MY_INF;
    } else if (x == -MY_INF) {
        result = 0;
    } else {
        result = simple_exp(MY_E, i) * tayl(exp_deriv, my_fmod(x, 1.0), 20);
    }
    return result;
}

long double my_sqrt(double x) {
    long double res = 0;
    if (x >= 0.0) {
        res = my_pow(x, 0.5);
    } else {
        res = MY_NAN;
    }
    return res;
}

long double my_log(double x) {
    long double res = 0;
    if (x != x || x < 0) {
        res = MY_NAN;
    } else if (x == MY_INF) {
        res = MY_INF;
    } else if (x == +0.0) {
        res = -MY_INF;
    } else {
        int deg10 = 0;
        while (x >= 10.0) {
            deg10++;
            x *= 0.1;
        }
        int deg2 = 0;
        while (x >= 2.0) {
            deg2++;
            x *= 0.5;
        }
        while (x <= 0.5) {
            deg2--;
            x *= 2;
        }
        int deg1_25 = 0;
        while (x >= 1.25) {
            deg1_25++;
            x *= 0.8;
        }
        while (x <= 0.8) {
            deg1_25--;
            x *= 1.25;
        }
        long double deg_x = 1.0, tayl_sign = -1.0;
        for (double i = 1.0; i < 30.0; i++) {
            deg_x *= x - 1.0;
            tayl_sign *= -1.0;
            res += tayl_sign * deg_x / i;
        }
        res += deg10 * MY_LN10 + deg2 * MY_LN2 + deg1_25 * MY_LN1_25;
    }
    return res;
}

long double my_asin(double x) {
    long double res = 0;
    if (x == 1.0) {
        res = MY_PI_2;
    } else if (x == -1.0) {
        res = -MY_PI_2;
    } else if (x > -1.0 && x < 1.0) {
        res = my_atan(x / my_sqrt(1 - x * x));
    } else {
        res = MY_NAN;
    }
    return res;
}

long double my_acos(double x) {
    long double res = 0;
    if (x >= -1.0 && x <= 1.0) {
        res = MY_PI_2 - my_asin(x);
    } else {
        res = MY_NAN;
    }
    return res;
}

long double my_atan(double x) {
    long double res = 0.0;
    if (x != x) {
        res = MY_NAN;
    } else if (x == MY_INF) {
        res = MY_PI_2;
    } else if (x == -MY_INF) {
        res = -MY_PI_2;
    } else if (x < 0) {
        res = -my_atan(-x);
    } else if (x < 0.4375) {
        res = x;
        long double step = x, mult = x * x;
        for (double i = 1.0; i < 15.0; i++) {
            step *= -1.0 * mult;
            res += step / (2.0 * i + 1.0);
        }
    } else if (x < 0.6875) {
        res = MY_ATAN0_5 + my_atan((x - 0.5) / (1 + x * 0.5));
    } else if (x < 1.1875) {
        res = MY_ATAN1 + my_atan((x - 1) / (1 + x));
    } else if (x < 2.4375) {
        res = MY_ATAN1_5 + my_atan((x - 1.5) / (1 + x * 1.5));
    } else {
        res = MY_PI_2 + my_atan((-1) / x);
    }
    return res;
  }


long double my_pow(double base, double exp) {
    long double res = 0.0;
    if (1.0 / base == MY_INF && exp < 0.0 && my_fmod(exp, 2.0) == -1.0) {
        res = MY_INF;
    } else if (1.0 / base == -MY_INF && exp < 0.0 && my_fmod(exp, 2.0) == -1.0) {
        res = -MY_INF;
    } else if ((1.0 / base == -MY_INF || 1.0 / base == MY_INF) && exp < 0.0) {
        res = MY_INF;
    } else if (1.0 / base == MY_INF && exp > 0.0 && my_fmod(exp, 2.0) == 1.0) {
        res = +0.0;
    } else if (1.0 / base == -MY_INF && exp > 0.0 && my_fmod(exp, 2.0) == 1.0) {
        res = -0.0;
    } else if ((1.0 / base == -MY_INF || 1.0 / base == MY_INF) && exp > 0.0) {
        res = +0.0;
    } else if (base == -1.0 && (exp == MY_INF || exp == -MY_INF)) {
        res = 1.0;
    } else if (base == 1.0 || exp == -0.0) {
        res = 1.0;
    } else if (base < 0 && base != -MY_INF && exp != MY_INF
                && exp != -MY_INF && my_fmod(exp, 1.0) != 0.0) {
        res = MY_NAN;
    } else if (exp == -MY_INF && base > -1.0 && base < 1.0) {
        res = MY_INF;
    } else if (exp == -MY_INF && (base < -1.0 || base > 1.0)) {
        res = +0.0;
    } else if (exp == MY_INF && base > -1.0 && base < 1.0) {
        res = +0.0;
    } else if (exp == MY_INF && (base < -1.0 || base > 1.0)) {
        res = MY_INF;
    } else if (base == -MY_INF && exp < 0.0 && my_fmod(exp, 2.0) == -1.0) {
        res = -0.0;
    } else if (base == -MY_INF && exp < 0.0) {
        res = +0.0;
    } else if (base == -MY_INF && exp > 0.0 && my_fmod(exp, 2.0) == 1.0) {
        res = -MY_INF;
    } else if (base == -MY_INF && exp > 0.0) {
        res = MY_INF;
    } else if (base == MY_INF && exp < 0.0) {
        res = +0.0;
    } else if (base == MY_INF && exp > 0.0) {
        res = MY_INF;
    } else if (base != base || exp != exp) {
        res = MY_NAN;
    } else {
        long double ldbase = (long double)base;
        long long i = (long long)exp;
        res = my_exp(my_log(my_fabs(base)) * my_fmod(exp, 1.0));
        res *= simple_exp(ldbase, i);
    }
    return res;
}

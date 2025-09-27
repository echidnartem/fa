#include "..\include\flags.h"

void solve(double * result, const double * e, const double * a, const double * b, const double * c) {
    result[0] = 0.0;
    result[1] = 0.0;
    result[2] = 0.0;
    if (fabs(*a) <= *e) {
        if (fabs(*b) <= *e) {
            if (fabs(*c) <= *e) result[0] = -1.0;
        } else {
            result[0] = 1.0;
            result[1] = -*c / *b;
        }
        return;
    }

    double d = *b * *b - 4 * *a * *c;

    if (d > *e) {
        result[0] = 2.0;
        result[1] = (-*b + sqrt(d)) / (2 * *a);
        result[2] = (-*b - sqrt(d)) / (2 * *a);
    } else if (fabs(d) <= *e) {
        result[0] = 1.0;
        result[1] = -*b / (2 * *a);
    }
}

double * q(const double * e, const double * a, const double * b, const double * c) {
    double * result = (double*)malloc(sizeof(double) * 3);
    if (!result) {
        return NULL;
    }

    solve(result, e, a, b, c);
    return result;
}

bool m(const int * a, const int * b) {
    if (*a % *b == 0) return true;
    return false;
}

bool t(const double * e, const double * a, const double * b, const double * c){
    if (*a <= *e || *b <= *e || *c <= *e) return false;
    if (!(*a + *b - *c > *e && *a + *c - *b > *e && *b + *c - *a > *e)) return false;

    return (fabs(*a * *a + *b * *b - *c * *c) < *e) ||
           (fabs(*a * *a + *c * *c - *b * *b) < *e) ||
           (fabs(*b * *b + *c * *c - *a * *a) < *e);
}
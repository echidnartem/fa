#include <stdio.h>
#include "include/epsilon_calculation.h"
#include "include/pi_calculation.h"
#include "include/ln2_calculation.h"
#include "include/sqrt2_calculation.h"
#include "include/gamma_calculation.h"


enum {
    SUCCESS = 0,
    ERR_MEMORY_ALLOC
};

int main() {
    double precision = 0.0001; 
    
    double e_limit = limit_e(precision);
    double e_series = series_e(precision); 
    double e_equation = equation_e(precision);
    
    double pi_limit = limit_pi(precision);
    double pi_series = series_pi(precision);
    double pi_equation = equation_pi(precision);
    
    double ln2_limit = limit_ln2(precision);
    double ln2_series = series_ln2(precision);
    double ln2_equation = equation_ln2(precision);
    
    double sqrt2_limit = limit_sqrt2(precision);
    double sqrt2_series = series_sqrt2(precision);
    double sqrt2_equation = equation_sqrt2(precision);
    
    double g_limit = limit_g(precision);
    double g_series = series_g(precision);
    double g_equation = equation_g(precision);
    
    printf("Euler's number is:         %.10lf %.10lf %.10lf\n", e_limit, e_series, e_equation);
    printf("Pi is:                     %.10lf %.10lf %.10lf\n", pi_limit, pi_series, pi_equation);
    printf("ln(2) is:                  %.10lf %.10lf %.10lf\n", ln2_limit, ln2_series, ln2_equation);
    printf("sqrt(2) is:                %.10lf %.10lf %.10lf\n", sqrt2_limit, sqrt2_series, sqrt2_equation);
    printf("Euler-Mascheroni gamma is: %.10lf %.10lf %.10lf\n", g_limit, g_series, g_equation);
    
    return SUCCESS;
}
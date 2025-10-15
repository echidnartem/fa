#ifndef FRACTIONS_H
#define FRACTIONS_H

#include <stdbool.h>
#include <stdarg.h>
#include "mathf.h"


long long get_denominator(err * error, double num);
bool has_finite_representation(err * error, double num, int base);
bool * is_finite_representation(err * error, int base, int count, ...);

#endif
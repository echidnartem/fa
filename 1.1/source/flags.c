#include <math.h>
#include "..\include\flags.h"

bool h(int * result, const ll * number) {
    bool flag = false;
    for (int x = 1; x < 101; x++) {
        if (x % *number == 0) {
            result[x - 1] = 1;
            flag = true;
        }
    }
    return flag;
}

bool p(const ll * number) {
    if (*number == 1) return false;

    for (ll x = 2; x * x <= *number; x++) {
        if (*number % x == 0) {
            return false;
        }
    }
    return true;
}

int s(char * result, const ll * number) {
    ll temp = *number;
    int index = 31, n;
    while (temp != 0) {
        n = temp % 16;
        if (n > 9) {
            result[index] = (n - 10) + 'A';
        } else {
            result[index] = n + '0';
        }
        temp /= 16;
        --index;
    }
    return ++index;
}

void e(ll * result, const ll * number) {
    for (int base = 1; base <= 10; base++) {
        for (ll power = 1; power <= *number; power++) {
            result[(base - 1) * *number + (power - 1)] = pow(base, power);
        }
    }
}

ll a(const ll * number) {
    ll result = 0;
    for (ll x = 1; x <= *number; x++) {
        result += x;
    }
    return result;
}

ll f(const ll * number) {
    ll result = 1;
    if (*number == 0) return result;
    for (ll x = 2; x <= *number; x++) {
        result *= x;
    }
    return result;
}
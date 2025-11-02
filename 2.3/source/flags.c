#include "../include/flags.h"

Status Ro(char * buf, int * wr, va_list l) {
    int num = va_arg(l, int);
    if (num <= 0 || num > 3999)
        return CANNOT_BE_ROMAN;

    const char * lit[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int val[]   = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    int i = 0, written = 0;
    while (num > 0) {
        while (num >= val[i]) {
            num -= val[i];
            int len = (int)strlen(lit[i]);
            memcpy(buf + written, lit[i], len);
            written += len;
        }
        ++i;
    }

    *wr = written;
    return SUCCESS;
}

Status Zr(char * buf, int * wr, va_list l) {
    unsigned int n = va_arg(l, unsigned int);
    const int maxCnt = 55;
    long long fib[maxCnt];

    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < maxCnt; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    char tmp[maxCnt];
    memset(tmp, '0', sizeof(tmp));

    for (int i = maxCnt - 1; i >= 0; --i) {
        if (fib[i] <= n) {
            tmp[i] = '1';
            n -= fib[i];
            if (i > 0)              // по теореме Цекендорфа любое положительное целое число можно единственным образом представить 
                tmp[i - 1] = '0';   // как сумму непоследовательных чисел Фибоначчи (без двух соседних в последовательности)
        }
    }

    int end = maxCnt - 1;
    while (end > 0 && tmp[end] == '0')
        --end;

    int written = 0;
    for (int i = 0; i <= end; ++i)
        buf[written++] = tmp[i];

    *wr = written;
    return SUCCESS;
}

static char getLit(int n, int base) {
    int rem = n % base;
    return (rem > 9) ? ('A' + rem - 10) : ('0' + rem);
}

static Status toBase(char * buf, int * wr, long long n, int base, bool up) {
    if (base < 2 || base > 36)
        base = 10;

    bool neg = n < 0;
    if (neg) n = -n;

    char tmp[70];
    int len = 0;

    if (n == 0)
        tmp[len++] = '0';

    while (n > 0) {
        char ch = getLit(n, base);
        tmp[len++] = up ? (char)toupper((unsigned char)ch) : (char)tolower((unsigned char)ch);
        n /= base;
    }

    if (neg)
        tmp[len++] = '-';

    for (int i = 0; i < len; ++i)
        buf[i] = tmp[len - 1 - i];

    *wr = len;
    return SUCCESS;
}

Status Cv(char * buf, int * wr, va_list l) {
    int n = va_arg(l, int);
    int base = va_arg(l, int);
    return toBase(buf, wr, n, base, false);
}

Status CV(char * buf, int * wr, va_list l) {
    int n = va_arg(l, int);
    int base = va_arg(l, int);
    return toBase(buf, wr, n, base, true);
}

static int getNum(char ch) {
    if (isdigit((unsigned char)ch)) return ch - '0';
    if (isupper((unsigned char)ch)) return 10 + ch - 'A';
    return 10 + ch - 'a';
}

static Status validateNum(const char * n, int base, bool up) {
    if (!n || !n[0])
        return UNCORRECT_NUM;
    
    if (base < 2 || base > 36) return INVALID_BASE;

    int mx = 0;
    for (int i = (n[0] == '-'); n[i]; ++i) {
        if (!isalnum((unsigned char)n[i]))
            return UNCORRECT_NUM;
        if (isupper((unsigned char)n[i]) && !up)
            return SHOULD_BE_LOWER;
        if (islower((unsigned char)n[i]) && up)
            return SHOULD_BE_UPPER;
        mx = max(mx, getNum(n[i]));
    }

    if (mx >= base)
        return NOT_IN_BASE;

    return SUCCESS;
}

static Status fromBase(char * buf, int * wr, va_list l, bool up) {
    char * n = va_arg(l, char*);
    int base = va_arg(l, int);

    Status cor = validateNum(n, base, up);
    if (cor != SUCCESS)
        return cor;

    bool neg = (n[0] == '-');
    long long num = 0;

    for (int i = (neg ? 1 : 0); n[i]; ++i) {
        int val = getNum(n[i]);
        if (num > (LLONG_MAX - val) / base)
            return LONG_OVERFLOW;
        num = num * base + val;
    }
    if (neg) num = -num;

    return toBase(buf, wr, num, 10, false);
}

Status to(char * buf, int * wr, va_list l) { return fromBase(buf, wr, l, false); }
Status TO(char * buf, int * wr, va_list l) { return fromBase(buf, wr, l, true); }

static Status getDump(char * buf, int * wr, const unsigned char * pi, int bcnt) {
    int written = 0;
    for (int i = 0; i < bcnt; ++i) {
        for (int j = 7; j >= 0; --j)
            buf[written++] = (pi[i] & (1 << j)) ? '1' : '0';

        if (i != bcnt - 1)
            buf[written++] = ' ';
    }
    *wr = written;
    return SUCCESS;
}

Status mi(char * buf, int * wr, va_list l) {
    int n = va_arg(l, int);
    return getDump(buf, wr, (unsigned char*)&n, sizeof(int));
}

Status mu(char * buf, int * wr, va_list l) {
    unsigned int n = va_arg(l, unsigned int);
    return getDump(buf, wr, (unsigned char*)&n, sizeof(unsigned int));
}

Status md(char * buf, int * wr, va_list l) {
    double n = va_arg(l, double);
    return getDump(buf, wr, (unsigned char*)&n, sizeof(double));
}

Status mf(char * buf, int * wr, va_list l) {
    float n = (float)va_arg(l, double);
    return getDump(buf, wr, (unsigned char*)&n, sizeof(float));
}
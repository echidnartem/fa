#include "../include/function.h"


// Разберём на примере 1 (0001)
unsigned int bit_add_one(unsigned int value) {
    unsigned int carry = 1; 
    while (carry) {
        unsigned int overlap = value & carry; // 0001 & 0001 = 0001 (при следующей итерации: 0000 & 0010 = 0000)
        value = value ^ carry; // 0001 ^ 0001 = 0000 (при следующей итерации: 0000 ^ 0010 = 0010)
        carry = overlap << 1; // 0001 << 1 = 0010 (при следующей итерации: 0000 << 1 = 0000)
    }
    return value;
}

// Разберём на примере 2 (0010)
unsigned int bit_sub_one(unsigned int value) {
    unsigned int borrow = 1;
    while (borrow) {
        unsigned int need_borrow = (~value) & borrow; // 1101 & 0001 = 0001 (при следующей итерации: 1100 & 0010 = 0000)
        value = value ^ borrow; // 0010 ^ 0001 = 0011 (при следующей итерации: 0011 ^ 0010 = 0001)
        borrow = need_borrow << 1; // 0001 << 1 = 0010 (при следующей итерации: 0000 << 1 = 0000)
    }
    return value;
}

void translate_to_base(const unsigned int number, const int r, char * output) {
    if (r < 1 || r > 5) return;

    unsigned int num_copy = number;
    const unsigned int bit_count = 64;
    char temp_str[bit_add_one(bit_count)];

    for (unsigned int i = 0; i < bit_count; i = bit_add_one(i)) {
        temp_str[i] = '0';
    }
    temp_str[bit_count] = '\0';

    int position = bit_sub_one(bit_count);
    const unsigned int mask = bit_sub_one(1 << r); // при r = 1: 0001, при r = 2: 0011, при r = 3: 0111 и так далее
    const char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (num_copy != 0) {
        unsigned int remainder = num_copy & mask;
        temp_str[position] = alphabet[remainder];
        position = bit_sub_one(position);
        num_copy >>= r;
    }

    unsigned int first_non_zero = 0;
    for (; first_non_zero < bit_sub_one(bit_count); first_non_zero = bit_add_one(first_non_zero)) {
        if (temp_str[first_non_zero] != '0') break;
    }

    unsigned int out_index = 0;
    unsigned int src_index = first_non_zero;

    while (temp_str[src_index] != '\0') {
        output[out_index] = temp_str[src_index];
        out_index = bit_add_one(out_index);
        src_index = bit_add_one(src_index);
    }

    output[out_index] = '\0';
}

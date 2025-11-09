#ifndef TESTS_H
#define TESTS_H


#include <stdio.h>
#include <string.h>


void translate_to_base(unsigned int number, int r, char *output);

void test_r1();
void test_r2();
void test_r3();
void test_r4();
void test_r5();
void test_edge_cases();

void run_test(const char * title, unsigned int number, int r, const char * expected);

#endif

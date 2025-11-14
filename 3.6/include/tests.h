#ifndef TESTS_H
#define TESTS_H


#include <stdio.h>
#include <string.h>
#include "function.h"


void test_valid();
void test_invalid();
void test_edge_cases();

void run_test(const char * title, const char * input, bool expected);

#endif
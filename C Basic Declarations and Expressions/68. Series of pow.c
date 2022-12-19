// Copyright School 21 finchren 2022

/*
Task:
Write a C program to print the powers of 2 table for the power 0 to 10, both positive and negative
=======================================
n 2 to power n 2 to power -n
=======================================
0 1 1.000000000000
1 2 0.500000000000
2 4 0.250000000000
3 8 0.125000000000
4 16 0.062500000000
5 32 0.031250000000
6 64 0.015625000000
7 128 0.007812500000
8 256 0.003906250000
9 512 0.001953125000
10 1024 0.000976562500

✔ 1. Write a plan to complete the exercise
✔ 2.0 Pow
✔ 2.1 Function to get the line
✔ 3. Repeat in for loop until completed
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

double s21_pow(const double base, const double exponent);
void get_line(const double base, const double exponent);
void get_lines(const double base, double exponent);

int main() {
    double base = 2.0, exponent = 0;
    get_lines(base, exponent);
    return 0;
}

void get_lines(const double base, double exponent) {
    int max_num_lines = 10;
    for (int index = 0; index <= max_num_lines; ++index) {
        get_line(base, exponent);
        ++exponent;
    }
}

void get_line(const double base, const double exponent) {
    printf("%.0lf %.0lf %.12lf\n",
    exponent, s21_pow(base, exponent), s21_pow(base, exponent * -1));
}

double s21_pow(const double base, const double exponent) {
    double result = base;
    if (exponent > 0) {
        for (int index = 2; index <= exponent; ++index) {
            result *= base;
        }
    } else if (exponent < 0) {
        for (int index = 2; index <= exponent * -1; ++index) {
            result *= base;
        }
        result = 1.0 / result;
    } else {
        result = 1;
    }
    return result;
}

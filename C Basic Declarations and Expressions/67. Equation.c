// Copyright School 21 finchren 2022

/*
Task:
Write a C program to evaluate the equation y=xn when n is a non-negative integer
Input the values of x and n: 256
x=256.000000; n=0;
x to power n=1.000000

✔ 1. Write a plan to complete the exercise
✔ 2. Input and invalid input
✔ 3. Function to get the result and output
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum is_valid {
    FALSE,
    TRUE
};

int input_nums(double* x, double* n);
void ask_for_input();
void invalid_input();
int check_n(const double n);
void n_can_be_only_non_negative();
void get_result(const double x, const double n, double* y);
void output_result(const double y);

int main() {
    double x = FALSE, n = FALSE;
    if (input_nums(&x, &n)) {
        if (check_n(n)) {
            double y = FALSE;
            get_result(x, n, &y);
            output_result(y);
        } else {
            n_can_be_only_non_negative();
        }
    } else {
        invalid_input();
    }
    return 0;
}

void output_result(const double y) {
    printf("x to power n=%lf\n", y);
}

void get_result(const double x, const double n, double* y) {
    *y = x * n;
}

void n_can_be_only_non_negative() {
    printf("Value of n can be only non-negative\n"
    "Please try again\n");
}

int check_n(const double n) {
    return n >= 0 ? TRUE : FALSE;
}

void invalid_input() {
    printf("The script takes two decimal or floating point nums\n"
    "Which are divided by a space or a newline"
    "and have a newline at the end of the line\n");
}

void ask_for_input() {
    printf("Input the values of x and n: \n");
}

int input_nums(double* x, double* n) {
    int is_valid_input = FALSE;
    char newline = '\0';
    if (scanf("%lf %lf%c", x, n, &newline) && newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

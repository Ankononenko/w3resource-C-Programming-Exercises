// Copyright School 21 finchren 2022

/*
Task:
Write a C program that accepts a real number x and prints out the corresponding value of sin(1/x) using 4-decimal places
Input value of x: .6235
Value of sin(1/x) is 0.9995

✔ 1. Write a plan to complete the exercise
✔ 2. Input and invalid input
✔ 3. Function to convert
✔ 3.5 Output
✔ 4. Test
✔ 5. Cpplint test
6. Add and push
*/

#include <stdio.h>
#include <math.h>

enum is_valid {
    FALSE,
    TRUE
};

int input_x(double* x);
void invalid_input();
void x_to_sin(const double x, double* calculated_sin);
void output_result(const double calculated_sin);

int main() {
    double x = FALSE;
    if (input_x(&x)) {
        double calculated_sin = FALSE;
        x_to_sin(x, &calculated_sin);
        output_result(calculated_sin);
    } else {
        invalid_input();
    }
    return 0;
}

void output_result(const double calculated_sin) {
    printf("Value of sin(1/x) is %.4lf\n", calculated_sin);
}

void x_to_sin(const double x, double* calculated_sin) {
    *calculated_sin = sin(1.0/x);
}

int input_x(double* x) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input value of x: ");
    if (scanf("%lf%c", x, &newline) && newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

void invalid_input() {
    printf("Script takes only one number\n"
    "At the end only a newline is allowed\n");
}

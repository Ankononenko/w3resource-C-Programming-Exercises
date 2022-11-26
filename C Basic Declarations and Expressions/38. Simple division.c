// Copyright School 21 finchren 2022

/*
Write a program that reads two numbers and divide the first number by second number. If the division not possible print "Division not possible". Go to the editor
Test Data :
Input two numbers:
x: 25
y: 5
Expected Output: 5.0

✔ 1. Write a plan to complete the exercise
✔ 2. Take input
✔ 3. Invalid input
✔ 4. Function for division
✔ 5. Check if the division is possible
✔ 6. Output result
✔ 7. Test
✔ 8. Cpplint test
9. Git add, git push

*/

#include <stdio.h>

void ask_input();
int input_num(double* num);
void invalid_input();
void ask_x();
void ask_y();
void print_result(double result);
void print_zero_division();
void divide(double x, double y, double* result);

enum is_valid{
    FALSE,
    TRUE
};

int main() {
    ask_input();
    double x = 0;
    ask_x();
    if (input_num(&x)) {
        double result = 0;
        if (x == 0) {
            print_result(result);
        } else {
            double y = 0;
            ask_y();
            input_num(&y);
            if (y == 0) {
                print_zero_division();
            } else {
                divide(x, y, &result);
                print_result(result);
            }
        }
    } else {
        invalid_input();
    }

    return 0;
}

void divide(double x, double y, double* result) {
    *result = x / y;
}

void print_zero_division() {
    printf("Division by zero is not possible\n");
}

void print_result(double result) {
    printf("Result: %.1lf\n", result);
}

void ask_x() {
    printf("x: ");
}
void ask_y() {
    printf("y: ");
}

void invalid_input() {
    printf("Input can only be a number. One number at a time\n");
}

int input_num(double* num) {
    int is_valid_input = TRUE;
    char newline = '\n';
    if (!scanf("%lf%c", num, &newline)) {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

void ask_input() {
    printf("Input two numbers:\n");
}

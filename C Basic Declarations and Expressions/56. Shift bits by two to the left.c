// Copyright School 21 finchren 2022

/*
Task:

Write a C program to shift given data by two bits to the left
Input value : 2
Read the integer from keyboard-
Integer value = 2
The left shifted data is = 8

✔ 1. Write a plan to complete the exercise
✔ 2. Input values
✔ 3. Invalid input
✔ 4. Learn how to shift data by bits:
    Left shift: x << y (x: first operand, y: second operand)
    Is equivalent to multiplying x with 2^y (2 raised to power y): x = x * (y^2)= shifted to the left value
    Right shift: x >> y (x: first operand, y: second operand)
    Is equivalent to dividing x with 2^y: x = x / (y^2)= shifted to the rigth value
✔ 5. Function to shift the input data
✔ 6. Output the result
✔ 7. Test
✔ 8. Cpplint test
✔ 9. Add and push
*/

#include <stdio.h>
#include <math.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(int* num);
void invalid_input();
void shift_value_left(int* x, const int y);
void output_result(const int result);
void output_input_num(const int num);

int main() {
    int num = FALSE;
    if (input_num(&num)) {
        output_input_num(num);
        shift_value_left(&num, 2);
        output_result(num);
    } else {
        invalid_input();
    }
    return 0;
}

void output_result(const int result) {
    printf("The left shifted data is = %d\n", result);
}

void output_input_num(const int num) {
    printf("Integer value = %d\n", num);
}

void shift_value_left(int* x, const int y) {
    *x = *x << y;
    // Second way to solve the task
    // *x = *x * (pow(y, 2));
}

void invalid_input() {
    printf("Input takes only one number\n"
    "At the end of the line can be only a newline");
}

int input_num(int* num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input value: ");
    if (scanf("%d%c", num, &newline) && newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

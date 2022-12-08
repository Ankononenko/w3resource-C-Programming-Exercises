// Copyright School 21 finchren 2022

/*
Write a C program that swaps two numbers without using third variable
Input value for x & y:
Before swapping the value of x & y: 5 7
After swapping the value of x & y: 7 5

✔ 1. Write a plan to complete the exercise
✔ 2. Input values
✔ 3. Invalid input
✔ 4. Function to swap the values
✔ 5. Output the result
✔ 6. Test
✔ 7. Cpplint test
8. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(int* num);
void invalid_input();
void output_greeting();
void swap_value(int* x, int* y);
void output_before_swap(const int x, const int y);
void output_after_swap(const int x, const int y);

int main() {
    int x = FALSE;
    output_greeting();
    if (input_num(&x)) {
        int y = FALSE;
        if (input_num(&y)) {
            output_before_swap(x, y);
            swap_value(&x, &y);
            output_after_swap(x, y);
        } else {
            invalid_input();
        }
    } else {
        invalid_input();
    }
    return 0;
}

void output_before_swap(const int x, const int y) {
    printf("Before swapping the value of x & y: %d %d\n", x, y);
}

void output_after_swap(const int x, const int y) {
    printf("After swapping the value of x & y: %d %d\n", x, y);
}

void swap_value(int* x, int* y) {
    *x += *y;
    *y = *x - *y;
    *x = *x - *y;
}

void output_greeting() {
    printf("Input value for x & y: \n");
}

void invalid_input() {
    printf("Input takes only one number\n"
    "At the end of the line can be only a newline");
}

int input_num(int* num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    if (scanf("%d%c", num, &newline) && newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

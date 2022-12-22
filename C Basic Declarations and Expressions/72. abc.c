// Copyright School 21 finchren 2022

/*
Task:
72. Write a C program to remove any negative sign in front of a number
Input a value (negative):
Original value = -253
Absolute value = 253

✔ 1. Write a plan to complete the exercise
✔ 2. Input int and invalid input
✔ 3.1 abc function
✔ 3.2. Output result
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(int* num);
void invalid_input();
void s21_abc(int* num);
void output_result(const int num);

int main() {
    int num = FALSE;
    if (input_num(&num)) {
        s21_abc(&num);
        output_result(num);
    } else {
        invalid_input();
    }
    return 0;
}


void output_result(const int num) {
    printf("Absolute value = %d\n", num);
}

void s21_abc(int* num) {
    *num = *num <= 0 ? *num * -1 : *num;
}

void invalid_input() {
    printf("Only whole negative number is accepted\n"
    "At the end of the line should be a newline\n");
}

int input_num(int* num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input a value (negative): ");
    if (scanf("%d%c", num, &newline) && newline == '\n' && *num < 0) {
        is_valid_input = TRUE;
    }
    printf("Original value = %d\n", *num);
    return is_valid_input;
}

// Copyright School 21 finchren 2022

/*
Write a C program to print a number, it’s square and cube in a line, starting from 1 and print n lines. Accept number of lines (n, integer) from the user
Test Data :
Input number of lines: 5
Expected Output:
1 1 1
2 4 8
3 9 27
4 16 64
5 25 125

✔ 1. Write a plan to complete the exercise
✔ 2. Input
✔ 3. Invalid input
✔ 4. Output the result
✔ 4.1 Insert zeros so the result would inlined:
    00001 00001 00001
    00010 00020 00030
    00100 00200 00300
    01000 02000 03000
    10000 20000 30000
✔ 5. Test
✔ 6. Cpplint test
7. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(int *num);
void invalid_input();
void output_result(int num);
int get_max_len(int num);
void print_zeros(int num_zeros);
void s21_pow(int* result, int base, int exponent);
void output_a_row(int index, int num);

int main() {
    int num = FALSE;
    if (input_num(&num)) {
        output_result(num);
    } else {
        invalid_input();
    }
    return 0;
}

void print_zeros(int num_zeros) {
    for (int index = 0; index < num_zeros; ++index) {
        printf("%d", 0);
    }
}

void s21_pow(int* result, int base, int exponent) {
    if (!exponent && *result) {
        *result = 1;
    } else {
        *result = base;
        for (int index = 1; index < exponent; ++index) {
            *result *= base;
        }
    }
}

void output_result(int num) {
    for (int index = 1; index <= num; ++index) {
        output_a_row(index, num);
    }
}

void output_a_row(int index, int num) {
    int biggest_num = 0, max_num_zeros = 0, current_num_zeros = 0,
        exponent = 1, result = 0;
    s21_pow(&biggest_num, num, 3);
    max_num_zeros = get_max_len(biggest_num);
    for (int row_of_three = 0; row_of_three < 3; ++row_of_three) {
        s21_pow(&result, index, exponent);
        current_num_zeros = max_num_zeros - get_max_len(result);
        print_zeros(current_num_zeros);
        printf("%d ", result);
        ++exponent;
    }
    printf("\n");
}

int get_max_len(int num) {
    int num_zeros = 0;
    while (num > 9) {
        num/=10;
        ++num_zeros;
    }
    return num_zeros;
}

void invalid_input() {
    printf("The script takes only one number\n"
    "There can be only positive number of rows. No negative numbers allowed\n");
}

int input_num(int *num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    if (scanf("%d%c", num, &newline) && newline == '\n' && *num > 0) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

// Copyright 2022 finchren
/*
Write a C program to find Strong Numbers within a range of numbers
Test Data :
Input starting range of number : 1
Input ending range of number: 200
Expected Output :
The Strong numbers are :
1 2 145

Rework regular Sstrong number solution to work in a range:
 + 1. Correct the input
 + 2. Find numbers inside a range
 + 3. Test:
    Input: 1 and 1000000. Output:
    1 2 145 40585
 + 4. Cpplint
 + 5. Add and push
*/

#include <stdio.h>

int input_start();
int input_end();
void print_invalid_input();
int find_number_of_digits(int number);
int find_factorial(int number);
int power(int base, int exponent);
int is_strong(int number);
void print_is_strong(int start, int end);

int main() {
    int start = input_start();
    if (start >= 0) {
        int end = input_end();
        if (end >= 0) {
            print_is_strong(start, end);
        } else {
        print_invalid_input();
        }
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_is_strong(int start, int end) {
    printf("The Strong numbers are:\n");
    for (int i = start; i <= end; i++) {
        if (is_strong(i)) {
            printf("%d ", i);
        }
    }
}

int is_strong(int number) {
    int is_strong = 0, result = 0, temp_number = number,
    one_digit, number_of_digits = find_number_of_digits(number);
    for (int i = number_of_digits; i > 0; --i) {
        one_digit = temp_number / (1 * power(10, i - 1));
        temp_number -= one_digit * (1 * power(10, i - 1));
        result += find_factorial(one_digit);
    }
    if (number == result) {
        is_strong = 1;
    }
    return is_strong;
}

int find_factorial(int number) {
    int result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

int find_number_of_digits(int number) {
    int result = 0;
    for (int i = number; i > 0; i /= 10) {
        ++result;
    }
    return result;
}

int power(int base, int exponent) {
    int result = base;
    if (exponent != 0) {
        for (int i = 2; i <= exponent; i++) {
            result *= base;
        }
    } else {
        result = 1;
    }
    return result;
}

void print_invalid_input() {
    printf("n/a");
}

int input_end() {
    int end;
    char endline;
    printf("Input starting range of number:\n");
    if (!scanf("%d%c", &end, &endline) || endline != '\n') {
        end = -1;
    }
    return end;
}

int input_start() {
    int start;
    char endline;
    printf("Input ending range of number:\n");
    if (!scanf("%d%c", &start, &endline) || endline != '\n') {
        start = -1;
    }
    return start;
}

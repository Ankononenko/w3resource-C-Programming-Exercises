// Copyright 2022 finchren
/*
Write a C program to find Strong Numbers within a range of numbers
Test Data :
Input starting range of number : 1
Input ending range of number: 200
Expected Output :
The Strong numbers are :
1 2 145

Rework regular Armstrong number solution to work in a range:
 + 1. Correct the input
 2. Find numbers inside a range
 3. Test
 4. Cppling
 5. Add and push
*/

#include <stdio.h>

int input_start();
int input_end();
void print_invalid_input();
int power(int base, int exponent);
int find_number_of_digits(int number);
int is_armstrong(int number, int number_of_digits);
void print_armstrong_in_range(int start, int end);
void test(int number, int expected, int test_number);


int main() {
    // Regular run of the program
    int start = input_start();
    if (start >= 0) {
        int end = input_end();
        if (end >= 0) {
            print_armstrong_in_range(start, end);
            }
    } else {
        print_invalid_input();
    }
    return 0;
}

// 0 - false, 1 - true
void test(int number, int expected, int test_number) {
    int number_of_digits = find_number_of_digits(number);
    int actual = is_armstrong(number, number_of_digits);
    if (actual == expected) {
        printf("Test #%d: number = %d, expected = %d, actual = %d\nSuccess\n",
        test_number, number, expected, actual);
    } else {
        printf("Test #%d: number = %d, expected = %d, actual = %d\nFailed\n",
        test_number, number, expected, actual);
    }
}

void print_armstrong_in_range(int start, int end) {
    printf("The Strong numbers are:\n"); 
    for (int i = start; i <= end; i++) {
        if (is_armstrong(i, find_number_of_digits(i))) {
            printf("%d ", i);
        }
    }
}

int is_armstrong(int number, int number_of_digits) {
    int is_armstrong = 0, result = 0, temp_number = number, one_digit;
    for (int i = number_of_digits; i > 0; --i) {
        one_digit = temp_number / (1 * power(10, i - 1));
        temp_number -= one_digit * (1 * power(10, i - 1));
        result += power(one_digit, number_of_digits);
    }
    if (number == result) {
        is_armstrong = 1;
    }
    return is_armstrong;
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
    printf("Input ending range of number:\n");
    if (!scanf("%d%c", &end, &endline) || endline != '\n') {
        end = -1;
    }
    return end;
}

int input_start() {
    int start;
    char endline;
    printf("Input starting range of number:\n");
    if (!scanf("%d%c", &start, &endline) || endline != '\n') {
        start = -1;
    }
    return start;
}

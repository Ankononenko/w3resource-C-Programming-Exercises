// Copyright 2022 finchren
/*
Write a C program to check whether a number is a Strong Number or not
Test Data :
Input a number to check whether it is Strong number: 15
Expected Output :
15 is not a Strong number.

+ 1. Take input
+ 2. Invalid input
+ 3.0 Figure out what is an Armstrong number: 
153 = 1^3 + 5^3 + 3^3
+ 3.1 Write a pow function
+ 3.2 Function to find how many digits there are in the number
+ 3.3 Write function to check if Armstrong or not
+ 4. Output
+ 5. Test
+ 6. Cpplint test
+ 7. Add and push
*/

#include <stdio.h>

int input_number();
void print_invalid_input();
int power(int base, int exponent);
int find_number_of_digits(int number);
int is_armstrong(int number, int number_of_digits);
void print_is_armstrong(int number, int is_armstrong);
void test(int number, int expected, int test_number);

int main() {
    // Regular run of the program
    int number = input_number();
    if (number >= 0) {
        int number_of_digits = find_number_of_digits(number);
        print_is_armstrong(number, is_armstrong(number, number_of_digits));
    } else {
        print_invalid_input();
    }
    // Test runs
    // First test, normal values
    test(153, 1, 1);
    // Normal value, false result
    test(15, 0, 2);
    // Min value
    test(0, 1, 3);
    // One
    test(1, 1, 4);
    // Max value
    test(912985153, 1, 5);
    // Max value, false result
    test(2147483647, 0, 6);
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

void print_is_armstrong(int number, int is_armstrong) {
    if (is_armstrong) {
        printf("%d is a Strong number.\n", number);
    } else {
        printf("%d is not a Strong number.\n", number);
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

int input_number() {
    int number;
    char endline;
    printf("Input a number to check whether it is Strong number:\n");
    if (!scanf("%d%c", &number, &endline) || endline != '\n') {
        number = -1;
    }
    return number;
}

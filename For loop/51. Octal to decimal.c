// Copyright 2022 finchren
/*
Write a program in C to convert an octal number to a decimal without using an array
Test Data :
Input an octal number (using digit 0 - 7) :745
Expected Output :
The Octal Number : 745
The equivalent Decimal Number : 485

+ 1. Figure out howo to convert octal to decimal
    745 = (7 * 8^2) + (4 * 8^1) + (5 * 8^0) = 485
+ 1.5 Input
+ 2. Pow function
+ 3. Function to count amount of digits
+ 4. Write function to iterate over digits and return sum of powers
+ 5. Invalid input
+ 5.5 Fix "using digit 0 - 7"
+ 6. Test
+ 7. Cpplint test
+ 8. Add and push 
*/

#include <stdio.h>

enum boolean_for_input {
    TRUE = 1,
    FALSE = 0
};

enum switch_for_negative_octal {
    IS_NEGATIVE = -1,
    IS_POSITIVE = 1
};

int input_octal(int *octal);
void print_invalid_input();
int power(int base, int exponent);
int find_number_of_digits(int octal);
int find_decimal(int octal, int number_of_digits, int sign);
void output_decimal(int octal, int decimal);
void test(int octal, int expected_result, int test_number);
void run_tests();

int main() {
    int octal = 0;
    if (input_octal(&octal)) {
       int sign = IS_POSITIVE;
       if (octal < 0) {
           octal *= IS_NEGATIVE;
           sign = IS_NEGATIVE;
       }
       output_decimal(octal, find_decimal(octal, find_number_of_digits(octal), sign));
       } else {
       print_invalid_input();
       }
    run_tests();
    return 0;
}

void run_tests() {
    // Normal values tests
    test(745, 485, 1);
    test(745456, 248622, 2);
    test(15, 13, 3);
    // Big number tests
    test(523053070, 88888888, 4);
    // Near end of int range test
    test(2122206200, 290000000, 5);
    // Zero test
    test(0, 0, 6);
    // Negative number test
    test(-34567, -14711, 7);
    test(-345, -229, 8);
}

void test(int octal, int expected_result, int test_number) {
    int sign = IS_POSITIVE;
    if (octal < 0) {
        octal *= IS_NEGATIVE;
        sign = IS_NEGATIVE;
    }
    int actual_result = find_decimal(octal, find_number_of_digits(octal), sign);
    if (actual_result == expected_result) {
        printf("Test #%d: Success\n", test_number);
    } else {
        printf("Test #%d: Failed. Octal = %d, expected_result = %d, actual_result = %d\n",
        test_number, octal, expected_result, actual_result);
    }
}

void output_decimal(int octal, int decimal) {
    printf("The Octal Number: %d", octal);
    printf("The equivalent Decimal Number: %d\n", decimal);
}

int find_decimal(int octal, int number_of_digits, int sign) {
    int decimal = 0, temp_octal = octal, power_of_ten;
    for (int i = number_of_digits; i > 0; --i) {
        power_of_ten = power(10, number_of_digits - 1);
        decimal += temp_octal / power_of_ten * power(8, number_of_digits - 1);
        temp_octal -= temp_octal / power_of_ten * power_of_ten;
        --number_of_digits;
    }
    return decimal * sign;
}

int find_number_of_digits(int octal) {
    int counter = 0;
    for (int i = octal; i > 0; i /= 10) {
        ++counter;
    }
    return counter;
}

int power(int base, int exponent) {
    int result = base;
    if (exponent == 0) {
        result = 1;
    } else {
        for (int i = 2; i <= exponent; ++i) {
            result *= base;
        }
    }
    return result;
}

void print_invalid_input() {
    printf("n/a\n");
}

int is_valid_octal(int octal, int number_of_digits) {
    int digit = 0, temp_octal = octal, power_of_ten, is_valid = TRUE;
    for (int i = number_of_digits; i > 0; --i) {
        power_of_ten = power(10, number_of_digits - 1);
        digit = temp_octal / power_of_ten * power(8, number_of_digits - 1);
        temp_octal -= temp_octal / power_of_ten * power_of_ten;
        --number_of_digits;
        if (digit >= 8 && digit <= 9) {
            is_valid = FALSE;
            break;
        }
    }
    return is_valid;
}

int input_octal(int *octal) {
    printf("Input an octal number (using digit 0 - 7):\n");
    int is_valid = TRUE;
    char endline = '\0';
    if (!scanf("%d%c", octal, &endline) || endline != '\n' ||
    is_valid_octal(*octal, find_number_of_digits(*octal) == FALSE)) {
        is_valid = FALSE;
    }
    return is_valid;
}

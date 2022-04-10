// Copyright 2022 finchren
/*
Write a program in C to convert a decimal number into octal without using an array
Test Data :
Enter a number to convert : 79
Expected Output :
The Octal of 79 is 117.

+ 1. Take input
+ 2. Figure out how to convert to octal:
    Devide the decimal by 8 and take the quotient to devide until it's zero
    Put that remainder at the end of the octal number;
    79 % 8 == 7; quotient = 9
    9 % 8 == 1; q = 1
    1 % 8 == 1; q = 1
    117
    Conversion steps:
        1 Divide the number by 8.
        2 Get the integer quotient for the next iteration.
        3 Get the remainder for the octal digit.
        4 Repeat the steps until the quotient is equal to 0.
+ 3. Invalid input
+ 4. Convert:
+    Function to count how many iterations of /8 there will be
+    Power function
+    Function to get the number int
+    Reverse it
+ 5. Output
6. Test
+ 7. Cpplint test
+ 8. Add and push
*/

#include <stdio.h>

enum input_state {
    FAILURE = 0,
    SUCCESS = 1
};

enum is_negative {
    TRUE = 1,
    FALSE = 0
};

int input_decimal_number(int * decimal_number);
int number_of_eights(int decimal_number);
int power(int base, int exponent);
int convert(int decimal_number);
int reverse_number(int converted_number, int division_by_eight);
void print_octal(int decimal_number, int result);
void print_invalid_input();
void test(int number, int expected, int test_number);
void run_tests();

int main() {
    // int decimal_number = 0;
    // int input_state = input_decimal_number(&decimal_number);
    // if (input_state == SUCCESS) {
    //     int converted = convert(decimal_number);
    //     print_octal(decimal_number, converted);
    // } else {
    //     print_invalid_input();
    // }
    run_tests();
    return 0;
}

void run_tests() {
    /*
    // Normal value tests
    test(79, 117, 1);
    test(1, 1, 2);
    test(15, 17, 3);
    test(555, 1053, 4);
    test(8888, 21270, 5);
    // Negative number test
    test(-79, -117, 6);
    test(-1, -1, 7);
    test(-15, -17, 8);
    test(-555, -1053, 9);
    test(-8888, -21270, 10);
    // Zero test
    test(0, 0, 11);
    // Big number test
    test(47483647, 265105377, 12);
    */
    // Near end of int range
    test(294903430, 2144757206, 13);
}

void test(int number, int expected, int test_number) {
    int actual = convert(number);
    if (actual == expected) {
        printf("Test #%d passed\n", test_number);
    } else {
        printf("Test #%d failed. Number = %d, expected = %d, actual = %d\n",
        test_number, number, expected, actual);
    }
}

void print_invalid_input() {
    printf("n/a");
}

void print_octal(int decimal_number, int result) {
    printf("The Octal of %d is %d.\n", decimal_number, result);
}

// 711 -> 117

int reverse_number(int converted_number, int division_by_eight) {
    int result = 0, temp_converted = converted_number, digit, power_counter = division_by_eight - 1;
    for (int i = 0; i <= division_by_eight; ++i) {
        digit = temp_converted % 10;
        temp_converted /= 10;
        result += digit * power(10, power_counter);
        --power_counter;
    }
    return result;
}

/*
Conversion steps:
        1 Divide the number by 8.
        2 Get the integer quotient for the next iteration.
        3 Get the remainder for the octal digit.
        4 Repeat the steps until the quotient is equal to 0.
   79 % 8 == 7; quotient = 9
    9 % 8 == 1; q = 1
    1 % 8 == 1; q = 1
I will probably need a function to count how many iterations I will need to convert result into a number.
I'll need that function once again when I will flip the number
*/

int convert(int decimal_number) {
    int is_negative = FALSE;
    if (decimal_number < 0) {
        decimal_number *= -1;
        is_negative = TRUE;
    }
    int division_by_eight = number_of_eights(decimal_number);
    int result = 0, quotient, remainder, temp_decimal = decimal_number,
    divider = 8, power_counter = division_by_eight;
    for (int i = 0; i <= division_by_eight; ++i) {
        quotient = temp_decimal / divider;
        remainder = temp_decimal % divider;
        if (power_counter >= 2) {
            result += remainder * power(10, power_counter - 1);
        } else {
            result += remainder;
        }
        --power_counter;
        temp_decimal = quotient;
    }
    result = reverse_number(result, division_by_eight);
    if (is_negative == TRUE) {
        result *= -1;
    }
    return result;
}

int power(int base, int exponent) {
    int result;
    if (exponent == 0) {
        result = 1;
    } else {
        result = base;
        for (int i = 2; i <= exponent; ++i) {
            result *= base;
        }
    }
    return result;
}

int number_of_eights(int decimal_number) {
    int divisor = 8, quotient, counter = 0, temp_decimal = decimal_number;
    for (int i = 0; i <= decimal_number; ++i) {
        quotient = temp_decimal / divisor;
        temp_decimal = quotient;
        ++counter;
        if (quotient == 0) {
            break;
        }
    }
    return counter;
}

int input_decimal_number(int * decimal_number) {
    int input_state = FAILURE;
    char endline = '\0';
    if (!scanf("%d%c", decimal_number, &endline) || endline != '\n') {
        input_state = FAILURE;
    } else {
        input_state = SUCCESS;
    }
    return input_state;
}

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
6. Test
7. Cpplint test
8. Add and push 
*/

#include <stdio.h>

enum boolean_for_validation {
    TRUE = 1,
    FALSE = 0
};

int input_octal(int *octal);
void print_invalid_input();
int power(int base, int exponent);
int find_number_of_digits(int octal);
int find_decimal(int octal, int number_of_digits);

int main() {
   int octal = 0;
   if (input_octal(&octal)) {
        int number_of_digits = find_number_of_digits(octal);
        printf("%d", find_decimal(octal, number_of_digits));
   } else {
       print_invalid_input();
   }
   return 0;
}

int find_decimal(int octal, int number_of_digits) {
    int decimal = 0, temp_octal = octal, power_of_ten;
    for (int i = number_of_digits; i > 0; --i) {
        power_of_ten = power(10, number_of_digits - 1);
        decimal += temp_octal / power_of_ten * power(8, number_of_digits - 1);
        temp_octal -= temp_octal / power_of_ten * power_of_ten;
        --number_of_digits;
    }
    return decimal;
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
    printf("n/a");
}

int input_octal(int *octal) {
    int is_valid = TRUE;
    char endline = '\0';
    if (!scanf("%d%c", octal, &endline) || endline != '\n') {
        is_valid = FALSE;
    }
    return is_valid;
}

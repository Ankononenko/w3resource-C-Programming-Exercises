// Copyright 2022 finchren
/*
Write a program in C to convert a decimal number into octal without using an array
Test Data :
Enter a number to convert : 79
Expected Output :
The Octal of 79 is 117.

+ 1. Take input
2. Figure out how to convert to octal
3. Invalid input
4. Convert
5. Output
6. Test
7. Cpplint test
8. Add and push
*/

#include <stdio.h>

int input_decimal_number();

int main() {
    int decimal_number = input_decimal_number();
    return 0;
}

int input_decimal_number() {
    int decimal_number;
    scanf("%d", &decimal_number);
    return decimal_number;
}

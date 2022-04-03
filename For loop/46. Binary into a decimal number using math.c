// Copyright 2022 finchren
/*
Write a program in C to convert a binary number into a decimal number using math function
Test Data :
Input the binary number :1010100
Expected Output :
The Binary Number : 1010100
The equivalent Decimal Number is : 84

+ 1. Take input. Max range of int is 2,147,483,647, so I'm going to take the maximum binary number of
31 characters long. 1111111111111111111111111111111 ==  2,147,483,647
+ 1.1 Remember how to pass an array from a function to a funtion and return an array from a function -
    Here we should use a pointer to that array and initialize it in the main funciton
+ 1.5 Invalid input
+ 2. Figure out how to use math library to find the decimal number:
    if char == 1 then 2^lenght-1 where i goes from lenght to zero
    if zero -> go next
+ 3. Convert to decimal
+ 4. Output
+ 5. Test
+ 6. Cpplint test
+ 7. Add and push
*/

#include <stdio.h>
#include <math.h>
#define NMAX 31

// To return an array from a function we should use a pointer
int input_binary_array(char* binary_array);
void print_invalid_input();
int convert_binary_to_decimal(char* binary_array, int lenght);
void print_decimal_result(char* binary_array, int lenght, int decimal);
void test(char* test_binary_array, int lenght, int expected_result, int test_number);
void print_test_binary_number(char* binary_array, int lenght, int test_number);

int main() {
    // Regular run
    char binary_array[NMAX];
    int lenght = input_binary_array(binary_array);
    if (lenght >= 1) {
        int decimal = convert_binary_to_decimal(binary_array, lenght);
        print_decimal_result(binary_array, lenght,  decimal);
    } else {
        print_invalid_input();
    }
    // Test runs
    // Regular value test
    char test1_binary_array[7] = {'1', '0', '1', '0', '1', '0', '0'};
    test(test1_binary_array, 7, 84, 1);
    // All ones test
    char test2_binary_array[7] = {'1', '1', '1', '1', '1', '1', '1'};
    test(test2_binary_array, 7, 127, 2);
    // All zeros test
    char test3_binary_array[7] = {'0', '0', '0', '0', '0', '0', '0'};
    test(test3_binary_array, 7, 0, 3);
    // Min test
    char test4_binary_array[1] = {'0'};
    test(test4_binary_array, 1, 0, 4);
    // Max int range test
    char test5_binary_array[31] = {'1', '1', '1', '1', '1', '1', '1', '1', '1',
    '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
    '1', '1', '1', '1', '1', '1', '1'};
    test(test5_binary_array, 31, 2147483647, 5);
    // 1 - 0 - 1 - 0 - 1 test
    char test6_binary_array[7] = {'1', '0', '1', '0', '1', '0', '1'};
    test(test6_binary_array, 7, 85, 6);
    // 1 - 1 - 1 - 0 - 0 - 0 test
    char test7_binary_array[12] = {'1', '1', '1', '0', '0', '0', '1', '1', '1', '0', '0', '0'};
    test(test7_binary_array, 12, 3640, 7);
    return 0;
}

void test(char* test_binary_array, int lenght, int expected_result, int test_number) {
    int actual_result = convert_binary_to_decimal(test_binary_array, lenght);
    print_test_binary_number(test_binary_array, lenght, test_number);
    if (actual_result == expected_result) {
        printf("\nTest #%d: expected = %d, actual = %d \nSuccess",
        test_number, expected_result, actual_result);
    } else {
        printf("\nTest #%d: expected = %d, actual = %d \nFailed",
        test_number, expected_result, actual_result);
    }
    printf("\n");
}

void print_test_binary_number(char* binary_array, int lenght, int test_number) {
    printf("\nThe test #%d Binary Number: ", test_number);
    for (int i = 0; i < lenght; ++i) {
        printf("%c", binary_array[i]);
    }
}

void print_decimal_result(char* binary_array, int lenght, int decimal) {
    printf("\nThe Binary Number: ");
    for (int i = 0; i <= lenght; ++i) {
        printf("%c", binary_array[i]);
    }
    printf("\nThe equivalent Decimal Number is: %d\n", decimal);
}

int convert_binary_to_decimal(char* binary_array, int lenght) {
    int result = 0, exponent = lenght - 1;
    for (int i = 0; i <= lenght - 1; ++i) {
        if (binary_array[i] == '1') {
            result += (int)pow(2, exponent);
        }
        --exponent;
    }
    return result;
}

void print_invalid_input() {
    printf("n/a");
}

int input_binary_array(char* binary_array) {
    int lenght = NMAX;
    for (int i = 0; i <= lenght; ++i) {
        scanf("%1c", &binary_array[i]);
        if (binary_array[i] == '\n') {
            // Used to stop the loop when it reaches newline
            lenght = i;
            break;
        }
        if (binary_array[i] != '0' && binary_array[i] != '1') {
            // Used to sort out invalid input
            lenght = -1;
        }
    }
    return lenght;
}

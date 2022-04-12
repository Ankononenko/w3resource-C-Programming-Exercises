// Copyright 2022 ficnhren
/*
Write a c program to find out the sum of an A.P. series
Test Data :
Input the starting number of the A.P. series: 1
Input the number of items for the A.P. series: 10
Input the common difference of A.P. series: 4
Expected Output :
The Sum of the A.P. series are :
1 + 5 + 9 + 13 + 17 + 21 + 25 + 29 + 33 + 37 = 190

+ 1. Take input
+ 1.5 Invalid input
+ 2. Write a function to find elements
+ 3. Output sum
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include <stdio.h>

enum is_valid {
    TRUE = 1,
    FALSE = 0
};

int input_start(int *start);
int input_number_of_items(int *number_of_items);
int input_difference(int *difference);
// Changed this function to return int sum for tests
int print_result_find_sum(int start, int number_of_items, int difference);
void print_invalid_input();
void test(int start, int number_of_items, int difference, int expected_sum, int test_number);
void run_tests();

int main() {
    int start = 0, number_of_items = 0, difference = 0;
    // Normal run of the programm
    if (input_start(&start)) {
        if (input_number_of_items(&number_of_items)) {
            if (input_difference(&difference)) {
                print_result_find_sum(start, number_of_items, difference);
            } else {
                print_invalid_input();
            }
        } else {
            print_invalid_input();
        }
    } else {
        print_invalid_input();
    }
    // Test runs
    printf("\nStart of test runs:\n");
    run_tests();
    return 0;
}

void run_tests() {
// values: int start, int number_of_items, int difference, int expected_sum, int test_number
// Normal value tests
    test(1, 10, 4, 190, 1);
    test(0, 9, 5, 180, 2);
    test(500, 5, 180, 4300, 3);
// Negative number tests
    // Negative start
    test(-100, 5, 3, -470, 4);
    // Negative step
    test(100, 5, -3, 470, 5);
    // Negative start and step
    test(-100, 5, -3, -530, 6);
// Big numbers
    test(67548, 50, 4543, 8942575, 7);
    // Almost the end of int range
    test(63437548, 33, 54543, 2122237788, 8);
}

void test(int start, int number_of_items, int difference, int expected_sum, int test_number) {
    int actual_sum = 0;
    actual_sum = print_result_find_sum(start, number_of_items, difference);
    if (expected_sum == actual_sum) {
        printf("Success\n");
    } else {
        printf("Failed\nTest #%d: start = %d, number_of_items = %d, difference = %d, expected_sum = %d, actual_sum = %d\n",
        test_number, start, number_of_items, difference, expected_sum, actual_sum);
    }
}

void print_invalid_input() {
    printf("n/a");
}

int print_result_find_sum(int start, int number_of_items, int difference) {
    printf("The Sum of the A.P. series are:\n");
    int sum = start, element = start;
    printf("%d ", element);
    for (int i = 0; i < number_of_items - 1; ++i) {
        element += difference;
        printf("+ %d ", element);
        sum += element;
    }
    printf("= %d\n", sum);
    return sum;
}

int input_start(int *start) {
    int is_valid = TRUE;
    char endline = '\0';
    printf("Input the starting number of the A.P. series:\n");
    if (!scanf("%d%c", start, &endline) || endline != '\n') {
        is_valid = FALSE;
    }
    return is_valid;
}

int input_number_of_items(int *number_of_items) {
    int is_valid = TRUE;
    char endline = '\0';
    printf("Input the number of items for the A.P. series:\n");
    if (!scanf("%d%c", number_of_items, &endline) || endline != '\n' || *number_of_items <= 0) {
        is_valid = FALSE;
    }
    return is_valid;
}

int input_difference(int *difference) {
    int is_valid = TRUE;
    char endline = '\0';
    printf("Input the common difference of A.P. series:\n");
    if (!scanf("%d%c", difference, &endline) || endline != '\n') {
        is_valid = FALSE;
    }
    return is_valid;
}

// Copyright 2022 finchren
/*
Write a program in c to find the Sum of GP series
Test Data :
Input the first number of the G.P. series: 3
Input the number or terms in the G.P. series: 5
Input the common ratio of G.P. series: 2
Expected Output :
The numbers for the G.P. series:
3.000000 6.000000 12.000000 24.000000 48.000000
The Sum of the G.P. series : 93.000000

+ 1. Write tests (run tests function + body of a test)
2. Input
3. Invalid input
4. Finction to print out and find the sum
5. Check the tests
6. Cppcheck
7. Add and push
*/

#include <stdio.h>

void test(int first_number, int number_of_terms, int common_ratio, int expected_result, int test_number);
void run_tests();
int find_gp_series(int first, int number_of_terms, int common_ratio);

int main() {
    run_test();
    return 0;
}

int find_gp_series(int first, int number_of_terms, int common_ratio) {
    int sum = 0;
    return sum;
}

void test(int first_number, int number_of_terms, int common_ratio, int expected_result, int test_number) {
    int actual_result = find_gp_series(first_number, number_of_terms, common_ratio);
    if (actual_result == expected_result) {
        printf("Test #%d: Success\n", test_number);
    } else {
        printf("Test #%d: Failed\nFirst_number = %d, number_of_terms = %d, common_ratio = %d, expected_result = %d, actual_result = %d\n",
        test_number, first_number, number_of_terms, common_ratio, expected_result, actual_result);
    }
}

void run_tests() {
    // Normal value tests
    test(3, 5, 2, 93, 1);
}
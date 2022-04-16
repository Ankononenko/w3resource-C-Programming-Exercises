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
+ 2. Input
3. Invalid input
4. Finction to print out and find the sum
5. Check the tests
6. Cppcheck
7. Add and push
*/

#include <stdio.h>

enum is_valid_boolean{
    TRUE = 1,
    FALSE = 0
};

void test(int first_number, int number_of_terms, int common_ratio, int expected_result, int test_number);
void run_tests();
int find_gp_series(int first, int number_of_terms, int common_ratio);
int input_first_number(int *first_number);
int input_number_of_terms(int *number_of_terms);
int input_common_ratio(int *common_ratio);
void print_invalid_input();

int main() {
    int first_number = 0;
    if (input_first_number(&first_number)) {
        int number_of_terms = 0;
        if (input_number_of_terms(&number_of_terms)) {
            int common_ratio = 0;
            if (input_common_ratio(&common_ratio)) {
                run_tests();
            } else {
               print_invalid_input();
            }
        } else {
        print_invalid_input();
    }     
    } else {
        print_invalid_input();
    }
    return 0;
}

int input_common_ratio(int *common_ratio) {
    int is_valid = TRUE;
    char endline = '\0';
    if (!scanf("%d%c", common_ratio, &endline) || endline != '\n') {
        is_valid = FALSE;
    }
    return is_valid;    
}

int input_number_of_terms(int *number_of_terms) {
    int is_valid = TRUE;
    char endline = '\0';
    if (!scanf("%d%c", number_of_terms, &endline) || endline != '\n') {
        is_valid = FALSE;
    }
    return is_valid;    
}

int input_first_number(int *first_number) {    
    int is_valid = TRUE;
    char endline = '\0';
    if (!scanf("%d%c", first_number, &endline) || endline != '\n') {
        is_valid = FALSE;
    }
    return is_valid;
}

void print_invalid_input() {
    printf("n/a");
}

int find_gp_series(int first, int number_of_terms, int common_ratio) {
    int sum = 0;
    printf("%d%d%d",first, number_of_terms, common_ratio);
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
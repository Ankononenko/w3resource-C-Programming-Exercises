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
+ 3. Invalid input
+ 4. Finction to print out and find the sum
+ 5. Check the tests
+ 6. Cppcheck
+ 7. Add and push
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
void print_sum_gp_series(int sum);

int main() {
    // Regular run
    int first_number = 0;
    if (input_first_number(&first_number)) {
        int number_of_terms = 0;
        if (input_number_of_terms(&number_of_terms)) {
            int common_ratio = 0;
            if (input_common_ratio(&common_ratio)) {
                int sum = find_gp_series(first_number, number_of_terms, common_ratio);
                print_sum_gp_series(sum);
            } else {
               print_invalid_input();
            }
        } else {
        print_invalid_input();
    }
    } else {
        print_invalid_input();
    }
    // Tests to run
    printf("\n>>>Tests:\n");
    run_tests();
    return 0;
}

void print_sum_gp_series(int sum) {
    printf("The Sum of the G.P. series: %d\n", sum);
}

int input_common_ratio(int *common_ratio) {
    printf("Input the common ratio of G.P. series:\n");
    int is_valid = TRUE;
    char endline = '\0';
    // Common ratio can't be zero as it will result in all elements being the same = 1, which is not gp
    if (!scanf("%d%c", common_ratio, &endline) || endline != '\n' || *common_ratio == 0) {
        is_valid = FALSE;
    }
    return is_valid;
}

int input_number_of_terms(int *number_of_terms) {
    printf("Input the number or terms in the G.P. series:\n");
    int is_valid = TRUE;
    char endline = '\0';
    // Number of terms can't be negative or zero
    if (!scanf("%d%c", number_of_terms, &endline) || endline != '\n' || *number_of_terms <= 0) {
        is_valid = FALSE;
    }
    return is_valid;
}

int input_first_number(int *first_number) {
    printf("Input the first number of the G.P. series:\n");
    int is_valid = TRUE;
    char endline = '\0';
    // First element can't be zero as it will result in progression having only one element - zero
    if (!scanf("%d%c", first_number, &endline) || endline != '\n' || first_number == 0) {
        is_valid = FALSE;
    }
    return is_valid;
}

void print_invalid_input() {
    printf("n/a");
}

int find_gp_series(int first, int number_of_terms, int common_ratio) {
    printf("The numbers for the G.P. series:\n");
    int number_to_print = first, sum = 0;
    for (int i = 0; i < number_of_terms; ++i) {
        printf("%d ", number_to_print);
        sum += number_to_print;
        number_to_print *= common_ratio;
    }
    printf("\nThe Sum of the G.P. series: %d\n", sum);
    return sum;
}

void test(int first_number, int number_of_terms, int common_ratio, int expected_result, int test_number) {
    int actual_result = find_gp_series(first_number, number_of_terms, common_ratio);
    if (actual_result == expected_result) {
        printf("Test #%d: Success\n", test_number);
    } else {
        printf("Test #%d: Failed\n", test_number);
        printf("First = %d, n_of_terms = %d, common_ratio = %d, expected = %d, actual = %d\n",
        first_number, number_of_terms, common_ratio, expected_result, actual_result);
    }
    printf("\n");
}

void run_tests() {
    // Normal value tests
    test(3, 5, 2, 93, 1);
    test(1, 10, 3, 29524, 2);
    // Negative start test
    test(-3, 5, 2, -93, 3);
    test(-1, 10, 3, -29524, 4);
    // Negative common ration tests
    test(10, 4, -2, -50, 5);
    test(51, 5, -5, 26571, 6);
    // Near-end of int range test
    test(1011, 21, 2, 2120219661, 7);
}

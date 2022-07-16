// Copyright 2022 finchren
/*
Write a C program to check whether a given integer is positive even, negative even, positive odd or negative odd. Print even if the number is 0
Test Data :
Input an integer: 13
Expected Output:
Positive Odd

√ 1. Write a plan to complete the exercise
√ 2. Take input
√ 3. Invalid input
√ 4. Write the fucntion to check the condition
√ 5. Output the result
√ 6. Test
√ 7. Cpplint test
√ 8. Add and push
*/

#include <stdio.h>

enum is_true{
    FALSE,
    TRUE
};

typedef struct Number_types {
    int positive_even;
    int negative_even;
    int positive_odd;
    int negative_odd;
} Number_types;


static void initialize_number_types(Number_types *number_types);
int input_number(int *number);
void print_invalid_input();
void check_number(int number, Number_types *number_types);
void output_result(Number_types number_types);

int main() {
    int number = 0;
    if (input_number(&number)) {
        Number_types number_types;
        initialize_number_types(&number_types);
        check_number(number, &number_types);
        output_result(number_types);
    } else {
        print_invalid_input();
    }
    return 0;
}

void output_result(Number_types number_types) {
    if (number_types.positive_even)
        printf("Positive even");
    if (number_types.positive_odd)
        printf("Positive odd");
    if (number_types.negative_even)
        printf("Negative even");
    if (number_types.negative_odd)
        printf("Negative odd");
}

static void initialize_number_types(Number_types *number_types) {
    number_types->positive_even = FALSE;
    number_types->positive_odd = FALSE;
    number_types->negative_even = FALSE;
    number_types->negative_odd = FALSE;
}

void check_number(int number, Number_types *number_types) {
        if (number >= 0) {
            if (number % 2 == 0) {
                number_types->positive_even = TRUE;
            } else {
                number_types->positive_odd = TRUE;
            }
        } else {
            if (number % 2 == 0) {
                number_types->negative_even = TRUE;
            } else {
                number_types->negative_odd = TRUE;
            }
        }
    }

void print_invalid_input() {
    printf("Script takes only one number."
    "At the end of the line only a newline is accepted");
}

int input_number(int *number) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input an integer: ");
    if (scanf("%d%c", number, &newline) && newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

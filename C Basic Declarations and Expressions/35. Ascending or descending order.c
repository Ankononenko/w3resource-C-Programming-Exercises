// Copyright 2022 finchren
/*
Write a C program to check whether two numbers in a pair is in ascending order or descending order
Test Data :
Input a pair of numbers (for example 10,2 : 2,10):
Input first number of the pair: 10
Expected Output:
Input second number of the pair: 2
The pair is in descending order!

√ 0. Write a plan to complete the exercise
√ 1. Take input of pair of numbers and store them in an array
√    that is placed in a structure for practice
√ 2. Work around invalid input
√ 3. Check if descending or ascending
√ 4. Output the result
√ 5. Test
√ 6. Cpplint test
√ 7. Add and push
*/

#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 2
#define STRING_SIZE 7
#define ERROR_STRING_SIZE 83

enum boolean{
    FALSE,
    TRUE
};

typedef struct Box {
    char ordinal_strings[ARRAY_SIZE][STRING_SIZE];
    int array_of_numbers[ARRAY_SIZE];
    char invalid_input_string[ERROR_STRING_SIZE];
} Box;

void initialize_structure(Box* box);
int input_number(Box* box, int index);
void print_greeting(Box* box, int ordinal);
void print_invalid_input(Box* box);
int is_ascending(Box* box);
void print_result(int result_of_ascending);
int check_if_equal(Box* box);
void print_numbers_are_equal();

int main() {
    Box box;
    initialize_structure(&box);
    int index = 0;
    print_greeting(&box, index);
    if (input_number(&box, index)) {
        ++index;
        print_greeting(&box, index);
        if (input_number(&box, index)) {
            if (!check_if_equal(&box)) {
                int result_of_ascending = FALSE;
                result_of_ascending = is_ascending(&box);
                print_result(result_of_ascending);
            } else {
                print_numbers_are_equal();
            }
        } else {
            print_invalid_input(&box);
        }
    } else {
        print_invalid_input(&box);
    }
    return 0;
}

void print_numbers_are_equal() {
    printf("Numbers are equal \n");
}

int check_if_equal(Box* box) {
    int is_equal = FALSE;
    is_equal =
        box->array_of_numbers[0] == box->array_of_numbers[1] ? TRUE : FALSE;
    return is_equal;
}

void print_result(int result_of_ascending) {
    if (result_of_ascending) {
        printf("The pair is in ascending order!");
    } else {
        printf("The pair is in descending order!");
    }
}

int is_ascending(Box* box) {
    int is_ascending = FALSE;
    is_ascending =
        box->array_of_numbers[0] < box->array_of_numbers[1] ? TRUE : FALSE;
    return is_ascending;
}

void print_invalid_input(Box* box) {
    printf("%s", box->invalid_input_string);
}

void print_greeting(Box* box, int ordinal) {
    printf("Input %s number of the pair: ", box->ordinal_strings[ordinal]);
}

int input_number(Box* box, int index) {
    int is_valid_input = FALSE;
    char newline = '\n';
    if (scanf("%d%c", &box->array_of_numbers[index], &newline) &&
        newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

void initialize_structure(Box* box) {
    char* first_string = "first";
    char* second_string = "second";
    snprintf(box->ordinal_strings[0],
        sizeof(box->ordinal_strings[0]), "%s", first_string);
    snprintf(box->ordinal_strings[1],
        sizeof(box->ordinal_strings[1]), "%s", second_string);
    memset(box->array_of_numbers, 0, ARRAY_SIZE * sizeof(int));
    char* invalid_input = "The script accepts only one number at a time \n"
    "At the end only newline is accepted \n";
    snprintf(box->invalid_input_string,
        sizeof(box->invalid_input_string), "%s", invalid_input);
}

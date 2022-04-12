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
4. Test
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
void find_and_print_result(int start, int number_of_items, int difference);
void print_invalid_input();

int main() {
    int start = 0, number_of_items = 0, difference = 0;
    if (input_start(&start)) {
        if (input_number_of_items(&number_of_items)) {
            if (input_difference(&difference)) {
                find_and_print_result(start, number_of_items, difference);
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

void print_invalid_input() {
    printf("n/a");
}

void find_and_print_result(int start, int number_of_items, int difference) {
    printf("The Sum of the A.P. series are:\n");
    int sum = start, element = start;
    printf("%d ", element);
    for (int i = 0; i < number_of_items - 1; ++i) {
        element += difference;
        printf("+ %d ", element);
        sum += element;
    }
    printf("= %d", sum);
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
    if (!scanf("%d%c", number_of_items, &endline) || endline != '\n' || *number_of_items == 0) {
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

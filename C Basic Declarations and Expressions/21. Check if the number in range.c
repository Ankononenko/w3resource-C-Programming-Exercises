// Copyright 2022 finchren
/*
Write a C program that reads an integer and check the specified range where it belongs. Print an error message if the number is negative and greater than 80
Test Data :
Input an integer: 15
Expected Output:
Range [0, 20]

+ 1. Write a plan to complete the exercise
+ 2. Take input
+ 3. Check if input is valid
+ 4. Write a function to check in which range the number is
+ 5. Error message
+ 6. Test
+ 7. Cpplint test
+ 8. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_number(int *number);
void print_invalid_input();
void find_range(int number, int *start, int *end);
void print_result(int start, int end);

int main() {
    int number = -1;
    if (input_number(&number)) {
        int start = -1, end = -1;
        find_range(number, &start, &end);
        print_result(start, end);
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_result(int start, int end) {
    if (start == -1 || end == -1) {
        printf("Error. The number can only be >= 0 and <= 80");
    } else {
        printf("Range [%d, %d]", start, end);
    }
}

void find_range(int number, int *start, int *end) {
    if (number >= 0 && number <= 20) {
        *start = 0;
        *end = 20;
    } else if (number >= 21 && number <= 40) {
        *start = 21;
        *end = 40;
    } else if (number >= 41 && number <= 60) {
        *start = 41;
        *end = 60;
    } else if (number >= 61 && number <= 80) {
        *start = 61;
        *end = 80;
    }
}

void print_invalid_input() {
    printf("Input can be only one number in the range of int"
    "at the end of the line only a newline is accepted");
}

int input_number(int *number) {
    int is_valid_input = TRUE;
    char newline = '\0';
    if (!scanf("%d%c", number, &newline) || newline != '\n') {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

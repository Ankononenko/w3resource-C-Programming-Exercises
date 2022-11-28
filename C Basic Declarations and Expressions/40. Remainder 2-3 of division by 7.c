// Copyright School 21 finchren 2022

/*
Task:
Write a C program to find all numbers which are dividing by 7 and the remainder is equal to 2 or 3 between two given integer numbers
Test Data :
Input the first integer: 25
Input the second integer: 45
Expected Output:
30
31
37
38
44

✔ 1. Write a plan to complete the exercise
✔ 2. Take input
✔ 3. Invalid input
✔ 4. Function to find and output the result
✔ 5. Test
✔ 6. Cppling test
✔ 7. Add and push
*/

#include <stdio.h>

enum is_valid {
    FALSE,
    TRUE
};

int take_input(char* string, int *num);
void invalid_input();
int first_lt_second(int first_num, int second_num);
void first_should_be_lt_second();
void find_result(int first_num, int second_num);

int main() {
    int first_num = 0;
    char first_string[] = "Input the first integer:\n";
    if (take_input(first_string, &first_num)) {
        int second_num = 0;
        char second_string[] = "Input the second integer:\n";
        if (take_input(second_string, &second_num)) {
            if (first_lt_second(first_num, second_num)) {
                find_result(first_num, second_num);
            } else {
                first_should_be_lt_second();
            }
        } else {
            invalid_input();
        }
    } else {
        invalid_input();
    }
}

void find_result(int first_num, int second_num) {
    int divisor = 7, first_remainder = 2, second_remainder = 3,
    num_found = FALSE;
    for (int index = first_num; index < second_num; ++index) {
        if ((index % divisor == first_remainder) ||
            (index % divisor == second_remainder)) {
            printf("%d\n", index);
            if (!num_found) {
                num_found = TRUE;
            }
        }
    }
    if (!num_found) {
        printf("No numbers were found.\n");
    }
}

void first_should_be_lt_second() {
    printf("First number should be less than the second one\n");
}

int first_lt_second(int first_num, int second_num) {
    int is_valid_input = FALSE;
    is_valid_input = first_num < second_num ? TRUE : FALSE;
    return is_valid_input;
}

void invalid_input() {
    printf("Invalid input. Script takes only one number at a time.\n");
}

int take_input(char* string, int *num) {
    int is_valid_input = TRUE;
    char newline = '\n';
    printf("%s", string);
    if (!scanf("%d%c", num, &newline) || newline != '\n') {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

// Copyright 2022 finchren
/*
Write a C program that reads an integer between 1 and 12 and print the month of the year in English
Test Data :
Input a number between 1 to 12 to get the month name: 8
Expected Output:
August

√ 1. Write a plan to complete the exercise
√ 2. Take the input
√ 3. Invalid input
√ 4. Output the month using an array of months
√ 5. Test
√ 6. Cpplint test
√ 7. Add and push
*/

#include <stdio.h>

enum is_valid {
    FALSE,
    TRUE
};

int enter_the_month(int *number_of_the_month);
void print_greeting();
void print_invalid_input();
void print_the_month(int number_of_the_month);

int main() {
    int number_of_the_month = 0;
    if (enter_the_month(&number_of_the_month)) {
        print_the_month(number_of_the_month);
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_the_month(int number_of_the_month) {
    char months[12][10] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    printf("%s", months[number_of_the_month - 1]);
}

void print_invalid_input() {
    printf("The number of the month should be in range of 12. \n"
        "At the end of the line only a newline is accepted");
}

void print_greeting() {
    printf("Input a number between 1 to 12 to get the month name: ");
}

int enter_the_month(int *number_of_the_month) {
    int is_valid_input = FALSE;
    char newline = '\n';
    print_greeting();
    if (scanf("%d%c", number_of_the_month, &newline) &&
        newline == '\n' &&
        (*number_of_the_month < 13 && *number_of_the_month > 0)) {
            is_valid_input = TRUE;
        }
    return is_valid_input;
}

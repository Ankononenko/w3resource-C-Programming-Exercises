// Copyright 2022 finchren
/*
Write a C program to convert a given integer (in seconds) to hours, minutes and seconds. Go to the editor
Test Data :
Input seconds: 25300
Expected Output:
There are:
H:M:S - 7:1:40

+ 1. Write the plan
+ 2. Function to get the input amount of seconds
+ 3. Invalid input
+ 4. One function to count the result (three for i or while loops,
    each of which devide by 3600 to get the hours then by 60 to get the minutes and in the end we get the seconds).
    Or I can use just regular devision and devide the remainder to get the next value
+ 5. Output the result
+ 6. Test
+ 7. Cpplint test
+ 8. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_amount_of_seconds(int *seconds_input);
void print_invalid_input();
void count_the_result(int seconds_input, int *hours, int *minutes, int *seconds);
void print_output(int hours, int minutes, int seconds);

int main() {
    int seconds_input = -1;
    if (input_amount_of_seconds(&seconds_input)) {
        int hours = -1, minutes = -1, seconds = -1;
        count_the_result(seconds_input, &hours, &minutes, &seconds);
        print_output(hours, minutes, seconds);
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_output(int hours, int minutes, int seconds) {
    printf("There are: \n"
    "H:M:S - %d:%d:%d", hours, minutes, seconds);
}

void count_the_result(int seconds_input, int *hours, int *minutes, int *seconds) {
    *hours = seconds_input / 3600;
    seconds_input -= *hours * 3600;
    *minutes = seconds_input / 60;
    seconds_input -= *minutes * 60;
    *seconds = seconds_input;
}

int input_amount_of_seconds(int *seconds_input) {
    int is_valid_input = TRUE;
    char newline = '\n';
    printf("Input seconds: ");
    if (!scanf("%d%c", seconds_input, &newline) || newline != '\n' || *seconds_input <= 0) {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

void print_invalid_input() {
    printf("There can only be a positive amount of seconds. Input is taken as a one whole number");
}

// Copyright 2022 finchren
/*
Write a C program that read 5 numbers and counts the number of positive numbers and negative numbers
Test Data :
Input the first number: 5
Input the second number: -4
Input the third number: 10
Input the fourth number: 15
Input the fifth number: -1
Expected Output:
Number of positive numbers: 3
Number of negative numbers: 2

√ 1. Write a plan to complete the exercise
√ 2. Function to take the five numbers and write them to an array of numbers
√ 2.0 Greeting messages
√ 2.5 Invalid input
√ 3. Function to iterate over the array and count negative and positive numbers
√ 4. Output the result
√ 5. Test
√ 6. Cpplint test
√ 7. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int take_input(int numbers[5]);
void print_invalid_input();
void print_greeting(int index);
void count_numbers(int *positive, int *negative, const int numbers[5]);
void output_result(int positive, int negative);

int main() {
    int numbers[5] = {0, 0, 0, 0, 0};
    if (take_input(numbers)) {
        int positive = 0, negative = 0;
        count_numbers(&positive, &negative, numbers);
        output_result(positive, negative);
    } else {
        print_invalid_input();
    }
    return 0;
}

void output_result(int positive, int negative) {
    printf("Number of positive numbers: %d \n"
           "Number of negative numbers: %d", positive, negative);
}

void count_numbers(int *positive, int *negative, const int numbers[5]) {
    for (int number = 0; number <= 4; ++number) {
        if (numbers[number] >= 0) {
            ++*positive;
        } else {
            ++*negative;
        }
    }
}

void print_greeting(int index) {
    char ordinal_numbers[5][10] = {"first", "second",
                         "third", "fourth", "fifth"};
    printf("Input the %s number: ", ordinal_numbers[index]);
}

void print_invalid_input() {
    printf("Only one number is taken at a time \n"
    "At the end of the line only newline is accepted.");
}

int take_input(int numbers[5]) {
    int is_valid_input = FALSE, index = 0;
    char newline = '\n';
    print_greeting(index);
    while (scanf("%d%c", &numbers[index], &newline) &&
           newline == '\n' && index < 4) {
        ++index;
        print_greeting(index);
    }
    if (index == 4) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

// Copyright 2022 finchren
/*
Write a C program that read 5 numbers and sum of all odd values between them
Test Data :
Input the first number: 11
Input the second number: 17
Input the third number: 13
Input the fourth number: 12
Input the fifth number: 5
Expected Output:
Sum of all odd values: 46

✔ 1. Write plan to complete the exercise
✔ 2. Take input of the numbers
✔ 3. Invalid input
✔ 4. Function to sum the odd numbers
✔ 5. Output the result
✔ 6. Test
✔ 7. Cpplint test
✔ 8. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_numbers(int array_of_numbers[]);
void print_greeting(int index_of_ordinal_number);
void print_invalid_input();
int sum_odd(int array_of_numbers[]);
void output_result(int sum);

int main() {
    int array_of_numbers[5];
    array_of_numbers[0] = 1;
    if (input_numbers(array_of_numbers)) {
        int sum = -1;
        sum = sum_odd(array_of_numbers);
        output_result(sum);
    }
    return 0;
}

void output_result(int sum) {
    printf("Sum of all odd values: %d", sum);
}

int sum_odd(int array_of_numbers[]) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        if (array_of_numbers[i] % 2 != 0) {
            sum += array_of_numbers[i];
        }
    }
    return sum;
}

void print_invalid_input() {
    printf("Program takes only one number at a time"
        "at the end of the line should be a newline");
}

void print_greeting(int index_of_ordinal_number) {
    char ordinal_numbers[5][10] = {
        "first", "second", "third", "fourth", "fifth"
    };
    printf("Input the %s number ", ordinal_numbers[index_of_ordinal_number]);
}

int input_numbers(int array_of_numbers[]) {
    int is_valid_input = TRUE, i = 0;
    char newline = '\n';
    while (i != 5 && newline == '\n' && is_valid_input == TRUE) {
        print_greeting(i);
        if (!scanf("%d%c", &array_of_numbers[i], &newline) || newline != '\n') {
            is_valid_input = FALSE;
            print_invalid_input();
        }
        ++i;
    }
    return is_valid_input;
}

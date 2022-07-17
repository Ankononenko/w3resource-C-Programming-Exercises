// Copyright 2022 finchren
/*
Write a C program to print all numbers between 1 to 100 which divided by
a specified number and the remainder will be 3

Test Data :
Input an integer: 25
Expected Output:
3
28
53
78

√ 1. Write the plan to complete the exercise
√ 2. Take the input
√ 3. Invalid input
√ 4. Function to iterate over the range from 1 to 100 and pass values to the array
√ 5. Print out the result using a separate function
√ 7. Test
√ 8. Cpplint test
√ 9. Add and push
*/

#include <stdio.h>
#include <string.h>
#define NMAX = 100

enum is_valid{
    FALSE,
    TRUE
};

int input_dividor(int *dividor);
void print_invalid_input();
void find_the_numbers(const int dividor, int array_of_numbers[]);
void output_result(int array_of_numbers[]);

int main() {
    int dividor = 0;
    if (input_dividor(&dividor)) {
        int kMaxSizeOfArray = 100, zero = 0;
        int array_of_numbers[kMaxSizeOfArray];
        memset(array_of_numbers, zero,
            kMaxSizeOfArray * sizeof(array_of_numbers[kMaxSizeOfArray]));
        find_the_numbers(dividor, array_of_numbers);
        output_result(array_of_numbers);
    } else {
        print_invalid_input();
    }
    return 0;
}

void output_result(int array_of_numbers[]) {
    int index = 0;
    while (array_of_numbers[index] != 0) {
        printf("%d\n", array_of_numbers[index]);
        ++index;
    }
    if (index == 0 && array_of_numbers[index] == 0) {
        printf("No numbers could be found");
    }
}

void find_the_numbers(const int dividor, int array_of_numbers[]) {
    int index = 0;
    for (int number = 1; number <= 100; ++number) {
        if (number % dividor == 3) {
            array_of_numbers[index] = number;
            ++index;
        }
    }
}

void print_invalid_input() {
    printf("The dividor cannnot be zero. \n"
    "The input takes only one number at a time. \n"
    "At the end of the line only a newline is accepted");
}

int input_dividor(int *dividor) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input an integer: ");
    if (scanf("%d%c", dividor, &newline) && newline == '\n' && *dividor != 0) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

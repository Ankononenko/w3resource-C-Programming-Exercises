// Copyright 2022 finchren
/*
Write a C program to compute the sum of consecutive odd numbers from a given pair of integers
Test Data :
Input a pair of numbers (for example 10,2):
Input first number of the pair: 10
Input second number of the pair: 2
Expected Output:
List of odd numbers: 3
5
7
9
Sum=24

√ 1. Write a plan to complete the exercise
√ 2. Take the input
√ 3. Invalid input
√ 4. Function to iterate over the range of numbers and find the sum
√ 5. Output the result
√ 6. Test
√ 7. Cpplint test
√ 8. Add and push
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum is_valid{
    FALSE,
    TRUE
};

int take_input(int *number);
void print_greeting(const char *ordinal);
void print_invalid_input();
void find_odd(int array_of_odd[], const int first, const int second);
void print_odd(int array_of_odd[], const int kSizeOfArray);
int find_sum(int array_of_odd[], const int kSizeOfArray);
void print_sum(const int sum);

int main() {
    int first_num = 0;
    char first_string[] = "first";
    print_greeting(first_string);
    if (take_input(&first_num)) {
        int second_num = 0;
        char second_string[] = "second";
        print_greeting(second_string);
        if (take_input(&second_num)) {
            int kSizeOfArray = 0;
            kSizeOfArray = abs(first_num - second_num) / 2;
            int array_of_odd[kSizeOfArray];
            memset(array_of_odd, 0, kSizeOfArray * sizeof(int));
            find_odd(array_of_odd, first_num, second_num);
            if (array_of_odd[0] != 0 && array_of_odd[1] != 0) {
                print_odd(array_of_odd, kSizeOfArray);
                int sum = 0;
                sum = find_sum(array_of_odd, kSizeOfArray);
                print_sum(sum);
            } else {
                printf("No odd numbers were found");
            }
        } else {
            print_invalid_input();
        }
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_sum(const int sum) {
    printf("Sum = %d", sum);
}

int find_sum(int array_of_odd[], const int kSizeOfArray) {
    int sum = 0;
    for (int index = 0; index < kSizeOfArray; ++index) {
        sum += array_of_odd[index];
    }
    return sum;
}

void print_odd(int array_of_odd[], const int kSizeOfArray) {
    printf("List of odd numbers: \n");
    for (int index = 0; index < kSizeOfArray; ++index) {
        printf("%d\n", array_of_odd[index]);
    }
}

void find_odd(int array_of_odd[], const int first, const int second) {
    int start = 0, end = 0, array_index = 0;
    if (first > second || first < second) {
        start = first < second ? first : second;
        end = first > second ? first : second;
    } else {
        start = first;
        end = second;
    }
    for (int number = start; number <= end; ++number) {
        if (number % 2 != 0) {
            array_of_odd[array_index] = number;
            ++array_index;
        }
    }
}

void print_invalid_input() {
    printf("The script takes only one number at a time \n"
    "At the end of the line only newline is accepter \n");
}

void print_greeting(const char *ordinal) {
    printf("Input %s number of the pair: \n", ordinal);
}

int take_input(int *number) {
    int is_valid_input = FALSE;
    char newline = '\0';
    if (scanf("%d%c", number, &newline) && newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

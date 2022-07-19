// Copyright 2022 finchren
/*
Write a program in C to find the prime numbers within a range of numbers.
Test Data :
Input starting number of range: 1
Input ending number of range : 50
Expected Output :
The prime number between 1 and 50 are :
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

√ 1. Write a plan to complete the exercise
√ 2. Take input of starting and ending values
√    Invalid input
√ 3. Funciton to iterate over the range and find prime numbers
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

int input_numbers(int *number);
void print_invalid_input();
void print_greeting(char *ordinal_string);
void find_primes(int start, int end);

int main() {
    int start = 0;
    char starting[] = "starting";
    print_greeting(starting);
    if (input_numbers(&start)) {
        int end = 0;
        char ending[] = "ending";
        print_greeting(ending);
        if (input_numbers(&end) && start <= end) {
            find_primes(start, end);
        } else {
            print_invalid_input();
        }
    } else {
        print_invalid_input();
    }
    return 0;
}

void find_primes(int start, int end) {
    int amount_of_primes_found = 0;
    printf("The prime numbers between %d and %d are: \n", start, end);
    for (int number = start > 1 ? start : 2; number <= end; ++number) {
        int divider_counter = 0;
        for (int divider = 2; divider < number; ++divider) {
            if (number % divider == 0) {
                ++divider_counter;
            }
        }
        if (divider_counter == 0) {
            ++amount_of_primes_found;
            printf("%d ", number);
        }
    }
    if (amount_of_primes_found == 0) {
        printf("No prime numbers in the set range could be found \n");
    }
}

void print_greeting(char *custom_string) {
    printf("Input %s number of range: ", custom_string);
}

void print_invalid_input() {
    printf("Prime number is a natural number greater than 1 \n"
    "That means that you can input only range of positive numbers \n"
    "At the end of the line only a newline is accepted"
    "and range should consist at least of one number");
}

int input_numbers(int *number) {
    int is_valid_input = FALSE;
    char newline = '\n';
    if (scanf("%d%c", number, &newline) && newline == '\n' && *number > 1) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

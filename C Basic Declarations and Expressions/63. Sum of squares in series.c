// Copyright School 21 finchren 2022

/*
Task:
Write a C program that accepts a positive integer n less than 100
from the user and prints out the sum 1^4 + 2^4 + 4^4 + 7^4 + 11^4 + • • • + m4 ,
where m is less than or equal to n. Print appropriate message.
Input a positive number less than 100: 68
Sum of the series is 37361622

✔ 1. Write a plan to complete the exercise
✔ 2. Input
✔ 3. Invalid input
✔ 3.5 Function to get pow 
✔ 4. Function to find the sum
✔ 5. Output result
✔ 6. Test
✔ 7. Cpplint test
✔ 8. Add and push
*/

#include <stdio.h>

enum is_valid {
    FALSE,
    TRUE
};

int input_num(int* num);
void invalid_input();
void find_pow(const int base, const int pow, int* result);
void find_sum(const int num, int* sum);
void output_result(const int sum);

int main() {
    int num = TRUE;
    if (input_num(&num)) {
        int sum = FALSE;
        find_sum(num, &sum);
        output_result(sum);
    } else {
        invalid_input();
    }
    return 0;
}

void find_pow(const int base, const int pow, int* result) {
    *result = base;
    for (int index = 1; index < pow; ++index) {
        *result *= base;
    }
}

void output_result(const int sum) {
    printf("Sum of the series is %d\n", sum);
}

void find_sum(const int num, int* sum) {
    int base, pow = 4, result = FALSE;
    for (int index = 1; base <= num; ++index) {
        find_pow(base, pow, &result);
        *sum += result;
        base += index;
    }
}

void invalid_input() {
    printf("Input can only be one whole number that is less than 100\n"
        "At the end only a newline is accepted\n"
        "Only positive number is accepted\n");
}

int input_num(int* num) {
    int is_valid_input = FALSE, max_limit = 100;
    char newline = '\n';
    printf("Input a positive number less than 100: ");
    if (scanf("%d%c", num, &newline) && newline == '\n'
        && *num > 0 && *num < max_limit) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

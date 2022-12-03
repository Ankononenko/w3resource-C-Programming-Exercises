// Copyright School 21 finchren 2022

/*
Write a C program that reads an integer and find all its divisor
Test Data:
Input an integer: 45
Expected Output:
All the divisor of 45 are:
1
3
5
9
15
45

✔ 1. Write a plan to complete the exercise
✔ 2. Take input
✔ 3. Invalid input
✔ 4. Function to find and output the divisors
✔ 5. Test
✔ 6. Cpplint test
✔ 7. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(int* num);
void invalid_input();
void output_divisors(const int num);

int main() {
    int num = FALSE;
    if (input_num(&num)) {
        output_divisors(num);
    } else {
        invalid_input();
    }
    return 0;
}

void output_divisors(const int num) {
    printf("All the divisor of %d are:\n", num);
    if (!num) {
        printf("Zero has infinitely many divisors."
        "Please try another number\n");
    } else {
        for (int divisor = 1; divisor <= num; ++divisor) {
            if (!(num % divisor)) {
                printf("%d\n", divisor);
            }
        }
    }
}

void invalid_input() {
    printf("The script takes only one number.\n"
    "After the line only newline is expected\n");
}

int input_num(int* num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input an integer: ");
    if (scanf("%d%c", num, &newline)) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

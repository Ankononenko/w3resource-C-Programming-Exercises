  // Copyright School 21 finchren 2022

/*
Task:
Write a C program that accepts a positive integer less than 500
and prints out the sum of the digits of this number
Input a positive number less than 500:
Sum of the digits of 347 is 14

✔ 1. Write a plan to complete the exercise
✔ 2. Input
✔ 3. Invalid input
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
void find_sum(const int num, int* sum);
void output_result(const int num, const int sum);

int main() {
    int num = FALSE;
    if (input_num(&num)) {
        int sum = FALSE;
        find_sum(num, &sum);
        output_result(num, sum);
    } else {
        invalid_input();
    }
    return 0;
}

void output_result(const int num, const int sum) {
    printf("Sum of the digits of %d is %d\n", num, sum);
}

void find_sum(const int num, int* sum) {
    int temp_num = num, current_num = FALSE, divisor = 10;
    while (temp_num > 0) {
        current_num = temp_num % divisor;
        *sum += current_num;
        temp_num /= divisor;
    }
}

void invalid_input() {
    printf("Input can only be one number less than 500\n"
        "At the end only a newline is accepted\n"
        "Only positive numbers are accepted\n");
}

int input_num(int* num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input a positive number less than 500: ");
    if (scanf("%d%c", num, &newline) && newline == '\n'
        && *num > 0 && *num < 500) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

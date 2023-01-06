// Copyright School 21 finchren 2022

/*
Task:
Write a C program which reads an integer (7 digits or fewer) and count number of 3s in the given number
Sample Input: 538453
Sample Output:
Input a number: The number of threes in the said number is 2

✔ 1. Write a plan to complete the exercise
✔ 2. Input, invalid input
✔ 3. Function to count the certain numbers and output the result
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(int* num);
void invalid_input();
void count_occurrences_of_num(const int num, int* count,
    const int num_to_search);
void output_result(const char name_of_num[], const int count);

int main() {
    int num = FALSE;
    if (input_num(&num)) {
        int count = FALSE, num_to_search = 3;
        char name_of_num[] = "three";
        count_occurrences_of_num(num, &count, num_to_search);
        output_result(name_of_num, count);
    } else {
        invalid_input();
    }
    return 0;
}

void output_result(const char name_of_num[], const int count) {
    printf("The number of %s in the said number is %d\n", name_of_num, count);
}

void count_occurrences_of_num(const int num, int* count,
const int num_to_search) {
    int temp_num = num, current_num = FALSE, divisor = 10;
    while (temp_num) {
        current_num = temp_num % divisor;
        if (current_num == num_to_search) {
            ++*count;
        }
        temp_num /= divisor;
    }
}

void invalid_input() {
    printf("The script takes only one number that is 7 digits or fewer\n"
           "At the end of the input only a newline is accepted\n");
}

int input_num(int* num) {
    int is_valid_input = FALSE,
    max_seven_digit_num = 9999999, min_seven_digit_num = -9999999;
    char newline = FALSE;
    printf("Input a number: ");
    if (scanf("%d%c", num, &newline) && newline == '\n' &&
    *num <= max_seven_digit_num && *num >= min_seven_digit_num) {
        is_valid_input = TRUE;
    }
    if (*num < 0) {
        *num *= -1;
    }
    return is_valid_input;
}

// Copyright School 21 finchren 2022

/*
Task:
Write a C program to calculate the sum of all number not divisible by 17 between two given integer numbers (<=)
Test Data :
Input the first integer: 50 
Input the second integer: 99
Expected Output:
Sum: 3521

✔ 1. Write a plan to complete the exercise
✔ 2. Take input
✔ 3. Invalid input
✔ 4. Function to return the resulting number
✔ 5. Output result
✔ 6. Test
✔ 7. Cpplint test
✔ 8. Add and push
*/

#include <stdio.h>

#define IS_GREATER(first_num, second_num) second_num > first_num

enum is_valid{
    FALSE,
    TRUE
};

int input_nums(char* string, int* num);
int is_first_gt_second(int first_num, int second_num);
void print_invalid_input();
void print_greater();
int find_sum_of_divisors(int first_num, int second_num);
void print_result(int result);

int main() {
    int first_num = 0;
    char first_string[24] = "Input the first integer";
    if (input_nums(first_string, &first_num)) {
        int second_num = 0;
        char second_string[25] = "Input the second integer";
        if (input_nums(second_string, &second_num)) {
            int is_second_gt_first = FALSE;
            is_second_gt_first = IS_GREATER(first_num, second_num);
            if (is_second_gt_first) {
                int result = 0;
                result = find_sum_of_divisors(first_num, second_num);
                print_result(result);
            } else {
                print_greater();
            }
        } else {
            print_invalid_input();
        }
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_result(int result) {
    printf("Sum: %d", result);
}

int find_sum_of_divisors(int first_num, int second_num) {
    int divisor = 17, sum = 0;
    for (int index = first_num; index <= second_num; ++index) {
        if (index % divisor != 0) {
            sum += index;
        }
    }
    return sum;
}

void print_greater() {
    printf("Second num should be greater than the first num\n");
}

void print_invalid_input() {
    printf("Input should be only a number, one a time\n");
}

int input_nums(char* string, int* num) {
    int is_valid_input = TRUE;
    char newline = '\0';
    printf("%s\n", string);
    if (!scanf("%d%c", num, &newline) || newline != '\n') {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

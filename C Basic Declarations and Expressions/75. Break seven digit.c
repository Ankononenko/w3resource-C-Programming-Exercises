// Copyright School 21 finchren 2022

/*
Task:
75 Write a C program that accepts one seven-digit number
and separates the number into its individual digits,
and prints the digits separated from one another by two spaces each
Sample Input: 2345678
Input a seven digit number:
Output: 2 3 4 5 6 7 8

✔ 1. Write a plan to complete the exercise
✔ 2. Input num and invalid input
✔ 3 Function to find each number and output it 
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
void print_digits(const int num);

int main() {
    int num = FALSE;
    if (input_num(&num)) {
        print_digits(num);
    } else {
        invalid_input();
    }
    return 0;
}

void print_digits(const int num) {
    int temp_num = num;
    while (temp_num > 0) {
        printf("%d  ", temp_num % 10);
        temp_num /= 10;
    }
}

void invalid_input() {
    printf("Number should be a seven-digit one\n"
    "At the end of the line only a newline is accepted\n");
}

int input_num(int* num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    if (scanf("%d%c", num, &newline) && newline == '\n'
    && *num >= 1000000 && *num <= 9999999) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

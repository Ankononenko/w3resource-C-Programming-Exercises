// Copyright School 21 finchren 2022

/*
Task:
Write a C program that reads in a five-digit integer and determines whether or not it’s a palindrome
Sample Input: 33333
Sample Output:

Input a five-digit number: 33333 is a palindrome.

✔ 1. Write a plan to complete the exercise
✔ 2. Input, invalid input
✔ 3. Is palindrome function and output
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(char array_of_num[]);
void print_invalid_input();
int check_if_is_palindrome(const char array[]);
void output_result(const char array_of_num[], const int is_palindrome);

int main() {
    int kMaxSize = 5;
    char array_of_num[kMaxSize];
    if (input_num(array_of_num)) {
        int is_palindrome = check_if_is_palindrome(array_of_num);
        output_result(array_of_num, is_palindrome);
    } else {
        print_invalid_input();
    }
    return 0;
}

int check_if_is_palindrome(const char array[]) {
    int array_size_to_center = 2, is_palindrome = TRUE,
    min_index = 0, max_index = 4;
    while (min_index < array_size_to_center && is_palindrome) {
        if (array[min_index] != array[max_index]) {
            is_palindrome = FALSE;
        }
        ++min_index;
        --max_index;
    }
    return is_palindrome;
}

void output_result(const char array_of_num[], const int is_palindrome) {
    if (is_palindrome) {
        printf("%c%c%c%c%c is a palindrome\n", array_of_num[0], array_of_num[1],
        array_of_num[2], array_of_num[3], array_of_num[4]);
    } else {
        printf("%c%c%c%c%c isn't a palindrome\n", array_of_num[0],
        array_of_num[1], array_of_num[2], array_of_num[3], array_of_num[4]);
    }
}

void print_invalid_input() {
    printf("The script takes only one number that is 5-digits long\n"
        "At the end only a newline is accepted\n");
}

int check_is_digit(const int num) {
    int is_digit = num >= 48 && num <= 57 ? TRUE : FALSE;
    return is_digit;
}

int input_num(char array_of_num[]) {
    int is_valid_input = FALSE;
    char newline = FALSE;
    printf("Input a five-digit number: ");
    if (scanf("%c%c%c%c%c%c", &array_of_num[0], &array_of_num[1],
    &array_of_num[2], &array_of_num[3], &array_of_num[4], &newline)
    && newline == '\n' &&
    check_is_digit(array_of_num[0]) && check_is_digit(array_of_num[1]) &&
    check_is_digit(array_of_num[2]) && check_is_digit(array_of_num[3]) &&
    check_is_digit(array_of_num[4])) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

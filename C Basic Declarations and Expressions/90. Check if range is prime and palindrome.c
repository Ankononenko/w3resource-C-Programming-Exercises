// Copyright School 21 finchren 2023

/*
Task:
Write a C program to find all prime palindromes in the range of two given numbers x and y (5 <= x<y<= 1000,000,000)
A number is called prime palindrome if the number is both a prime number and a palindrome.
Sample Output:
Input two numbers (separated by a space):
List of prime palindromes:
0
1

✔ 1. Write a plan to complete the exercise
✔ 2. Function to check if a num is prime
✔ 3. Function to check if a num is a palindrome
✔ 3.1 Input and invalid input
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

void iterate_over_nums(const int start, const int end);
int check_if_num_is_prime(const int num);
int check_if_num_is_palindrome(const int num);
int get_len(const int num);
int s21_pow(const int base, const int exponent);
int input_nums(int* start, int* end);
void invalid_input();

enum __bool{
    FALSE,
    TRUE
};

int main() {
    int start = 0, end = 0;
    if (input_nums(&start, &end)) {
        iterate_over_nums(start, end);
    } else {
        invalid_input();
    }
    return 0;
}

void invalid_input() {
    printf("Only two numbers separeted by a space can be entered\n"
           "At the end of the line a newline is expected\n"
           "Starting number should be less than the ending num\n");
}

int input_nums(int* start, int* end) {
    int is_valid_input = FALSE;
    char newline = '\0';
    printf("Input two numbers (separated by a space): ");
    if (scanf("%d %d%c", start, end, &newline)
    && newline == '\n' && *start <= *end) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

int s21_pow(const int base, const int exponent) {
    int result = base;
    for (int index = 2; index <= exponent; ++index) {
        result *= base;
    }
    return result;
}

int get_len(const int num) {
    int temp_num = num, len = 0;
    while (temp_num) {
        temp_num /= 10;
        ++len;
    }
    return len;
}

int check_if_num_is_palindrome(const int num) {
    int is_palindrome = TRUE, temp_num = num,
    first_num = 0, last_num = 0, pow_of_ten = get_len(num) - 1;
    if (get_len(num) > 1) {
        while (temp_num > 9 && is_palindrome) {
            first_num = temp_num / s21_pow(10, pow_of_ten);
            temp_num -= s21_pow(10, pow_of_ten) * first_num;
            pow_of_ten -= 2;
            last_num = temp_num % 10;
            temp_num /= 10;
            if (first_num != last_num) {
                is_palindrome = FALSE;
            }
        }
    }
    if (num == 0 || num == 1) {
        is_palindrome = FALSE;
    }
    return is_palindrome;
}

int check_if_num_is_prime(const int num) {
    int is_prime = TRUE;
    for (int index = 2; index < num; ++index) {
        if (!(num % index)) {
            is_prime = FALSE;
        }
    }
    return is_prime;
}

void iterate_over_nums(const int start, const int end) {
    for (int index = start; index <= end; ++index) {
        printf("List of prime palindromes:\n");
        if (check_if_num_is_prime(index)) {
            if (check_if_num_is_palindrome(index)) {
                printf("%d\n", index);
            }
        }
    }
}

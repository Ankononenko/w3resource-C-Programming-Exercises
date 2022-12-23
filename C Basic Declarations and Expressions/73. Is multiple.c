// Copyright School 21 finchren 2022

/*
Task:
73. Write a C program that reads in two integers and check whether the first integer is a multiple of the second integer
Sample Input: 9 3
Sample Output:
Input the integers: 9 3
9 is a multiple of 3.

✔ 1. Write a plan to complete the exercise
✔ 2. Input and invalid input
✔ 3.1 Fucntion to check whether the first integer is a multiple of the second integer
✔ 3.2. Output result
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(int* first, int* second);
void invalid_input();
int is_multiple(const int first, const int second);
void output_result_is_multiple(const int first, const int second);
void output_result_is_not_multiple(const int first, const int second);

int main() {
    int first = FALSE, second = FALSE;
    if (input_num(&first, &second)) {
        if (is_multiple(first, second)) {
            output_result_is_multiple(first, second);
        } else {
            output_result_is_not_multiple(first, second);
        }
    } else {
        invalid_input();
    }
    return 0;
}

void output_result_is_not_multiple(const int first, const int second) {
    printf("%d isn't a multiple of %d.\n", first, second);
}


void output_result_is_multiple(const int first, const int second) {
    printf("%d is a multiple of %d.\n", first, second);
}

int is_multiple(const int first, const int second) {
    return first % second == 0 ? 1 : 0;
}

void invalid_input() {
    printf("Only integers separetaed by a space are accepted\n"
    "At the end of the line should be a newline\n"
    "Numbers cannot be zero\n");
}

int input_num(int* first, int* second) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input the integers: ");
    if (scanf("%d %d%c", first, second, &newline) && newline == '\n'
            && *second != 0 && *first != 0) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

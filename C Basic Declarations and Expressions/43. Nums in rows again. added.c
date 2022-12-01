// Copyright Scholl 21 finchren 2022

/*

Write a C program that reads two integers p and q, print p number of lines in a sequence of 1 to q in a line
Test Data :
Input number of lines: 5
Number of characters in a line: 6
Expected Output:
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30

✔ 1. Write a plan to complete the exercise
✔ 2. Take input
✔ 3. Invalid input
✔ 4. Function for multiplication
✔ 5. Output result
✔ 6. Test
✔ 7. Cpplint test
8. Git add, git push

*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(int *num, char greeting[]);
void invalid_input();
void output_result(int num_lines, int num_chars);
int get_max_len(int num);
void print_zeros(int num_zeros);
void add(int* result);
void output_a_row(int* result, int num_lines, int num_chars);

int main() {
    int num_lines = FALSE;
    char enter_num_lines[] = "Input number of lines:";
    if (input_num(&num_lines, enter_num_lines)) {
        int num_chars = FALSE;
        char enter_num_chars[] = "Number of characters in a line:";
        if (input_num(&num_chars, enter_num_chars)) {
            output_result(num_lines, num_chars);
        } else {
            invalid_input();
        }
    } else {
        invalid_input();
    }
    return 0;
}

void print_zeros(int num_zeros) {
    for (int index = 0; index < num_zeros; ++index) {
        printf("%d", 0);
    }
}

void add(int* result) {
    ++(*result);
}

void output_result(int num_lines, int num_chars) {
    int result = FALSE;
    for (int index = 1; index <= num_lines; ++index) {
        output_a_row(&result, num_lines, num_chars);
    }
}

void output_a_row(int* result, int num_lines, int num_chars) {
    int biggest_num = FALSE, max_num_zeros = FALSE,
        current_num_zeros = FALSE;
    biggest_num = num_lines * num_chars;
    max_num_zeros = get_max_len(biggest_num);
    for (int row_index = 0; row_index < num_chars; ++row_index) {
        add(result);
        current_num_zeros = max_num_zeros - get_max_len(*result);
        print_zeros(current_num_zeros);
        printf("%d ", *result);
    }
    printf("\n");
}

int get_max_len(int num) {
    int num_zeros = FALSE;
    while (num > 9) {
        num/=10;
        ++num_zeros;
    }
    return num_zeros;
}

void invalid_input() {
    printf("The script takes only one number\n"
    "There can be only positive number of rows and nums of chars in the line.\n"
    "No negative numbers or zeros allowed\n");
}

int input_num(int *num, char greeting[]) {
    printf("%s\n", greeting);
    int is_valid_input = FALSE;
    char newline = '\n';
    if (scanf("%d%c", num, &newline) && newline == '\n' && *num > 0) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

// Copyright School 21 finchren 2022

/*
Write a C program to print 3 numbers in a line, starting from 1 and print n lines.
Accept number of lines (n, integer) from the user
Test Data :
Input number of lines: 5
Expected Output:
1 2 3
4 5 6
7 8 9
10 11 12
13 14 15

✔ 1. Write a plan to complete the exercise
✔ 2. Input
✔ 3. Invalid input
✔ 4. Output the result
✔ 4.1 Insert zeros so the result would inlined:
    00001 00002 00003
    00010 00020 00030
    00100 00200 00300
    01000 02000 03000
    10000 20000 30000
✔ 5. Test
✔ 6. Cpplint test
7. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(int *num);
void invalid_input();
void output_result(int num);
int get_max_len(int num);
void print_zeros(int num_zeros);

int main() {
    int num = FALSE;
    if (input_num(&num)) {
        output_result(num);
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

void output_result(int num) {
    int num_zeros = 0, current_len = 0, previous_len = 1;
    num_zeros = get_max_len(num);
    for (int index = 1; index <= num; ++index) {
        current_len = get_max_len(index);
        if (current_len >= previous_len) {
            ++previous_len;
            --num_zeros;
        }
        print_zeros(num_zeros);
        printf("%d ", index);
        if (!(index % 3)) {
            printf("\n");
        }
    }
}

int get_max_len(int num) {
    int num_zeros = 0;
    while (num > 9) {
        num/=10;
        ++num_zeros;
    }
    return num_zeros;
}

void invalid_input() {
    printf("The script takes only one number\n"
    "The number should be postive value and divisible by three\n");
}

int input_num(int *num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    if (scanf("%d%c", num, &newline) && newline == '\n' &&
        *num > 0 && *num % 3 == 0) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

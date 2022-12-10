// Copyright School 21 finchren 2022

/*
Task:
Write a C program to reverse and print a given number
Input a number:
The original number = 234
The reverse of the said number = 432

✔ 1. Write a plan to complete the exercise
✔ 2. Input
✔ 3. Invalid input
✔ 4. Function to reverse the number
✔ 5. Output result
✔ 6. Test
✔ 7. Cpplint test
✔ 8. Add and push
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum is_valid {
    FALSE,
    TRUE
};

int input_num(int* num);
void invalid_input();
void reverse_num(const int num);

int main() {
    int num = FALSE;
    if (input_num(&num)) {
        reverse_num(num);
    } else {
        invalid_input();
    }
    return 0;
}

void reverse_num(const int num) {
    int pow_of_ten = 10, temp_num = num, current = FALSE;
    while (temp_num > 0) {
        current = temp_num % 10;
        temp_num /= pow_of_ten;
        printf("%d", current);
    }
}

void invalid_input() {
    printf("Input can only be a single whole number\n"
        "At the end only a newline is accepted\n");
}

int input_num(int* num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    if (scanf("%d%c", num, &newline) && newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

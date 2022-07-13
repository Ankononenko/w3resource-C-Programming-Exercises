// Copyright 2022 finchren
/*
Write a C program that reads two integers and checks whether they are multiplied or not
Test Data :
Input the first number: 5
Input the second number: 15
Expected Output:
Multiplied!

✔ 1. Write plan to complete the exercise
✔ 2. Take input
✔ 3. Invalid input
✔ 4. Check if one number can be divided by the other without a remainder
✔ 5. Output the result
✔ 6. Test
✔ 7. Cpplint test
✔ 8. Add and push
*/

#include <stdio.h>

enum is_valid {
    FALSE,
    TRUE
};

int input_numbers(int *number, int *index);
void print_invalid_input();
int check_division(int first, int second);

int main() {
    int first = -1, index = 0;
    if (input_numbers(&first, &index)) {
        int second = -1;
        if (input_numbers(&second, &index)) {
            if (check_division(first, second)) {
                printf("Multiplied!");
            } else {
                printf("Cannot be multiplied");
            }
        } else {
            print_invalid_input();
        }
    } else {
        print_invalid_input();
    }
    return 0;
}

int check_division(int first, int second) {
    int divided_without_remainder = FALSE, temp = 1;
    if (first > second) {
        temp = first % second;
        if (temp == 0) {
            divided_without_remainder = TRUE;
        }
    } else {
        temp = second % first;
        if (temp == 0) {
            divided_without_remainder = TRUE;
        }
    }
    return divided_without_remainder;
}

void print_greeting(int index) {
    char ordinal_numbers[2][10] = {"first", "second"};
    printf("Input the %s number: ", ordinal_numbers[index]);
}

void print_invalid_input() {
    printf("Number cannot be zero, the script takes only one number at a time"
    "and at the end only newline is accepted");
}

int input_numbers(int *number, int *index) {
    int is_valid_input = TRUE;
    char newline = '\0';
    print_greeting(*index);
    if (!scanf("%d%c", number, &newline) || newline != '\n' || *number == 0) {
        is_valid_input = FALSE;
    }
    ++*index;
    return is_valid_input;
}

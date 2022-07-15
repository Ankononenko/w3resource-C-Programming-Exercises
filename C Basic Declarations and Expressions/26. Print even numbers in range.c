// Copyright 2022 finchren
/*
Write a C program that prints all even numbers between 1 and 50 (inclusive)
Test Data :
Even numbers between 1 to 50 (inclusive):
Expected Output:
2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50

√ 1. Write a plan to complete the exercise
√ 1.5 Check if valid range
√ 2. Function to print even numbers in the set range
√ 3. Test
√ 4. Cpplint test
√ 5. Add and push
*/

#include <stdio.h>

enum is_valid {
    FALSE,
    TRUE
};

int check_if_range_is_valid(int start, int end);
void print_even(int start, int end);

int main() {
    int start = 1, end = 50;
    if (check_if_range_is_valid(start, end)) {
        print_even(start, end);
    }
    return 0;
}

void print_even(int start, int end) {
    for (int number = start; number <= end; ++number) {
        if (number % 2 == 0) {
            printf("%d", number);
            if (number != end) {
                printf(" ");
            }
        }
    }
}

int check_if_range_is_valid(int start, int end) {
    int is_valid = FALSE;
    if (start < end) {
        is_valid = TRUE;
    }
    return is_valid;
}

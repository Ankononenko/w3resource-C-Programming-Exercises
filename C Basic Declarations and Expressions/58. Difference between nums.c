// Copyright School 21 finchren 2022

/*
Task:
Write a C program that accepts 4 real numbers from the keyboard and print out
the difference of the maximum and minimum values of these four numbers
Input four numbers: 1.54 1.236 1.3625 1.002
Difference is 0.5380

✔ 1. Write a plan to complete the exercise
✔ 2. Input
✔ 3. Invalid input
✔ 4. Function to find diff
✔ 5. Output result
✔ 6. Test
✔ 7. Cpplint test
✔ 8. Add and push
*/

#include <stdio.h>

enum is_valid {
    FALSE,
    TRUE
};

int input_nums(double array_of_nums[], const int kMaxElements);
void invalid_input();
void find_diff(double array_of_nums[], const int kMaxElements, double* diff);
void output_diff(const double diff);

int main() {
    int kMaxElements = 4;
    double array_of_nums[kMaxElements];
    if (input_nums(array_of_nums, kMaxElements)) {
        double diff = FALSE;
        find_diff(array_of_nums, kMaxElements, &diff);
        output_diff(diff);
    } else {
        invalid_input();
    }
    return 0;
}

void output_diff(const double diff) {
    printf("Difference is %.4lf\n", diff);
}

void find_diff(double array_of_nums[], const int kMaxElements, double* diff) {
    *diff = array_of_nums[0] - array_of_nums[1];
    double current = FALSE;
    for (int element_a = 0; element_a < kMaxElements; ++element_a) {
        for (int element_b = 0; element_b < kMaxElements; ++element_b) {
            current = array_of_nums[element_a] - array_of_nums[element_b];
            *diff = current < *diff ? current : *diff;
        }
    }
    if (*diff < 0) {
        *diff *= -1;
    }
}

void invalid_input() {
    printf("Input can only be four numbers,"
        "each number divided from another by a newline\n"
        "At the end only a newline is accepted\n");
}

int input_nums(double array_of_nums[], const int kMaxElements) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input four numbers: \n");
    for (int index = 0; index < kMaxElements; ++index) {
        if (scanf("%lf%c", &array_of_nums[index], &newline)
            && newline == '\n') {
            is_valid_input = TRUE;
        } else {
            is_valid_input = FALSE;
            break;
        }
    }
    return is_valid_input;
}

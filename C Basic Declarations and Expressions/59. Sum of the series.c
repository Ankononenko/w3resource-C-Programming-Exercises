// Copyright School 21 finchren 2022

/*
Task:
Write a C program to display sum of series 1 + 1/2 + 1/3 + ………. + 1/n
Input any number: 4
1 + 1/2 + 1/3 + 1/4
Sum = 1/10

✔ 1. Write a plan to complete the exercise
✔ 2. Input
✔ 3. Invalid input
✔ 3.5 Output series of nums
✔ 4. Function to find the sum
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

int input_num(int* num);
void invalid_input();
void output_series_of_sum(const int divident, const int num);
void find_sum(const int num, int* sum);
void output_result(const int divident, const int sum);

int main() {
    int num = TRUE;
    if (input_num(&num)) {
        int sum = FALSE, divident = 1;
        output_series_of_sum(divident, num);
        find_sum(num, &sum);
        output_result(divident, sum);
    } else {
        invalid_input();
    }
    return 0;
}

void output_result(const int divident, const int sum) {
    printf("Sum = %d/%d\n", divident, sum);
}

void output_series_of_sum(const int divident, const int num) {
    printf("%d", divident);
    if (num > 1) {
        printf(" + ");
    }
    for (int index = 2; index <= num; ++index) {
        printf("%d/%d", divident, index);
        if (index != num) {
            printf(" + ");
        }
    }
    printf("\n");
}

void find_sum(const int num, int* sum) {
    for (int index = 1; index <= num; ++index) {
        *sum += + index;
    }
    *sum += 1 / num;
}

void invalid_input() {
    printf("Input can only be one number\n"
        "At the end only a newline is accepted\n"
        "Only positive number is accepted\n");
}

int input_num(int* num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input any number: ");
    if (scanf("%d%c", num, &newline) && newline == '\n' && *num > 0) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

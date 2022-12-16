// Copyright School 21 finchren 2022

/*
Task:
Write a C program that accepts integers from the user until a zero or a negative number,
display the number of positive values, the minimum value, the maximum value and the average of all numbers
Input a positive integer:
Input next positive integer: 15
Input next positive integer: 25
Input next positive integer: 37
Input next positive integer: 43
Number of positive values entered is 4
Maximum value entered is 43
Minimum value entered is 15
Average value is 30.0000

✔ 1. Write a plan to complete the exercise
✔ 2. Input until zero or negative
✔ 3. Invalid input
✔ 4.0 Function to get number of positve values
✔ 4.1 Function for min
✔ 4.3 Function for max
✔ 4.4 Function for average
✔ 5. Output result
✔ Fix nan problem
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
void print_greeting();
void ask_for_input(int* num, double* num_of_ints,
    int* min, int* max, double* average);
double get_num_of_ints(double num_of_ints);
int get_min(int current_min, int num);
int get_max(int current_min, int num);
double get_average(double num_of_ints, double sum);
void output_result(const int min, const int max,
    const double average, const double num_of_ints);
void check_if_average_is_nan(double* average);

int main() {
    int num = TRUE, min = FALSE, max = FALSE;
    double num_of_ints = FALSE, average = FALSE;
    print_greeting();
    ask_for_input(&num, &num_of_ints, &min, &max, &average);
    check_if_average_is_nan(&average);
    output_result(min, max, average, num_of_ints);
    return 0;
}

void check_if_average_is_nan(double* average) {
    // According to the IEEE standard, NaN values have the odd property
    // that comparisons involving them are always false.
    // That is, for a float f, f != f will be true only if f is NaN.
    if (*average != *average) {
        printf("here");
        *average = 0.0;
    }
}

void output_result(const int min, const int max,
    const double average, const double num_of_ints) {
    printf("Number of positive values entered is %.0lf\n"
        "Maximum value entered is %d\n"
        "Minimum value entered is %d\n"
        "Average value is %.4lf\n", num_of_ints, max, min, average);
}

void ask_for_input(int* num, double* num_of_ints,
    int* min, int* max, double* average) {
    int is_first_run = TRUE;
    double sum = FALSE;
    while (*num > 0) {
        if (input_num(num)) {
            if (*num > 0) {
                if (is_first_run) {
                    *min = *num;
                    *max = *num;
                    is_first_run = FALSE;
                }
                *num_of_ints = get_num_of_ints(*num_of_ints);
                *min = get_min(*min, *num);
                *max = get_max(*max, *num);
                sum += *num;
            }
        } else {
            invalid_input();
            fflush(stdin);
        }
    }
    *average = get_average(*num_of_ints, sum);
}

double get_average(double num_of_ints, double sum) {
    return sum / num_of_ints;
}

int get_max(int current_max, int num) {
    return num > current_max ? num : current_max;
}

int get_min(int current_min, int num) {
    return num < current_min ? num : current_min;
}

double get_num_of_ints(double num_of_ints) {
    ++num_of_ints;
    return num_of_ints;
}

void print_greeting() {
    printf("Input a positive integer:\n");
}

void invalid_input() {
    printf("Input can only be one whole number\n"
        "At the end only a newline is accepted\n"
        "Please try again");
}

int input_num(int* num) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input next positive integer: ");
    if (scanf("%d%c", num, &newline) && newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

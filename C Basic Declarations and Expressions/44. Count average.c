// Copyright School 21 finchren 2022

/*
Write a C program to calculate the average marks of mathematics of some students. 
Input 0 (excluding to calculate the average) or negative value to terminate the input process
Test Data :
Input Mathematics marks (0 to terminate): 10
15
20
25
0
Expected Output:
Average marks in Mathematics: 17.50

✔ 1. Write a plan to complete the exercise
✔ 2. Take input while 0 or negative number
✔ 3. Invalid input
✔ 4. Function to count the average value
✔ 5. Output result
✔ 6. Test
✔ 7. Cpplint test
✔ 8. Git add, git push

*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_num(double* sum, double* num_of_marks, const char greeting[]);
void invalid_input();
void count_average(const double sum, const double num_of_marks,
    double* average);
void output_result(const double average);

int main() {
    double sum = FALSE, num_of_marks = FALSE;
    char greeting[] = "Input Mathematics marks"
        "(0 or negative number to terminate):";
    if (input_num(&sum, &num_of_marks, greeting)) {
        double average = FALSE;
        count_average(sum, num_of_marks, &average);
        output_result(average);
    } else {
        invalid_input();
    }
    return 0;
}

void output_result(const double average) {
    printf("Average marks in Mathematics: %.2lf\n", average);
}

void count_average(const double sum, const double num_of_marks,
    double* average) {
    *average = sum / num_of_marks;
}

void invalid_input() {
    printf("The script takes only one number per line\n"
    "At the end of the line only a newline is allowed\n"
    "Negative numbers or zeros are used to terminate the script"
    "and count the average mark\n"
    "At least one valid number should be entered");
}

int input_num(double* sum, double* num_of_marks, const char greeting[]) {
    printf("%s\n", greeting);
    int is_valid_input = TRUE;
    double current_num = FALSE;
    char newline = '\n';
    while (is_valid_input) {
        if (scanf("%lf%c", &current_num, &newline) && newline == '\n') {
            if (current_num <= 0) {
               break;
            }
            *sum += current_num;
            ++(*num_of_marks);
            is_valid_input = TRUE;
        } else {
            is_valid_input = FALSE;
        }
    }
    if (!*num_of_marks) {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

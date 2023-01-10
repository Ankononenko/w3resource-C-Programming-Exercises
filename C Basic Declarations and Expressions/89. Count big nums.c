// Copyright School 21 finchren 2023

/*
Task:
Write a C programming to calculate (x + y + z) for each pair of integers x, y and z where -2^31 <= x, y, z<= 2^31-1
Sample Output:
Result: 140733606875472

✔ 1. Write a plan to complete the exercise
✔ 2. Function to count
✔ 3 Input, invalid input and output the result
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_nums(double* x, double* y, double* z);
void invalid_input();
double count_sum(const double x, const double y, const double z);
void output_result(const double sum);


int main() {
    double sum = 0.0;
    double x = 0.0, y = 0.0, z = 0.0;
    if (input_nums(&x, &y, &z)) {
        sum = count_sum(x, y, z);
        output_result(sum);
    } else {
        invalid_input();
    }
    return 0;
}

void invalid_input() {
    printf("The script takes only three numbers\n"
           "At the end of the line only a newline is expected\n");
}

int input_nums(double* x, double* y, double* z) {
    int is_valid_input = FALSE;
    char newline = '\0';
    printf("Enter three nums separated by a space to count their sum\n"
           "At the end of the line a newline is expected\n");
    if (scanf("%lf %lf %lf%c", x, y, z, &newline) && newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

void output_result(const double sum) {
    printf("Result: %.0lf\n", sum);
}

double count_sum(const double x, const double y, const double z) {
    return x + y + z;
}

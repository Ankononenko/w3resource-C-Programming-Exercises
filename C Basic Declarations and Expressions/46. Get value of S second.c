// Copyright School 21 finchren 2022

/*
Write a C program to calculate the value of S where S = 1 + 3/2 + 5/4 + 7/8
Expected Output:
Value of series: 4.62

✔ 1. Write a plan to complete the exercise
✔ 2. Fucntion to count
✔ 3. Output result
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Git add, git push

*/

#include <stdio.h>

void count_s(double max_range, double* s);
void output_result(double s);

int main() {
    double max_range = 8.0, s = 0.0;
    count_s(max_range, &s);
    output_result(s);
    return 0;
}

void output_result(double s) {
    printf("Value of S: %.2lf\n", s);
}

void count_s(double max_range, double* s) {
    double current_result = 1.0, divisor = 1.0;
    while (divisor <= max_range) {
        *s += current_result / divisor;
        printf("%.2lf/%.2lf ", current_result, divisor);
        current_result += 2.0;
        divisor *= 2.0;
    }
}

// Copyright School 21 finchren 2022

/*
45. Write a C program to calculate the value of S where S = 1 + 1/2 + 1/3 + … + 1/50
Expected Output:
Value of S: 4.50

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
    double max_range = 50.0, s = 0.0;
    count_s(max_range, &s);
    output_result(s);
    return 0;
}

void output_result(double s) {
    printf("Value of S: %.2lf\n", s);
}

void count_s(double max_range, double* s) {
    double current_result = 1.0;
    for (double index = 1.0; index <= max_range; ++index) {
        *s += current_result / index;
    }
}

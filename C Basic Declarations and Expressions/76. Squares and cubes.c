// Copyright School 21 finchren 2022

/*
Task:
Write a C program that calculates and prints the squares and cubes
of the numbers from 0 to 20 and uses tabs to display them in a table of values
Sample Output:
Number Square Cube
=========================
0 0 0
1 1 1
2 4 8
3 9 27
.....
18 324 5832
19 361 6859
20 400 8000

✔ 1. Write a plan to complete the exercise
✔ 2. Function to output the current number, square and cube
✔ 3. Function to iterate over the range and print the lines
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int s21_pow(const int base, const int exponent);
void print_line(const int current_num);
void print_lines_in_range(const int max_range);

int main() {
    int max_range = 20;
    print_lines_in_range(max_range);
    return 0;
}

int s21_pow(const int base, const int exponent) {
    int result = base;
    if (exponent == 0 && base != 0) {
        result = 1;
    } else if (exponent != 0 && base == 0) {
        result = 0;
    } else {
        for (int index = 1; index < exponent; ++index) {
            result *= base;
        }
    }
    return result;
}

void print_line(const int current_num) {
    printf("%d %d %d\n",
    current_num, s21_pow(current_num, 2), s21_pow(current_num, 3));
}

void print_lines_in_range(const int max_range) {
    for (int index = 0; index <= max_range; ++index) {
        print_line(index);
    }
}

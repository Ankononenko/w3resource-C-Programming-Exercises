// Copyright School 21 finchren 2022

/*
Task:
Write a C program to print a binomial coefficient table
Mx 0 1 2 3 4 5 6 7 8 9 10
----------------------------------------------------------
0 1
1 1 1
2 1 2 1
3 1 3 3 1
4 1 4 6 4 1
5 1 5 10 10 5 1
6 1 6 15 20 15 6 1
7 1 7 21 35 35 21 7 1
8 1 8 28 56 70 56 28 8 1
9 1 9 36 84 126 126 84 36 9 1
10 1 10 45 120 210 252 210 120 45 10 1

✔ 1. Write a plan to complete the exercise
✔ 2. Find out how to calculate binomial coefficient table
✔ 3. Output result
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

void get_binomial_coefficient(const int row_index);
void print_rows(const int max_rows);

int main() {
    int max_rows = 10;
    print_rows(max_rows);
    return 0;
}

void print_rows(const int max_rows) {
    for (int row_index = 0; row_index <= max_rows; ++row_index) {
        printf("%2d", row_index);
        get_binomial_coefficient(row_index);
    }
}

void get_binomial_coefficient(const int row_index) {
    int binom = 1;
    for (int column_index; column_index <= row_index; ++column_index) {
        if (row_index != 0 && column_index != 0) {
            binom = binom * (row_index - column_index + 1) / column_index;
            printf("%4d", binom);
        }
    }
    printf("\n");
}

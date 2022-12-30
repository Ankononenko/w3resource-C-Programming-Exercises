// Copyright School 21 finchren 2022

/*
Task:
Write a C program using looping to produce the following table of values
Sample Output:

x       x+2     x+4     x+6
--------------------------------
1       3       5       7
4       6       8       10
7       9       11      13
10      12      14      16
13      15      17      19

✔ 1. Write a plan to complete the exercise
✔ 2. Increment
✔ 3. Loop
✔ 4. Spaces
✔ 5. Test
✔ 6. Cpplint test
✔ 7. Add and push
*/

#include <stdio.h>

void output_top_of_the_table();
void output_x(int* x, const int index);
void loop(int max_num_of_elements);

int main() {
    int max_num_of_elements = 20;
    output_top_of_the_table();
    loop(max_num_of_elements);
    return 0;
}

void loop(int max_num_of_elements) {
    int x = 1;
    for (int index = 1; index <= max_num_of_elements; ++index) {
        output_x(&x, index);
    }
}

void output_x(int* x, const int index) {
    printf("%-8d", *x);
    *x += 2;
    if (!(index % 4)) {
        printf("\n");
    }
}

void output_top_of_the_table() {
    printf("x       x+2     x+4     x+6\n"
        "--------------------------------\n");
}

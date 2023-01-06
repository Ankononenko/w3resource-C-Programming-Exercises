// Copyright School 21 finchren 2023

/*
Task:
Write a C program to calculate and print the average of some integers. Accept all the values preceding 888
Sample Input:12
15
24
888
Sample Output:
Input each number on a separate line (888 to exit):

The average value of the said numbers is 17.000000

✔ 1. Write a plan to complete the exercise
✔ 2. Input to an array until 888, invalid input
✔ 3. Function to count the average and output the result
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

enum is_valid{
    FALSE,
    TRUE
};

void print_greeting();
int input_num(double array[], const int index);
void iterate_until_stop_num(int current_element,
    const int stop_num, int is_valid_input, double array[], int* index);
void invalid_input();
void count_average(const double array[], const int max_size, double* result);
void output_result(const double result);

int main() {
    double *array;
    int index = 0, is_valid_input = TRUE, stop_num = 888, current_element = 0;
    array = (double*)malloc(sizeof(double));
    if (array == NULL) {
        printf("memory cannot be allocated\n");
    } else {
        print_greeting();
        iterate_until_stop_num(current_element,
            stop_num, is_valid_input, array, &index);
        double result = 0;
        count_average(array, index, &result);
        output_result(result);
        free(array);
    }
    return 0;
}

void output_result(const double result) {
    printf("The average value of the said numbers is %lf\n", result);
}

void count_average(const double array[], const int max_size, double* result) {
    double sum = 0;
    for (int index = 0; index < max_size - 1; ++index) {
        sum += array[index];
    }
    *result = sum / (max_size - 1);
}

void iterate_until_stop_num(int current_element, const int stop_num,
int is_valid_input, double array[], int* index) {
    while (current_element != stop_num) {
    is_valid_input = input_num(array, *index);
    if (!is_valid_input) {
        invalid_input();
        fflush(stdin);
        continue;
    }
    current_element = array[*index];
    if (is_valid_input) {
        ++*index;
        array = (double*)realloc(array, (*index) * sizeof(double));
        }
    }
}

void invalid_input() {
    printf("The script takes only one number at a time\n"
           "At the end of the line only a newline is accepted\n"
           "Please try again\n");
}

int input_num(double array[], const int index) {
    int is_valid_input = FALSE;
    char newline = '\0';
    if (scanf("%lf%c", &array[index], &newline) && newline == '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

void print_greeting() {
    printf("Input each number on a separate line (888 to exit):\n");
}

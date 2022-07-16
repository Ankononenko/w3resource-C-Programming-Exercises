// Copyright 2022 ficnhren
/* 
Write a C program to find and print the square of each one of the even values from 1 to a specified value
Test Data :
List of square of each one of the even values from 1 to a 4 :
Expected Output:
2^2 = 4
4^2 = 16

√ 1. Write a plan to complete the exercise
√ 2. Function to find squares of all even values from the specified start to end values
√ 3. Greeting string
√ 4. Output the result string
√ 5. Test
√ 6. Cpplint test
√ 7. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

enum is_valid{
    FALSE,
    TRUE
};

int check_if_valid_numbers(int start, int end);
int find_squares_and_output_result(int start, int end, int *array_for_squares);
void print_greeting(int start, int end);

int main() {
    int start = 1, end = 100;
    if (check_if_valid_numbers(start, end)) {
        int *array_for_squares = (int*)malloc(1 * sizeof(int));
        if (array_for_squares == NULL) {
            printf("Memory wan't allocated");
        } else {
            find_squares_and_output_result(start, end, array_for_squares);
            free(array_for_squares);
            array_for_squares = NULL;
        }
    }
    return 0;
}

void print_greeting(int start, int end) {
    printf("List of square of each one of the even values from %d to a %d: ",
        start, end);
}

int check_if_valid_numbers(int start, int end) {
    int is_valid_input = FALSE;
    if (start < end) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

int find_squares_and_output_result(int start, int end, int *array_for_squares) {
    int index = 0;
    for (int number = start; number <= end; ++number) {
        if (number % 2 == 0) {
            array_for_squares[index] = number * number;
            printf("%d^%d = %d \n", number, number, array_for_squares[index]);
            ++index;
            array_for_squares = realloc(array_for_squares, index * sizeof(int));
        }
    }
    return index;
}

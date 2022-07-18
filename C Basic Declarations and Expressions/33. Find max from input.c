// Copyright 2022 finchren
/*
Write a C program that accepts some integers from the user and find the highest value and the input position
Test Data :
Input 5 integers:
5
7
15
23
45
Expected Output:
Highest value: 45
Position: 5

√ 1. Write a plan to complete the exercise
√ 2. Input the five ints to the array
√ 3. Invalid input
√ 4. Function to iterate over the array and return the highest value
√ 5. Output the result
√ 6. Test
√ 7. Cpplint test
√ 8. Add and push
*/

#include <stdio.h>
#include <string.h>

#define NMAX 5

enum is_valid{
    FALSE,
    TRUE
};

int input_numbers(int array_of_numbers[NMAX]);
void print_invalid_input();
int find_highest(const int array_of_numbers[NMAX]);
void output_result(int highest_value);

int main() {
    int array_of_numbers[NMAX];
    memset(array_of_numbers, -1, NMAX * sizeof(int));
    if (input_numbers(array_of_numbers)) {
        int highest_value = 0;
        highest_value = find_highest(array_of_numbers);
        output_result(highest_value);
    } else {
        print_invalid_input();
    }
    return 0;
}

void output_result(int highest_value) {
    printf("Highest value: %d", highest_value);
}

int find_highest(const int array_of_numbers[NMAX]) {
    int highest_value = array_of_numbers[0];
    for (int index = 1; index < NMAX; ++index) {
        if (highest_value < array_of_numbers[index]) {
            highest_value = array_of_numbers[index];
        }
    }
    return highest_value;
}

void print_invalid_input() {
    printf("Only one number is taken at a time. \n"
    "At the end of the line only a newline is accepted");
}

int input_numbers(int array_of_numbers[5]) {
    int is_valid_input = TRUE, index = 0;
    char newline = '\n';
    printf("Input 5 integers: \n");
    while (is_valid_input && index < 5) {
        if (!scanf("%d%c", &array_of_numbers[index], &newline) ||
            newline != '\n') {
            is_valid_input = FALSE;
        }
        ++index;
    }
    return is_valid_input;
}

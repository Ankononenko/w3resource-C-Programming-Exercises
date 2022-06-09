// Copyright 2022 finchren
/*
Write a C program that accepts three integers and find the maximum of three
Test Data :
Input the first integer: 25
Input the second integer: 35
Input the third integer: 15
Expected Output:
Maximum value of three integers: 35

+ 1. Think through the structure of the program
+ 2 Study if array of integers are possible in C
+ 3. Write down function to take integers and write them to an array of integers
+ 4. Invalid input
+ 5. Function to find the maximum value from the integers
+ 6. Print out the result
+ 7. Test
+ 8. Cpplint test
9. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int scan_to_the_array(int array_of_numbers[], int *index);
void print_invalid_input();
int find_max(int array_of_numbers[], const int index);
void print_result(int max_number);

int main() {
    int array_of_numbers[3] = {0, 0, 0};
    int index_to_write_to = 0;
    printf("Input the first integer: ");
    if (scan_to_the_array(array_of_numbers, &index_to_write_to)) {
        printf("Input the second integer: ");
        if (scan_to_the_array(array_of_numbers, &index_to_write_to)) {
            printf("Input the third integer: ");
            if (scan_to_the_array(array_of_numbers, &index_to_write_to)) {
                int max_value = 0;
                max_value = find_max(array_of_numbers, index_to_write_to);
                print_result(max_value);
            } else {
                print_invalid_input();
            }
        } else {
            print_invalid_input();
        }
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_result(int max_number) {
    printf("Maximum value of three integers: %d", max_number);
}

int find_max(int array_of_numbers[], const int index) {
    int max = array_of_numbers[0];
    for (int i = 1; i <= index; ++i) {
        if (max < array_of_numbers[i]) {
            max = array_of_numbers[i];
        }
    }
    return max;
}

int scan_to_the_array(int array_of_numbers[], int *index) {
    char endline = '\n';
    int is_valid_input = TRUE;
    if (!scanf("%d%c", &array_of_numbers[*index], &endline) || endline != '\n') {
        is_valid_input = FALSE;
    }
    if (is_valid_input == TRUE) {
        ++(*index);
    }
    return is_valid_input;
}

void print_invalid_input() {
    printf("The input can only be an interger and an endline at the end of the string");
}

/* 
Write a C program that accepts two integers from the user and calculate the sum of the two integers
Test Data :
Input the first integer: 25
Input the second integer: 38
Expected Output:
Sum of the above two integers = 63

+ 1. Function for the first number
+ 2. Function for the second number
+ 3. Invalid input
+ 4. Sum function
+ 5. Output the result
+ 6. Test
+ 7. Cpplint test
+ 8. Add and push
*/

#include <stdio.h>
#define SUM_OF_TWO(first, second) (first) + (second)

enum is_valid_value {
    FALSE,
    TRUE
};

int input_number(int *number);
void print_invalid_input();
void print_result(int sum);

int main() {
    int first_number = 0;
    printf("Input the first integer: ");
    if (!input_number(&first_number)) {
        print_invalid_input();
    } else {
        int second_number = 0;
        printf("Input the second integer: ");
        if (!input_number(&second_number)) {
            print_invalid_input();
        } else {
            int sum = SUM_OF_TWO(first_number, second_number);
            print_result(sum);
            }
    }
    return 0;
}

int input_number(int *number) {
    int is_valid_input = TRUE;
    char endline = '\n';
    if (!scanf("%d%c", number, &endline) || endline != '\n') {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

void print_invalid_input() {
    printf("Invalid input\n"
    "The program takes only one int value per iteration\n");
}

void print_result(int sum) {
    printf("Sum of the above two integers = %d", sum);
}

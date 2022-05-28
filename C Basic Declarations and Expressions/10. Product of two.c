/*
Write a C program that accepts two integers from the user and calculate the product of the two integers
Test Data :
Input the first integer: 25
Input the second integer: 15
Expected Output:
Product of the above two integers = 375

+ 1. Function for the first number
+ 2. Function for the second number
+ 3. Invalid input
+ 4. Product function
+ 5. Output the result
+ 6. Test
+ 7. Cpplint test
+ 8. Add and push
*/

#include <stdio.h>
#define PRODUCT_OF_TWO(first, second) (first) * (second)

enum is_valid_value {
    FALSE,
    TRUE
};

int input_number(int *number);
void print_invalid_input();
void print_result(int product);

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
            int product = PRODUCT_OF_TWO(first_number, second_number);
            print_result(product);
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

void print_result(int product) {
    printf("Product of the above two integers = %d", product);
}

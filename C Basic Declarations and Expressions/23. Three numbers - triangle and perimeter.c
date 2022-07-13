// Copyright 2022 finchren
/* 
Write a C program that reads three floating values and check if it is possible to make a triangle with them.
Also calculate the perimeter of the triangle if the said values are valid
Test Data :
Input the first number: 25
Input the second number: 15
Input the third number: 35
Expected Output:
Perimeter = 75.0

✔ 1. White a plan to complete the exercise
✔ 2. Figure out how to check if three numbers can or cannot make a triangle
    Sum of two sides should be bigger than the third
    And we need to repeat that for all of the sides
✔ 3. Function to take input
✔ 4. Invalid input
✔ 5. Can make a trianle out of the numbers?
✔ 6. Find the perimeter
✔ 7. Output the result
✔ 8. Test
✔ 9. Cpplint test
✔ 10. Add and push
*/

#include <stdio.h>

#define PERIMETER(a, b, c) a + b + c

enum is_valid {
    FALSE,
    TRUE
};

int input_numbers(double numbers[3]);
void print_invalid_input();
int check_if_triangle(double numbers[3]);
void print_not_triangle();
void print_ordinal_greeting(int index);
void print_perimeter(double perimeter);

int main() {
    double array_of_numbers[3] = {0.0, 0.0, 0.0};
    if (input_numbers(array_of_numbers)) {
        if (check_if_triangle(array_of_numbers)) {
            double perimeter =
            PERIMETER(array_of_numbers[0], array_of_numbers[1], array_of_numbers[2]);
            print_perimeter(perimeter);
        } else {
            print_not_triangle();
        }
    } else {
        print_invalid_input();
    }
    return 0;
}

void print_perimeter(double perimeter) {
    printf("Perimeter = %.1lf", perimeter);
}

void print_ordinal_greeting(int index) {
    char ordinal_numbers[3][10] = {"first", "second", "third"};
    printf("Input the %s number: ", ordinal_numbers[index]);
}

void print_not_triangle() {
    printf("A valid triangle cannot be build using those numbers");
}

int check_if_triangle(double numbers[3]) {
    int is_triangle = FALSE;
    double a = 0.0, b = 0.0, c = 0.0;
    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    if ((a + b > c) && (b + c > a) && (c + a > b)) {
        is_triangle = TRUE;
    }
    return is_triangle;
}

void print_invalid_input() {
    printf("Input takes three double numbers one per turn"
    "At the end of the line only newline is accepted");
}

int input_numbers(double numbers[3]) {
    int is_valid_input = TRUE, index = 0;
    char newline = '\0';
    print_ordinal_greeting(index);
    while ((scanf("%lf%c", &numbers[index], &newline))
        && newline == '\n'
        && numbers[index] > 0.0
        && index < 2) {
            ++index;
            print_ordinal_greeting(index);
    }
    if (index < 2) {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

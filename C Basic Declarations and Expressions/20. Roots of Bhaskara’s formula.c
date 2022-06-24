// Copyright 2022 finchren
/*
Write a C program to print the roots of Bhaskara’s formula from the given three floating numbers. 
Display a message if it is not possible to find the roots
Test Data :
Input the first number(a): 25
Input the second number(b): 35
Input the third number(c): 12
Expected Output:
Root1 = -0.60000
Root2 = -0.80000

+ 1. Find out what is Bhashara's formula - I used the formula to count the roots of the quadric equation
    x = (-b ± √b² - 4ac) / 2a
+ 2. Take the input
+ 3. Invalid input
+ 4. Write the universal function to count the two roots
+ 5. Count the result
+ 6. Output the result
+ 7. Test
+ 8. Cpplint test
9. Add and push
*/

#include <stdio.h>
#include <math.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_number(float *pointer_to_the_number);
void invalid_input();
void output_greetings(char *counter_string, char counter_letter);
void count_roots_using(float a, float b, float c, float *x, float *y);
void output_result(float x, float y);

int main() {
    float a = 0;
    output_greetings("first", 'a');
    if (input_number(&a)) {
        float b = 0;
        output_greetings("second", 'b');
        if (input_number(&b)) {
            float c = 0;
            output_greetings("third", 'c');
            if (input_number(&c)) {
                float x = 0, y = 0;
                count_roots_using(a, b, c, &x, &y);
                output_result(x, y);
            } else {
                invalid_input();
            }
        } else {
            invalid_input();
        }
    } else {
        invalid_input();
    }
    return 0;
}

void output_result(float x, float y) {
    printf("Root1 = %.5f \n"
           "Root2 = %.5f", x, y);
}

void count_roots_using(float a, float b, float c, float *x, float *y) {
    *x = ((b * -1) + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    *y = ((b * -1) - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
}

void output_greetings(char *counter_string, char counter_letter) {
    printf("Input the %s number(%c): ", counter_string, counter_letter);
}

void invalid_input() {
    printf("The number can be only one. It cannot be zero."
    "At the of the line only newline is accepted");
}

int input_number(float *pointer_to_the_number) {
    int is_valid_input = TRUE;
    char newline = '\n';
    if (!scanf("%f%c", pointer_to_the_number, &newline) ||
        newline != '\n' ||
        *pointer_to_the_number == 0) {
            is_valid_input = FALSE;
    }
    return is_valid_input;
}

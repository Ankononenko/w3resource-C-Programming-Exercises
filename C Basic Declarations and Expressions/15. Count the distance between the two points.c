// Copyright 2022 finchren
/*
Write a C program to calculate the distance between the two points
Test Data :
Input x1: 25
Input y1: 15
Input x2: 35
Input y2: 10
Expected Output:
Distance between the said points: 11.1803

+ 1. Write the plan to complete the exercise
+ 2. Figure out how to count the distance between the two points
+ 3. Function to take the two pairs of coordinates from a user
+ 4. Invalid input
+ 5. Function to count the distance
+ 6. Test
+ 7. Cpplint test
8. Add and push
*/

#include <stdio.h>
#include <math.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_coordinate(double *pointer_to_the_coordinate);
void print_invalid_input();
double count_the_distance(double x1, double y1, double x2, double y2);
void output_result(double distance);

int main() {
    double x1 = 0.0;
    printf("Input x1: ");
    if (input_coordinate(&x1)) {
        double y1 = 0.0;
        printf("Input y1: ");
        if (input_coordinate(&y1)) {
            double x2 = 0.0;
            printf("Input x2: ");
            if (input_coordinate(&x2)) {
                double y2 = 0.0;
                printf("Input y1: ");
                if (input_coordinate(&y2)) {
                    double distance = count_the_distance(x1, y1, x2, y2);
                    output_result(distance);
                } else {
                    print_invalid_input();
                }
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

void output_result(double distance) {
    printf("Distance between the said points: %.4lf", distance);
}

double count_the_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void print_invalid_input() {
    printf("The program takes only one coordinate that can be a floating point value of a decimal\n"
    "The end character may only be newline");
}

int input_coordinate(double *pointer_to_the_coordinate) {
    int is_valid_input = TRUE;
    char newline = '\n';
    if (!scanf("%lf%c", pointer_to_the_coordinate, &newline) || newline != '\n') {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

// Copyright School 21 - finchren 2022

/*
Task:
Write a C program to read the coordinates(x, y) (in Cartesian system) 
and find the quadrant to which it belongs (Quadrant -I, Quadrant -II, Quadrant -III, Quadrant -IV)
Note: A Cartesian coordinate system is a coordinate system that specifies each point uniquely in a plane by a pair of numerical coordinates.
These are often numbered from 1st to 4th and denoted by Roman numerals: I (where the signs of the (x,y) coordinates are I(+,+), II (−,+), III (−,−), and IV (+,−).

Test Data :
Input the Coordinate(x,y):
x: 25
y: 15
Expected Output:
Quadrant-I(+,+)

✔ 1. Write a plan to complete the exercise
✔ 2. Take input
✔ 3. Invalid input
✔ 4. Check coordinates
✔ 5. Assign roman number
✔ 6. Output result
✔ 7. Test
✔ 8. Cpplint test

*/

#include <stdio.h>
#include <string.h>

enum is_valid {
    FALSE,
    TRUE
};

int read_input(int* x, int* y);
void scan_input(int* num, int* is_valid_input);
void check_coordinate(int coordinate, char* result);
void assign_roman(char x_result, char y_result, char* roman);

int main() {
    int x = 0, y = 0;
    if (read_input(&x, &y)) {
        char x_result = '\0', y_result = '\0';
        check_coordinate(x, &x_result);
        check_coordinate(y, &y_result);
        int kArrayMaxSize = 33;
        char roman[kArrayMaxSize];
        memset(roman, '\0', sizeof(roman));
        assign_roman(x_result, y_result, roman);
        printf("Quadrant - %s (%c, %c)\n", roman, x_result, y_result);
    }
    return 0;
}

void assign_roman(char x_result, char y_result, char* roman) {
    const char plus = '+', minus = '-', zero = '0';
    const char first_quadrant[] = "I", second_quadrant[] = "II",
    third_quadrant[] = "III", forth_quadrant[] = "IV", center[] = "Center",
    on_the_line[] = "On the line, inbetween quadrants";
    if (x_result == plus && y_result == plus) {
        strcpy(roman, first_quadrant);
    } else if (x_result == plus && y_result == minus) {
        strcpy(roman, second_quadrant);
    } else if (x_result == minus && y_result == minus) {
        strcpy(roman, third_quadrant);
    } else if (x_result == minus && y_result == plus) {
        strcpy(roman, forth_quadrant);
    } else if (x_result == zero && y_result == zero) {
        strcpy(roman, center);
    } else {
        strcpy(roman, on_the_line);
    }
}

void check_coordinate(int coordinate, char* result) {
    const char plus = '+', minus = '-', zero = '0';
    if (coordinate > 0) {
        *result = plus;
    } else if (coordinate < 0) {
        *result = minus;
    } else {
        *result = zero;
    }
}

int read_input(int* x, int* y) {
    int is_valid_input = TRUE;
    printf("Input the Coordinate(x,y)\n");
    printf("x: ");
    scan_input(x, &is_valid_input);
    if (is_valid_input) {
        printf("y: ");
        scan_input(y, &is_valid_input);
    }
    return is_valid_input;
}

void scan_input(int* num, int* is_valid_input) {
    char newline = '\n';
    if (!scanf("%d%c", num, &newline) || (newline != '\n')) {
        printf("Invalid input\n");
        printf("Coordinate can only be a number."
        "One number at a time (one per line)\n");
        *is_valid_input = FALSE;
    }
}

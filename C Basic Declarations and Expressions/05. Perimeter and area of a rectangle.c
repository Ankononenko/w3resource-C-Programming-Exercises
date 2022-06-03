/*
Write a C program to compute the perimeter and area of a rectangle with a height of 7 inches. and width of 5 inches
Expected Output:
Perimeter of the rectangle = 24 inches
Area of the rectangle = 35 square inches
*/

#include <stdio.h>

#define PERIMETER(height, width, two) (two) * ((height) + (width))
#define AREA(height, width) (height) * (width)

void print_result(int perimeter, int area);

int main() {
    int height = 7, width = 5, two = 2;
    int perimeter = PERIMETER(height, width, two);
    int area = AREA(height, width);
    print_result(perimeter, area);
    return 0;
}

void print_result(int perimeter, int area) {
    printf("Perimeter of the rectangle = %d inches\n"
    "Area of the rectangle = %d square inches", perimeter, area);
}

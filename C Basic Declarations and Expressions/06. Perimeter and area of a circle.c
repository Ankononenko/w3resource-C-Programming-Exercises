/*
Write a C program to compute the perimeter and area of a circle with a given radius
Expected Output:
Perimeter of the Circle = 37.680000 inches
Area of the Circle = 113.040001 square inches
*/

#include <stdio.h>
#include <math.h>

double find_perimeter(double radius);
double find_area(double radius);
void print_result(double perimeter_found, double area_found);

int main() {
    double radius = 5.998479;
    double perimeter_found = find_perimeter(radius);
    double area_found = find_area(radius);
    print_result(perimeter_found, area_found);

    // The redius wasn't stated in the preconditions of the exercise. Needed to find the radius
    // double radius_f = sqrt(113.040001 / M_PI);
    // printf("%f", radius_f);
    return 0;
}

void print_result(double perimeter_found, double area_found) {
    printf("Perimeter of the Circle = %f inches\n"
    "Area of the Circle = %f square inches\n", perimeter_found, area_found);
}

double find_area(double radius) {
    return (M_PI * pow(radius, 2));
}

double find_perimeter(double radius) {
    return (2 * M_PI * radius);
}

// Copyright School 21 finchren 2022

/*
Write a C program that accepts a distance in centimeters and prints the corresponding value in inches
Test Data:
Input Data: 500
Input the distance in cm: 500
Distance of 500.00 cms is = 196.85 inches

✔ 1. Write a plan to complete the exercise
✔ 2. Input values
✔ 3. Invalid input
✔ 4. Function to convert to inches
✔ 6. Output the result
✔ 7. Test
✔ 9. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input(double* cm);
void invalid_input();
void convert_cm_to_inches(const double cm, double* inches);
void output_result(const double cm, const double inches);

int main() {
    double cm = FALSE;
    if (input(&cm)) {
        double inches = FALSE;
        convert_cm_to_inches(cm, &inches);
        output_result(cm, inches);
    } else {
        invalid_input();
    }
    return 0;
}

void output_result(const double cm, const double inches) {
    printf("Distance of %.2lf cms is = %.2lf inches\n", cm, inches);
}

void convert_cm_to_inches(const double cm, double* inches) {
    double convert_ratio = 2.54;
    *inches = cm / convert_ratio;
}

void invalid_input() {
    printf("Invalid input. The sctipt takes only one number at a time\n"
           "At the end of the input only a newline is expected");
}

int input(double* cm) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input the distance in cm: ");
    if (scanf("%lf%c", cm, &newline) && newline == '\n' && *cm > 0) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

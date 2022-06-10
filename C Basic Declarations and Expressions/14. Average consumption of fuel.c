// Copyright 2022 finchren
/*
Write a C program to calculate a bike’s average consumption from the given total distance
(integer value) traveled (in km) and spent fuel (in liters, float number – 2 decimal point)
Test Data :
Input total distance in km: 350
Input total fuel spent in liters: 5
Expected Output:
Average consumption (km/lt) 70.000

+ 1. Write down a plan of completing the exercise
+ 2. Function to get the distance from the user - double
+ 3. Invalid input for distance
+ 4. Function to get input of liters - double
+ 5. Invalid input for the liters
+ 6. Function to calculate the average consumption
+ 7. Output the final result 
+ 8. Test
+ 9. Cpplint test
10. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_value(double *value);
void print_invalid_input();
double calculate_average_consumption(double distance_km, double fuel_km);
void ask_for_distance();
void ask_for_fuel();
void printf_out_result(double average_consumtion);

int main() {
    double distance_kms = -1.0;
    ask_for_distance();
    if (input_value(&distance_kms)) {
        double fuel_kms = -1.0;
        ask_for_fuel();
        if (input_value(&fuel_kms)) {
            double average_consumtion = -1.0;
            average_consumtion = calculate_average_consumption(distance_kms, fuel_kms);
            printf_out_result(average_consumtion);
        } else {
            print_invalid_input();
        }
    } else {
        print_invalid_input();
    }
    return 0;
}

void printf_out_result(double average_consumtion) {
    printf("Average consumption (km/lt) %.3lf", average_consumtion);
}

void ask_for_fuel() {
    printf("Input total fuel spent in liters: ");
}

void ask_for_distance() {
    printf("Input total distance in km: ");
}

double calculate_average_consumption(double distance_km, double fuel_km) {
    return distance_km / fuel_km;
}

void print_invalid_input() {
    printf("Value should be a single number that can be a decimal number."
    "Only a newline is accepted at the end of input.");
}

int input_value(double *value) {
    int is_valid_input = TRUE;
    char newline = '\n';
    if (!scanf("%lf%c", value, &newline) || newline != '\n' || *value <= 0) {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

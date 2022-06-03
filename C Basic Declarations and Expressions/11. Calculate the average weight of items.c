// Copyright 2022 finchren
/*
!!! Corrected the text of the exercise to make more sence
Write a C program that accepts two item’s weight (floating points' values ) and number of items (floating points' values) and calculate the average weight of the items
Test Data :
Weight of the first type of item: 15
Number of the items: 5
Weight of the second type of item: 25
Number of the items: 4
Expected Output:
Average weight of the items = 19.444444

✔ 0. Fix the exercise to make more sence
✔ 1. Write a plan to compete the exercise
✔ 2. Function to accept floating point values for the calculation
✔ 3. Greeting workflow of the exercise 
✔ 4. Function to count the result
✔ 5. Display the result
✔ 6. Invalid input
✔ 7. Test
✔ 8. Cpplint test
✔ 9. Add and push 
*/

#include <stdio.h>

enum is_valid{
    false,
    true
};

double input_floating_values(double *value_to_enter);
double count_average_weight(double first_item_weight, double second_item_weight,
    double number_of_first_items, double number_of_second_items);
void print_invalid_input();

int main() {
    double first_item_weight = 0.0;
    printf("Weight of the first type of item:\n");
    if (input_floating_values(&first_item_weight) == true) {
        printf("Number of the items:\n");
        double number_of_first_items = 0.0;
        if (input_floating_values(&number_of_first_items) == true) {
            printf("Weight of the second type of item:\n");
            double second_item_weight = 0.0;
            if (input_floating_values(&second_item_weight) == true) {
                printf("Number of the items:\n");
                double number_of_second_items = 0.0;
                if (input_floating_values(&number_of_second_items) == true) {
            double average_weight = count_average_weight(first_item_weight,
            second_item_weight, number_of_first_items, number_of_second_items);
            printf("Average weight of the items = %lf\n", average_weight);
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

double input_floating_values(double *value_to_enter) {
    int is_valid = true;
    char endline = '\n';
    if (!scanf("%lf%c", value_to_enter, &endline) ||
        *value_to_enter <= 0 || endline != '\n') {
        is_valid = false;
    }
    return is_valid;
}

void print_invalid_input() {
    printf("Weight cannot be less or equal to zero"
    "and single input takes only one number at a time\n");
}

double count_average_weight(double first_item_weight, double second_item_weight,
        double number_of_first_items, double number_of_second_items) {
    double average_weight = 0.0;
    average_weight = ((first_item_weight * number_of_first_items)
    + (second_item_weight * number_of_second_items)) /
    (number_of_first_items + number_of_second_items);
    return average_weight;
    }

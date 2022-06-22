// Copyright 2022 finchren
/*
Write a C program to convert a given integer (in days) to years, months and days, assumes that all months have 30 days and all years have 365 days
Test Data :
Input no. of days: 2535
Expected Output:
6 Year(s)
11 Month(s)
15 Day(s)

+ 1. Write a plan to complete the exercise
+ 2. Take input
+ 3. Invalid input
+ 4. Function to iterate over the number and assign the values to the passed variables of years, months and etc
+ 5. Output the result
+ 6. Test
+ 7. Cpplint test
8. Add and push
*/

#include <stdio.h>
#define COUNT_YEARS(number_of_days, days_in_a_year) (number_of_days / days_in_a_year)
#define COUNT_MONTHS(number_of_days, days_in_a_month) (number_of_days / days_in_a_month)
#define GET_REMAINDER(multiplied_value, multiply_value) (multiplied_value) * (multiply_value)

enum is_valid{
    FALSE,
    TRUE
};

int input_days(int *number_of_days);
void print_invalid_input();
void get_years_months_days(int number_of_days, int *years, int *months, int *days);
void output_result(int years, int months, int days);


int main() {
    int number_of_days = -1;
    if (input_days(&number_of_days)) {
        int years = -1, months = -1, days = -1;
        get_years_months_days(number_of_days, &years, &months, &days);
        output_result(years, months, days);
    } else {
        print_invalid_input();
    }
    return 0;
}

void output_result(int years, int months, int days) {
    printf("%d Year(s) \n"
           "%d Month(s) \n"
           "%d Day(s) \n",
        years, months, days);
}

void get_years_months_days(int number_of_days, int *years, int *months, int *days) {
    int days_in_a_year = 365;
    *years = COUNT_YEARS(number_of_days, days_in_a_year);
    number_of_days -= GET_REMAINDER(*years, days_in_a_year);
    int days_in_a_month = 30;
    *months = COUNT_MONTHS(number_of_days, days_in_a_month);
    number_of_days -= GET_REMAINDER(*months, days_in_a_month);
    *days = number_of_days;
}

void print_invalid_input() {
    printf("Number of days can only be positve value"
           "and at the of the line there can be only newline character");
}

int input_days(int *number_of_days) {
    int is_valid_input = TRUE;
    char newline = '\n';
    printf("Input no. of days: ");
    if (!scanf("%d%c", number_of_days, &newline) || *number_of_days <= 0 || newline != '\n') {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

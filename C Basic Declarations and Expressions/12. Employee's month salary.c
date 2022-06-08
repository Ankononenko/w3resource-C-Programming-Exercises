// Copyright 2022 finchren
/*
Write a C program that accepts an employee's ID, total worked hours of a month and the amount he received per hour. Print the employee's ID and salary (with two decimal places) of a particular month
Test Data :
Input the Employees ID(Max. 10 chars): 0342
Input the working hrs: 8
Salary amount/hr: 15000
Expected Output:
Employees ID = 0342
Salary = U$ 120000.00

✔ 1. Write a plan to compete the exercise
✔ 2. Take ID
✔ 3. ID invalid input
✔ 4. Take input of total worked hours
✔ 5. Invalid input of total worked hours per the month
✔ 6. Take input of pay per hour
✔ 7. Invalid input pay per hour
✔ 8. Count the salary per month
✔ 9. Output the result
10. Test
11. Cpplint test
12. Add and push
*/

#include <stdio.h>

enum is_true {
    false,
    true
};

int input_ID(char *pointer_to_the_ID_array);
int input_total_worked_hours_and_hourly_pay(double *value);
double count_month_salary(double worked_hours, double hourly_pay);
void print_invalid_input_ID();
void print_invalid_input_worked_hours_and_pay();
void print_final_output(char *pointer_to_the_ID_array, double month_salary);

int main() {
    char array_for_ID[11] = {'\0'};
    char *pointer_to_the_array = array_for_ID;
    printf("Input the Employees ID(Max. 10 chars): \n");
    if (input_ID(pointer_to_the_array) == true) {
        double worked_hours = 0.0;
        printf("Input the working hrs: \n");
        if (input_total_worked_hours_and_hourly_pay(&worked_hours)) {
            double hourly_pay = 0.0;
            printf("Salary amount/hr: \n");
            if (input_total_worked_hours_and_hourly_pay(&hourly_pay)) {
                double month_salary = count_month_salary(worked_hours, hourly_pay);
                print_final_output(pointer_to_the_array, month_salary);
            } else {
                print_invalid_input_worked_hours_and_pay();
            }
        } else {
        print_invalid_input_worked_hours_and_pay();
        }
    } else {
        print_invalid_input_ID();
    }
    return 0;
}

void print_final_output(char *pointer_to_the_ID_array, double month_salary) {
    printf("Employees ID = ");
    for (int i = 0; i < 10; ++i) {
        if (pointer_to_the_ID_array[i] == '\0') {
            break;
        }
        printf("%c", pointer_to_the_ID_array[i]);
    }
    printf("\n");
    printf("Salary = U$ %.2lf\n", month_salary);
}

double count_month_salary(double worked_hours, double hourly_pay) {
    double month_salary = worked_hours * hourly_pay;
    return month_salary;
}

int input_total_worked_hours_and_hourly_pay(double *value) {
    int is_valid_input = true;
    char endline = '\n';
    if (!scanf("%lf%c", value, &endline) || *value <= 0 || endline != '\n') {
        is_valid_input = false;
    }
    return is_valid_input;
}

int input_ID(char *pointer_to_the_ID_array) {
    int is_valid_input = true;
    char temp_char = '\0';
    for (int i = 0; i < 10; ++i) {
        if (!scanf("%c", &temp_char) || temp_char < '0' || temp_char > '9') {
            is_valid_input = false;
            break;
        } else {
            *pointer_to_the_ID_array = temp_char;
        }
        ++*pointer_to_the_ID_array;
    }
    return is_valid_input;
}

void print_invalid_input_ID() {
    printf("ID must include only a number and is maximum 10-digits long\n");
}

void print_invalid_input_worked_hours_and_pay() {
    printf("The value must be only a positibe number\n");
}

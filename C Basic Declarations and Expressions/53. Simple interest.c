// Copyright School 21 finchren 2022

/*
Write a C program that accepts principle, rate of interest, time and compute the simple interest.
Test Data:
Input Data: p = 10000, r = 10% , t = 12 year
Expected Output:
Input principle, Rate of interest & time to find simple interest:
Simple interest = 12000

✔ 1. Write a plan to complete the exercise
✔ 2. Input values
✔ 3. Invalid input
✔ 4. Function to calculate the simple interest
✔ 6. Output the result
✔ 7. Test
✔ 9. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_data(double* principal, double* rate, double* time);
void invalid_input();
void caluculate_interest(const double principal, const double rate,
    const double time, double* interest);
void output_result(const double interest);

int main() {
    double principal = FALSE, rate = FALSE, time = FALSE;
    if (input_data(&principal, &rate, &time)) {
        double interest = FALSE;
        caluculate_interest(principal, rate, time, &interest);
        output_result(interest);
    } else {
        invalid_input();
    }

    return 0;
}

void output_result(const double interest) {
    printf("Simple interest = %.2lf\n", interest);
}

void caluculate_interest(const double principal, const double rate,
    const double time, double* interest) {
    *interest = principal * (rate / 100) * time;
}

void invalid_input() {
    printf("The values should be only positive numbers, one at a time\n"
"Please try again\n");
}

int input_data(double *principal, double* rate, double* time) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input Data: \n");
    printf("Enter principal:\n\
    *The principal is the amount that initially borrowed from the bank or invested\n");
    if (scanf("%lf%c", principal, &newline) && (newline == '\n') && (*principal > 0)) {
        is_valid_input = TRUE;
    }
    printf("Enter rate without percent sign:\n\
    *Rate is the rate of interest at which the principal amount is given to someone\
    for a certain time, the rate of interest can be 5%%, 10%%, or 13%%, etc\n");
    if (scanf("%lf%c", rate, &newline) && (newline == '\n') && (*rate > 0) && (is_valid_input)) {
        is_valid_input = TRUE;
    }   else {
        is_valid_input = FALSE;
    }
    printf("Enter time (in years):\n\
    *Time is the duration for which the principal amount is given to someone.\n");
    if (scanf("%lf%c", time, &newline) && (newline == '\n') && (*time > 0) && (is_valid_input)) {
        is_valid_input = TRUE;
    }   else {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

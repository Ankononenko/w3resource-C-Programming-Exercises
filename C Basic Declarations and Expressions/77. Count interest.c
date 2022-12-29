// Copyright School 21 finchren 2022

/*
Task:
Write a C program that accepts principal amount,
rate of interest and days for a loan and calculate the simple interest for the loan, using the following formula
interest = principal * rate * days / 365.
Sample Input:
Input loan amount:
10000
Input interest rate:
.1
Input term of the loan in days:
365
Sample Output:
The interest amount is $1000.00

✔ 1. Write a plan to complete the exercise
✔ 2. Functions to take the input and invalid input
✔ 3. Formula
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input(double* value);
void invalid_input();
void get_interest(const double loan_amount, const double interest_rate,
    const double number_of_days, double* interest);
void output_interest(const double interest);
void ask_for_loan_amount();
void ask_for_interest_rate();
void ask_for_number_of_days();

int main() {
    double loan_amount = FALSE;
    ask_for_loan_amount();
    if (input(&loan_amount)) {
        double interest_rate = FALSE;
        ask_for_interest_rate();
        if (input(&interest_rate)) {
            double number_of_days = FALSE;
            ask_for_number_of_days();
            if (input(&number_of_days)) {
                double interest = FALSE;
                get_interest(loan_amount,
                    interest_rate, number_of_days, &interest);
                output_interest(interest);
            } else {
                invalid_input();
            }
        } else {
            invalid_input();
        }
    } else {
        invalid_input();
    }
    return 0;
}

void ask_for_loan_amount() {
    printf("Input loan amount:\n");
}

void ask_for_interest_rate() {
    printf("Input interest rate:\n");
}

void ask_for_number_of_days() {
    printf("Input term of the loan in days:\n");
}

void output_interest(const double interest) {
    printf("The interest amount is $%.2lf\n", interest);
}

void get_interest(const double loan_amount, const double interest_rate,
    const double number_of_days, double* interest) {
        *interest = loan_amount * interest_rate * number_of_days / 365;
}

void invalid_input() {
    printf("Loan amount, rate and number of days"
    "can be only a positive values\n");
}

int input(double* loan_amount) {
    int is_valid_input = FALSE;
    char newline = '\n';
    if (scanf("%lf%c", loan_amount, &newline) &&
    newline == '\n' && *loan_amount > 0) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

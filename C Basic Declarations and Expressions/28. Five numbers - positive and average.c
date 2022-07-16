// Copyright 2022 finchren
/*
Write a C program that read 5 numbers and counts the number of positive numbers and print the average of all positive values.
Test Data :
Input the first number: 5
Input the second number: 8
Input the third number: 10
Input the fourth number: -5
Input the fifth number: 25
Expected Output:
Number of positive numbers: 4
Average value of the said positive numbers: 12.00

√ 1. Write a plan to complete the exercise
√ 2. Function to take the five numbers and write them to an array of numbers
√ 2.0 Greeting messages
√ 2.5 Invalid input
√ 3. Function to iterate over the array and count the average value of all the positive numbers
√ 4. Output the result
√ 5. Test
√ 6. Cpplint test
√ 7. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int take_input(double numbers[5]);
void print_invalid_input();
void print_greeting(int index);
void count_numbers(int *positive, double *average, const double numbers[5]);
void output_result(int positive, double average);

int main() {
    double numbers[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
    if (take_input(numbers)) {
        int positive = 0;
        double average = 0.0;
        count_numbers(&positive, &average, numbers);
        output_result(positive, average);
    } else {
        print_invalid_input();
    }
    return 0;
}

void output_result(int positive, double average) {
    printf("Number of positive numbers: %d \n"
        "Average value of the said positive numbers: %.2lf", positive, average);
}

void count_numbers(int *positive, double *average, const double numbers[5]) {
    for (int number = 0; number <= 4; ++number) {
        if (numbers[number] >= 0) {
            ++*positive;
            *average += numbers[number];
        }
    }
    *average /= *positive;
}

void print_greeting(int index) {
    char ordinal_numbers[5][10] = {"first", "second",
                         "third", "fourth", "fifth"};
    printf("Input the %s number: ", ordinal_numbers[index]);
}

void print_invalid_input() {
    printf("Only one number is taken at a time \n"
    "At the end of the line only newline is accepted.");
}

int take_input(double numbers[5]) {
    int is_valid_input = FALSE, index = 0;
    char newline = '\n';
    print_greeting(index);
    while (scanf("%lf%c", &numbers[index], &newline) &&
           newline == '\n' && index < 4) {
        ++index;
        print_greeting(index);
    }
    if (index == 4) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

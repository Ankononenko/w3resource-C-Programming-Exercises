// Copyright 2022 finchren
/*
Write a C program to read an amount (integer value) and break the amount 
into smallest possible number of bank notes
Test Data :
Input the amount: 375
Expected Output:
There are:
3 Note(s) of 100.00
1 Note(s) of 50.00
1 Note(s) of 20.00
0 Note(s) of 10.00
1 Note(s) of 5.00
0 Note(s) of 2.00
0 Note(s) of 1.00

+ 1. Write a plan to complete the exercise
+ 2. Take the input
+ 3. Invalid input
+ 4. Function to which the values of the bank notes are passed as pointers
+    Inside the function there is some logic that divides, gets the remainder and continues to count
+ 5. Output the result
+ 6. Cpplint test
+ 7. Test
+ 8. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_amount_of_funds(int *amount_of_funds);
void count_the_banknotes(int amount_of_funds, int *hundred, int *fifty, int *twenty,
                            int *ten, int *five, int *two, int *one);
void print_invalid_input();
void output_the_result(int hundred, int fifty, int twenty, int ten, int five, int two, int one);

int main() {
    int amount_of_funds = -1;
    if (input_amount_of_funds(&amount_of_funds) == TRUE) {
        int hundred = -1, fifty = -1, twenty = -1, ten = -1, five = -1, two = -1, one = -1;
        count_the_banknotes(amount_of_funds, &hundred, &fifty, &twenty, &ten, &five, &two, &one);
        output_the_result(hundred, fifty, twenty, ten, five, two, one);
    } else {
        print_invalid_input();
    }
    return 0;
}

void output_the_result(int hundred, int fifty, int twenty, int ten, int five, int two, int one) {
    printf("There are: \n"
        "%d Note(s) of 100.00 \n"
        "%d Note(s) of 50.00 \n"
        "%d Note(s) of 20.00 \n"
        "%d Note(s) of 10.00 \n"
        "%d Note(s) of 5.00 \n"
        "%d Note(s) of 2.00 \n"
        "%d Note(s) of 1.00 \n"
        , hundred, fifty, twenty, ten, five, two, one);
}

void count_the_banknotes(int amount_of_funds, int *hundred, int *fifty, int *twenty,
                            int *ten, int *five, int *two, int *one) {
    *hundred = amount_of_funds / 100;
    amount_of_funds %= 100;
    *fifty = amount_of_funds / 50;
    amount_of_funds %= 50;
    *twenty = amount_of_funds / 20;
    amount_of_funds %= 20;
    *ten = amount_of_funds / 10;
    amount_of_funds %= 10;
    *five = amount_of_funds / 5;
    amount_of_funds %= 5;
    *two = amount_of_funds / 2;
    amount_of_funds %= 2;
    *one = amount_of_funds / 1;
}

void print_invalid_input() {
    printf("Valid amount of funds is a positive whole number\n"
            "At the end of the line only a newline is accepted");
}

int input_amount_of_funds(int *amount_of_funds) {
    int is_valid_input = TRUE;
    char newline = '\n';
    if (!scanf("%d%c", amount_of_funds, &newline) || *amount_of_funds <= 0 || newline != '\n') {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

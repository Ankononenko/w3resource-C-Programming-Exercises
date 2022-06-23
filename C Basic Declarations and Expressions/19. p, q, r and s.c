// Copyright 2022 finchren
/*
Write a C program that accepts 4 integers p, q, r, s from the user where q, r and s are positive and p is even. 
If q is greater than r and s is greater than p and if the sum of r and s is greater than the sum of p and q print "Correct values", otherwise print "Wrong values"
Test Data :
Input the first integer: 15
Input the second integer: 35
Input the third integer: 15
Input the fourth integer: 46
Expected Output:
Correct values

+ 1. Write a plan for the programm
+ 2. Take the input
+ 3. Invalid input
+ 4. Boolean return statement
+ 5. Output the result
+ 6. Test
+ 7. Cpplint test
+ 8. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_the_values(int *value);
void print_greeting(char *string);
void print_invalid_input();
int check_the_statement(int p, int q, int r, int s);

int main() {
    print_greeting("first");
    int p = -1;
    if (input_the_values(&p)) {
        print_greeting("second");
        int q = -1;
        if (input_the_values(&q)) {
            print_greeting("third");
            int r = -1;
            if (input_the_values(&r)) {
                print_greeting("fourth");
                int s = -1;
                if (input_the_values(&s)) {
                    if (check_the_statement(p, q, r, s)) {
                        printf("Correct values");
                    } else {
                        printf("Wrong values");
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
    } else {
        print_invalid_input();
    }
    return 0;
}

int check_the_statement(int p, int q, int r, int s) {
    int correct_values = FALSE;
    if ((q > r) && (s > p) && ((r + s) > (p + q))) {
        correct_values = TRUE;
    }
    return correct_values;
}

void print_greeting(char *string) {
    printf("Input the %s integer: ", string);
}

void print_invalid_input() {
    printf("The value can be only a positve number"
    "and at the end of the line should be a newline");
}

int input_the_values(int *value) {
    int is_valid_input = TRUE;
    char newline = '\n';
    if (!scanf("%d%c", value, &newline) || *value <= 0 || newline != '\n') {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

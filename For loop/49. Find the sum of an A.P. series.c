// Copyright 2022 ficnhren
/*
Write a c program to find out the sum of an A.P. series
Test Data :
Input the starting number of the A.P. series: 1
Input the number of items for the A.P. series: 10
Input the common difference of A.P. series: 4
Expected Output :
The Sum of the A.P. series are :
1 + 5 + 9 + 13 + 17 + 21 + 25 + 29 + 33 + 37 = 190

+ 1. Take input
1.5 Invalid input - To be done later
+ 2. Write a function to find elements
+ 3. Output sum
4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include <stdio.h>

int input_start();
int input_number_of_items();
int input_difference();
void find_and_print_result(int start, int number_of_items, int difference);

int main() {
    int start = input_start();
    int number_of_items = input_number_of_items();
    int difference = input_difference();
    find_and_print_result(start, number_of_items, difference);
    return 0;
}

void find_and_print_result(int start, int number_of_items, int difference) {
    printf("The Sum of the A.P. series are:\n");
    int sum = start, element = start;
    printf("%d ", element);
    for (int i = 0; i < number_of_items - 1; ++i) {
        element += difference;
        printf("+ %d ", element);
        sum += element;
    }
    printf("= %d", sum);
}

int input_start() {
    printf("Input the starting number of the A.P. series:\n");
    int start;
    scanf("%d", &start);
    return start;
}

int input_number_of_items() {
    printf("Input the number of items for the A.P. series:\n");
    int number_of_items;
    scanf("%d", &number_of_items);
    return number_of_items;
}

int input_difference() {
    printf("Input the common difference of A.P. series:\n");
    int difference;
    scanf("%d", &difference);
    return difference;
}

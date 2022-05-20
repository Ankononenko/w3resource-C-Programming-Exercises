// Copyright 2022 finchren
/*
Write a C program to print the following characters in a reverse way
Test Characters: 'X', 'M', 'L'
Expected Output:
The reverse of XML is LMX
*/

#include <stdio.h>

#define ARRAY_SIZE 3

void reverse_array(char *pointer_to_the_array, char *pointer_to_the_reversed_array);
void print_array(char *pointer_to_the_array);
void print_expected_output(char *pointer_to_the_array, char *pointer_to_the_reversed_array);

int main() {
    char array_of_letters[ARRAY_SIZE] = {'X', 'M', 'L'};
    char *pointer_to_the_array = array_of_letters;
    char reversed_array[ARRAY_SIZE];
    char *pointer_to_the_reversed_array = reversed_array;
    reverse_array(pointer_to_the_array, pointer_to_the_reversed_array);
    print_expected_output(pointer_to_the_array, pointer_to_the_reversed_array);
    return 0;
}

void print_expected_output(char *pointer_to_the_array, char *pointer_to_the_reversed_array) {
    printf("The reverse of ");
    print_array(pointer_to_the_array);
    printf("is ");
    print_array(pointer_to_the_reversed_array);
}

void print_array(char *pointer_to_the_array) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%c", pointer_to_the_array[i]);
    }
    printf(" ");
}

void reverse_array(char *pointer_to_the_array, char *pointer_to_the_reversed_array) {
    int max_index = ARRAY_SIZE - 1;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        pointer_to_the_reversed_array[i] = pointer_to_the_array[max_index];
        --max_index;
    }
}

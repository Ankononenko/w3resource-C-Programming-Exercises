// Copyright 2022 finchren
/*
Write a C program to print a block F using hash (#), where the F has a height of six characters and width of five and four characters. And also to print a big 'C'
Expected Output:

######
#
#
#####
#
#
#
    ######
  ##      ##
 #
 #
 #
 #
 #
  ##      ##
    ######

+ 0. Write a function to repeadetly print a char
+ 1. Write a function to print F using for loop
+ 2. Do the same with C
+ 3. Test
+ 4. Add and push

*/

#include <stdio.h>

void print_on_repeat(char char_to_print, int number_of_iterations);
void print_f(char char_to_print_with, char newline);
void print_c(char char_to_print_with, char char_space, char newline);

int main() {
    char hash = '#', space = ' ', newline = '\n';
    print_f(hash, newline);
    print_c(hash, space, newline);
    return 0;
}

void print_on_repeat(char char_to_print_with, int number_of_iterations) {
    for (int i = 0; i < number_of_iterations; ++i) {
        printf("%c", char_to_print_with);
    }
}

void print_f(char char_to_print_with, char newline) {
    for (int i = 0; i < 7; ++i) {
        if (i == 0) {
            print_on_repeat(char_to_print_with, 5);
            print_on_repeat(newline, 1);
        } else if (i == 3) {
            print_on_repeat(char_to_print_with, 4);
            print_on_repeat(newline, 1);
        } else {
            print_on_repeat(char_to_print_with, 1);
            print_on_repeat(newline, 1);
        }
    }
}

void print_c(char char_to_print, char char_space, char newline) {
    for (int i = 0; i < 9; ++i) {
        if (i == 0 || i == 8) {
            print_on_repeat(char_space, 1);
            print_on_repeat(char_space, 3);
            print_on_repeat(char_to_print, 5);
            print_on_repeat(newline, 1);
        } else if (i == 1 || i == 7) {
            print_on_repeat(char_space, 2);
            print_on_repeat(char_to_print, 2);
            print_on_repeat(char_space, 5);
            print_on_repeat(char_to_print, 2);
            print_on_repeat(newline, 1);
        } else {
            print_on_repeat(char_space, 1);
            print_on_repeat(char_to_print, 1);
            print_on_repeat(newline, 1);
        }
    }
}

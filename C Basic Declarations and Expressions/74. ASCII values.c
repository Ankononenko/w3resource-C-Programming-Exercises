// Copyright School 21 finchren 2022

/*
Task:
74. Write a C program to display the integer equivalents of letters (a-z, A-Z)
Sample Output:
List of integer equivalents of letters (a-z, A-Z).
==================================================
97 98 99 100 101 102
103 104 105 106 107 108
109 110 111 112 113 114
115 116 117 118 119 120
121 122 65 66 67 68
69 70 71 72 73 74
75 76 77 78 79 80
81 82 83 84 85 86
87 88 89 90

✔ 1. Write a plan to complete the exercise
✔ 2. Iterate over the range of letters
✔ 3. Output result
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

void iterate_over_lower_chars(int* newline_counter);
void iterate_over_upper_chars(int* newline_counter);
void print_dec_value_and_char(const int index);
void print_newline();
void print_starting_line_of_output();

int main() {
    int counter_for_newline = 0;
    print_starting_line_of_output();
    iterate_over_lower_chars(&counter_for_newline);
    iterate_over_upper_chars(&counter_for_newline);
    return 0;
}

void print_starting_line_of_output() {
    printf("List of integer equivalents of letters (a-z, A-Z).\n"
    "==================================================\n");
}

void iterate_over_lower_chars(int* newline_counter) {
    for (int index = 97; index <= 122; ++index) {
        print_dec_value_and_char(index);
        ++*newline_counter;
        if (*newline_counter % 6 == 0) {
            print_newline();
        }
    }
}

void iterate_over_upper_chars(int* newline_counter) {
    for (int index = 65; index <= 90; ++index) {
        print_dec_value_and_char(index);
        ++*newline_counter;
        if (*newline_counter % 6 == 0) {
            print_newline();
        }
    }
}

void print_dec_value_and_char(const int index) {
    printf("%d ", index);
}

void print_newline() {
    printf("\n");
}

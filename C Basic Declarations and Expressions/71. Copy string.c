// Copyright School 21 finchren 2022

/*
Task:
71. Write a C program to copy a given string into another and count the number of characters copied
Input a string
Original string: w3resource
Number of characters = 10

✔ 1. Write a plan to complete the exercise
✔ 2. Input string and invalid input
✔ 3.1. Function to copy the input string to another and count
✔ 3.2. Output result
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_string(char* string, int* index);
void invalid_input();
void memory_cannot_be_allocated();
void output_string(const char* string, const int index);

int main() {
    char* string;
    int index = FALSE;
    string = (char*)malloc(1 * sizeof(char));
    if (!string) {
        memory_cannot_be_allocated();
    }
    if (input_string(string, &index)) {
        output_string(string, index);
    } else {
        invalid_input();
        free(string);
        return 1;
    }
    free(string);
    return 0;
}

void output_string(const char* string, const int index) {
    printf("Original string: ");
    for (int i = 0; i < index; ++i) {
        printf("%c", string[i]);
    }
    printf("\nNumber of characters = %d\n", index);
}

void memory_cannot_be_allocated() {
    printf("Memory not allocated\n");
}

void invalid_input() {
    printf("String cannot be null. Please try again\n");
}

int input_string(char* string, int* index) {
    int is_valid_input = TRUE;
    char current_char = '\0', newline = '\n';
    printf("Input a string\n");
    while (scanf("%c", &current_char) && current_char != newline) {
        string[*index] = current_char;
        ++*index;
        string = (char*)realloc(string, (*index) * sizeof(char));
        if (!string) {
            memory_cannot_be_allocated();
            break;
        }
    }
    if (!*index) {
        is_valid_input = FALSE;
    }
    return is_valid_input;
}

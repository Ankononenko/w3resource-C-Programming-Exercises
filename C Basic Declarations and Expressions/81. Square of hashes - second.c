// Copyright School 21 finchren 2022

/*
Task:
Write a C program that reads the side (side sizes between 1 and 10 ) of a square and prints a hollow square using hash (#) character
Sample Input: 10
Sample Output:

Input the size of the square: 
##########
#        #
#        #
#        #
#        #
#        #
#        #
#        #
#        #
##########

✔ 1. Write a plan to complete the exercise
✔ 2. Input, invalid input
✔ 3. Print out the suare
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_size(int* size);
void invalid_input();
void print_square(const int size);

int main() {
    int size = FALSE;
    if (input_size(&size)) {
        print_square(size);
    } else {
        invalid_input();
    }
    return 0;
}

void print_square(const int size) {
    for (int index_column = 0; index_column < size; ++index_column) {
        for (int index_element = 0; index_element < size; ++index_element) {
            if (index_column == 0 || index_column == size - 1) {
                printf("#");
            } else {
                if (index_element == 0 || index_element == size - 1) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void invalid_input() {
    printf("Size of the square should be bigger than 0 and less than 10\n");
}

int input_size(int* size) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input the size of the square:\n");
    if (scanf("%d%c", size, &newline) && newline == '\n'
    && *size > 0 && *size <= 10) {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

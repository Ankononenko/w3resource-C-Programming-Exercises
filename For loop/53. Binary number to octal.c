// Copyright 2022 finchren
/*
Write a program in C to convert a binary number to octal
Test Data :
Input a binary number :1001
Expected Output :
The Binary Number : 1001
The equivalent Octal Number : 11

+ 1. Figure out how to convert binary straight to octal
At this moment I can binary -> decimal -> octal. There probably is a better way to do this:
Convert every 3 binary digits (start from bit 0) to 1 octal digit, with binary table from 0 to 7
Ex: 00001100010001 = 00 001 100 010 001 = 1 4 2 1 = 1421
+ 2. Input a dinamic array of chars
3. Convertion: 
    Return the lenght from the array input
    Flip the array
    Iterate over an array by three elements at the time, assign each pair of three from the end of the array octal value
    Output the value
4. Invalid input
5. Test
    Check if all the memory was freed
6. Cpplint test
7. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

enum is_valid{
    TRUE = 1,
    FALSE = 0
};

int input_binary(int *array_lenght, char *pointer_to_binary_array);
void print_invalid_input();
void print_binary_array(char *pointer_to_binary_array);
// void convert_to_octal(char *pointer_to_octal_array, char *pointer_to_binary_array);

int main() {
    char *pointer_binary;
    int array_lenght = 0;
    pointer_binary = (char*)malloc(1 * sizeof(char));
    if (pointer_binary == NULL) {
        printf("Memory could not be allocated");
    } else {
        int is_valid = input_binary(&array_lenght, pointer_binary);
        print_binary_array(pointer_binary);
        printf("\n%d\n", array_lenght - 1);
        if (is_valid == FALSE) {
            print_invalid_input();
        } 
        //     else {
        //     char *pointer_octal;
        //     pointer_octal = (char*)malloc(1 * sizeof(char));
        //     convert_to_octal(pointer_octal, pointer_binary);
        // }
    }
    return 0;
}

// void convert_to_octal(char *pointer_to_octal_array, char *pointer_to_binary_array) {
//     int array_lenght = 1, one_step = 3, index = 0, biggest_binary = 8, temp_octal = 0, binary_divisor = 2;
//     char current_element = pointer_to_binary_array[index];
//     while(current_element != '\0') {
//         for (int i = 0; i <= 3; ++i) {
//             if (current_element == 1) {
//                 temp_octal += biggest_binary / binary_divisor;
        
//             }
//         }
//     }
    
// }

void print_binary_array(char *pointer_to_binary_array) {
    for (int i = 0; ;++i) {
        if (pointer_to_binary_array[i] == '\0') {
            break;
        } 
        printf("%c", pointer_to_binary_array[i]);
    }
}

void print_invalid_input() {
    printf("n/a");
}

int input_binary(int *array_lenght, char *pointer_to_binary_array) {
    int is_valid = TRUE;
    *array_lenght = 1;
    char endline = '\n', temp_char = '\0';
    for (int i = 0; i < *array_lenght; ++i) {
        if(!scanf("%c", &temp_char)) {
            if (pointer_to_binary_array) {
                free(pointer_to_binary_array);
                pointer_to_binary_array = NULL;
            }
            is_valid = FALSE;
        } else {
            if (temp_char == endline) {
                pointer_to_binary_array[i] = '\0';
                break;
            }
            if (temp_char != '1' && temp_char != '0') {
                is_valid = FALSE;
                if (pointer_to_binary_array) {
                free(pointer_to_binary_array);
                pointer_to_binary_array = NULL;
                }
            }
            pointer_to_binary_array[i] = temp_char;
            ++*array_lenght;
            pointer_to_binary_array = (char*)realloc(pointer_to_binary_array, (*array_lenght)*sizeof(char));
        }
    }
    return is_valid;
}

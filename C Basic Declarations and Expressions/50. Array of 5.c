// Copyright School 21 finchren 2022

/*
Write a C program to read an array of length 5 and print the position and value of the array elements of value less than 5
Test Data:
Input the 5 members of the array:
15
25
4
35
40
Expected Output:
A[2] = 4.0

✔ 1. Write a plan to complete the exercise
✔ 2. Create an array and initialize it with default values
✔ 3. Input values
✔ 4. Invalid input
✔ 5. Output the result
✔ 7. Test
✔ 8. Cpplint test
9. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

void init_array(int array[], const int len);
void output_array(int array[], const int len, const int target_value);
int input_value(int array[], const int len);
void invalid_input();

int main() {
    int kLen = 5, target_value = 5;
    int array[kLen];
    init_array(array, kLen);
    if (input_value(array, kLen)) {
        output_array(array, kLen, target_value);
    } else {
        invalid_input();
    }
    return 0;
}

void invalid_input() {
    printf("Input takes only one number\n"
    "At the end of the line can be only a newline");
}

int input_value(int array[], const int len) {
    int is_valid_input = TRUE;
    char newline = '\n';
    printf("Input the 5 members of the array:\n");
    for (int index = 0; index < len; ++index) {
        if (!scanf("%d%c", &array[index], &newline) || newline != '\n') {
            is_valid_input = FALSE;
            break;
        }
    }
    return is_valid_input;
}

void output_array(int array[], const int len, const int target_value) {
    printf("Array values are:\n");
    for (int index = 0; index < len; ++index) {
        if (array[index] < target_value) {
            printf("A[%d] = %d\n", index, array[index]);
        }
    }
}

void init_array(int array[], const int len) {
    for (int index = 0; index < len; ++index) {
        array[index] = 0;
    }
}

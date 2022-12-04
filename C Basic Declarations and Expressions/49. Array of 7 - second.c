// Copyright School 21 finchren 2022

/*
Write a C program to read and print the elements of an array of length 7,
before print, put the triple of the previous position starting from the second position of the array
For example, if the first number is 2, the array numbers must be 2, 6, 18, 54 and 162
Test Data:
Input the first number of the array: 5
Expected Output:
n[0] = 5
n[1] = 15
n[2] = 45
n[3] = 135
n[4] = 405

✔ 1. Write a plan to complete the exercise
✔ 2. Create an array and initialize it with default values
✔ 3. Input values
✔ 4. Invalid input
✔ 5. Modify the values of the array
✔ 6. Output the result
✔ 7. Test
✔ 8. Cpplint test
✔ 9. Add and push
*/

#include <stdio.h>

enum is_valid{
    FALSE,
    TRUE
};

void init_array(int array[], const int len);
void output_array(int array[], const int len);
int input_value(int array[]);
void invalid_input();
void modify_array(int array[], const int len);

int main() {
    int kLen = 7, num_elements = 5;
    int array[kLen];
    init_array(array, kLen);
    if (input_value(array)) {
        modify_array(array, num_elements);
        output_array(array, num_elements);
    } else {
        invalid_input();
    }
    return 0;
}

void modify_array(int array[], const int len) {
    for (int index = 1; index < len; ++index) {
        array[index] = array[index - 1] * 3;
    }
}

void invalid_input() {
    printf("Input takes only one number\n"
    "At the end of the line can be only a newline");
}

int input_value(int array[]) {
    int is_valid_input = FALSE;
    char newline = '\n';
    printf("Input the first number of the array: ");
    if (scanf("%d%c", &array[0], &newline) || newline != '\n') {
        is_valid_input = TRUE;
    }
    return is_valid_input;
}

void output_array(int array[], const int len) {
    printf("Array values are:\n");
    for (int index = 0; index < len; ++index) {
        printf("n[%d] = %d\n", index, array[index]);
    }
}

void init_array(int array[], const int len) {
    for (int index = 0; index < len; ++index) {
        array[index] = 0;
    }
}

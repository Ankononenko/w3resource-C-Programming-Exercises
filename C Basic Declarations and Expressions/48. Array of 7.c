// Copyright School 21 finchren 2022

/*
Write a C program to read and print the elements of an array of length 7, before print replace every negative number, zero with 100
Test Data:
Input the 5 members of the array:
25
45
35
65
15

Expected Output:
Array values are:
n[0] = 25
n[1] = 45
n[2] = 35
n[3] = 65
n[4] = 15

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
int input_values(int array[], const int len);
void invalid_input();
void modify_array(int array[], const int len);

int main() {
    int kLen = 7;
    int array[kLen];
    init_array(array, kLen);
    if (input_values(array, kLen)) {
        modify_array(array, kLen);
        output_array(array, kLen);
    } else {
        invalid_input();
    }
    return 0;
}

// Part of the task - Before print replace every negative number, zero with 100
void modify_array(int array[], const int len) {
    for (int index = 0; index < len; ++index) {
        if (!array[index]) {
            array[index] = 100;
        }
        if (array[index] < 0) {
            array[index] *= -1;
        }
    }
}

void invalid_input() {
    printf("Input takes only one number per line\n"
    "Only numbers are allowed. At the end of the line can be only a newline");
}

int input_values(int array[], const int len) {
    int is_valid_input = TRUE, index = 0;
    char newline = '\n';
    while (index < len && is_valid_input) {
        if (!scanf("%d%c", &array[index], &newline) || newline != '\n') {
            is_valid_input = FALSE;
        }
        ++index;
    }
    return is_valid_input;
}

void output_array(int array[], const int len) {
    for (int index = 0; index < len; ++index) {
        printf("%d ", array[index]);
    }
}

void init_array(int array[], const int len) {
    for (int index = 0; index < len; ++index) {
        array[index] = 0;
    }
}

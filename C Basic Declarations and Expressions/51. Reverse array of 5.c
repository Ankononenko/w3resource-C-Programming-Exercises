// Copyright School 21 finchren 2022

/*
Write a C program to read an array of length 6, change the first element by the last,
the second element by the fifth and the third element by the fourth. 
Print the elements of the modified array
Test Data:
Input the 5 members of the array:
15
20
25
30
35

Expected Output:
array_n[0] = 35
array_n[1] = 30
array_n[2] = 25
array_n[3] = 20
array_n[4] = 15

✔ 1. Write a plan to complete the exercise
✔ 2. Create an array and initialize it with default values
✔ 3. Input values
✔ 4. Invalid input
✔ 5. Modify the array
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
int input_value(int array[], const int len);
void invalid_input();
void modify_array(int array[], const int len);

int main() {
    int kLen = 5;
    int array[kLen];
    init_array(array, kLen);
    if (input_value(array, kLen)) {
        modify_array(array, kLen);
        output_array(array, kLen);
    } else {
        invalid_input();
    }
    return 0;
}

void modify_array(int array[], const int len) {
    int first = FALSE, last = FALSE;
    int min_index = 0, max_index = len - 1;
    for (int index = 0; index < len / 2 + 1; ++index) {
        first = array[min_index];
        last = array[max_index];
        array[min_index] = last;
        array[max_index] = first;
        ++min_index;
        --max_index;
    }
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

void output_array(int array[], const int len) {
    printf("The reversed values are:\n");
    for (int index = 0; index < len; ++index) {
        printf("array_n[%d] = %d\n", index, array[index]);
    }
}

void init_array(int array[], const int len) {
    for (int index = 0; index < len; ++index) {
        array[index] = 0;
    }
}

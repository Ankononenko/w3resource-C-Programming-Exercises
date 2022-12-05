// Copyright School 21 finchren 2022

/*
Write a C program to read an array of length 6 and find the smallest element and its position
Test Data:
Input the length of the array: 5 
Input the array elements:
25
35
20
14
45
Expected Output:
Smallest Value: 14
Position of the element: 3

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
int input_array_len(int* kLen);

int main() {
    int kLen = FALSE;
    if (input_array_len(&kLen)) {
        int array[kLen];
        init_array(array, kLen);
        if (input_value(array, kLen)) {
            output_array(array, kLen);
        } else {
            invalid_input();
        }
    } else {
        invalid_input();
    }

    return 0;
}

int input_array_len(int* kLen) {
    int is_valid_input = TRUE;
    char newline = '\n';
    printf("Input the length of the array: ");
    if (!scanf("%d%c", kLen, &newline) || newline != '\n' || *kLen < 0) {
        is_valid_input = FALSE;
    }
    return is_valid_input;
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
    int smallest_value = array[0], current_value = FALSE, position = FALSE;
    for (int index = 1; index < len; ++index) {
        if (array[index] < smallest_value) {
            current_value = array[index];
            smallest_value = current_value;
            position = index;
        }
    }
    printf("Smallest Value: %d\n", smallest_value);
    printf("Position of the element: %d\n", position);
}

void init_array(int array[], const int len) {
    for (int index = 0; index < len; ++index) {
        array[index] = 0;
    }
}

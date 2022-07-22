// Copyright 2022 finchren
/*
Write a C program to read a password until it is correct. For wrong password print "Incorrect password"
and for correct password print "Correct password" and quit the program. 
The correct password is 1234
Test Data :
Input the password: 1234
Expected Output:
Correct password

√ 1. Write the plan to complete the exercise
√ 2. Take the input string and store it in the one-dimensional array
√ 3. Function to compare the arrays
√ 4. Print output and greeting
√ 5. Place the function in a while loop intil strings are equal
√ 6. Test
√ 7. Cpplint test
√ 8. Add and push
*/

#include <stdio.h>
#define ARRAY_SIZE 42

enum boolean{
    FALSE,
    TRUE
};

typedef struct Data {
    char input_array[ARRAY_SIZE];
    char password[ARRAY_SIZE];
} Data;

void s21_memset(char array[],
    const char character_to_fill_with, const int array_size);
void initialize_arrays(Data* data);
void s21_strcpy(char target_array[], const char array_to_copy[],
    const int array_to_copy_size);
void set_password(Data* data, char password_array[]);
int s21_strlen(const char array[]);
void take_input(Data* data);
int s21_strcmp(Data* data);
void print_greeting();
void print_correct_password();
void print_incorrect_password();
void print_final_output(int result);

int main() {
    Data data;
    initialize_arrays(&data);
    char password[] = "1234";
    set_password(&data, password);
    int result = FALSE;
    while (!result) {
        print_greeting();
        take_input(&data);
        result = s21_strcmp(&data);
        print_final_output(result);
    }
    return 0;
}

void print_final_output(int result) {
    if (result) {
        print_correct_password();
    } else {
        print_incorrect_password();
    }
}

void print_correct_password() {
    printf("Correct password \n");
}

void print_incorrect_password() {
    printf("Incorrect password \n"
    "Please try again \n");
}

void print_greeting() {
    printf("Input the password: \n");
}

int s21_strcmp(Data* data) {
    int index = 0, password_length = 0, result = TRUE;
    password_length = s21_strlen(data->password);
    if (data->password[index] != data->input_array[index]) {
        result = FALSE;
    } else {
        ++index;
        while (result && index < password_length) {
            if (data->password[index] != data->input_array[index]) {
               result = FALSE;
            }
            ++index;
        }
    }
    return result;
}

void take_input(Data* data) {
    scanf("%42s", data->input_array);
}

int s21_strlen(const char array[]) {
    int index = 0;
    char null_terminator = '\0';
    while (array[index] != null_terminator) {
        ++index;
    }
    return index;
}

void set_password(Data* data, char password_array[]) {
    s21_strcpy(data->password, password_array, s21_strlen(password_array));
}

void s21_strcpy(char target_array[], const char array_to_copy[],
    const int array_to_copy_size) {

    for (int index = 0; index < array_to_copy_size; ++index) {
        target_array[index] = array_to_copy[index];
    }
}

void initialize_arrays(Data* data) {
    char null_terminator = '\0';
    s21_memset(data->input_array, null_terminator, ARRAY_SIZE);
    s21_memset(data->password, null_terminator, ARRAY_SIZE);
}

void s21_memset(char array[], const char character_to_fill_with,
    const int array_size) {

    for (int index = 0; index < array_size; ++index) {
        array[index] = character_to_fill_with;
    }
}

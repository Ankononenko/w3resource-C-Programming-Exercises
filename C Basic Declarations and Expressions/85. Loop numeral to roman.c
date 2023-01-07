// Copyright School 21 finchren 2023

/*
Task:
Write a C program to print a table of all the Roman numeral equivalents of the decimal numbers in the range 1 to 50
Sample Output:
Decimal  Roman
number   numeral
-------------------
1        I
2        II
3        III
4        IV
.....
98        LXXXXVIII
99        LXXXXIX
100        C

✔ 1. Write a plan to complete the exercise
✔ 2. Think of a way to iterate over the roman numbers
✔ 3. An array of roman numbers and a function to convert each of the nums into Roman
    ✔ 1. One
    ✔ 2. Five
    ✔ 3. Ten
    ✔ 4. Fifty
    ✔ 5. Hundred
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum is_true{
    FALSE,
    TRUE
};

void iterate_over_range(const int start, const int end, char array_to_print[]);
void convert_num_to_roman(const int num, char array_to_print[]);
void get_hundreds(int* temp_num, char array_to_print[], int* char_index, int* should_be_flipped);
void get_fifties(int* temp_num, char array_to_print[], int* char_index);
void get_tens(int* temp_num, char array_to_print[], int* char_index, int* should_be_flipped, const int forties);
void get_fives(int* temp_num, char array_to_print[], int* char_index, int* should_be_flipped);
void get_ones(int* temp_num, char array_to_print[], int* char_index, int* should_be_flipped);
void print_out_the_array(const int current_num, const char array_to_print[]);
void empty_the_array(char array_to_print[]);
void flip_the_array(char array_to_print[]);
int check_if_forty(const int temp_num);
void output_header_string();

int main() {
    char array_to_print[10] = {'\0'};
    int start = 1, end = 100;
    output_header_string();
    iterate_over_range(start, end, array_to_print);
    return 0;
}

void output_header_string() {
    printf("Decimal  Roman\n"
           "number   numeral\n"
           "-------------------\n");
}

void flip_the_array(char array_to_print[]) {
    int index_i = 0;
    char temp_array[10] = {'\0'};
    while (array_to_print[index_i]) {
        temp_array[index_i] = array_to_print[index_i];
        ++index_i;
    }
    --index_i;
    array_to_print[index_i] = temp_array[index_i - 1];
    array_to_print[index_i - 1] = temp_array[index_i];
}

void empty_the_array(char array_to_print[]) {
    int index = 0;
    while (array_to_print[index]) {
        array_to_print[index] = '\0';
        ++index;
    }
}

void print_out_the_array(const int current_num, const char array_to_print[]) {
    int index = 0;
    printf("%-9d", current_num);
    while (array_to_print[index]) {
        printf("%c", array_to_print[index]);
        ++index;
    }
    printf("\n");
}

void iterate_over_range(const int start, const int end, char array_to_print[]) {
    for (int current_num = start; current_num <= end; ++current_num) {
        convert_num_to_roman(current_num, array_to_print);
        print_out_the_array(current_num, array_to_print);
        empty_the_array(array_to_print);
    }
}

void convert_num_to_roman(const int num, char array_to_print[]) {
    int temp_num = num, char_index = 0, should_be_flipped = FALSE, forties = FALSE;
    forties = check_if_forty(temp_num);
    get_hundreds(&temp_num, array_to_print, &char_index, &should_be_flipped);
    get_fifties(&temp_num, array_to_print, &char_index);
    get_tens(&temp_num, array_to_print, &char_index, &should_be_flipped, forties);
    get_fives(&temp_num, array_to_print, &char_index, &should_be_flipped);
    get_ones(&temp_num, array_to_print, &char_index, &should_be_flipped);
}

void get_hundreds(int* temp_num, char array_to_print[], int* char_index, int* should_be_flipped) {
    while (*temp_num >= 90 && *temp_num <= 100) {
        array_to_print[*char_index] = 'C';
        ++*char_index;
        if (*temp_num != 100) {
            *temp_num -= 80;
            *should_be_flipped = TRUE;
        } else {
            *temp_num -= 100;
        }
        if (*temp_num < 0) {
            *temp_num *= -1;
        }
    }
}

int check_if_forty(const int temp_num) {
    return temp_num >= 40 && temp_num <= 48 ? TRUE : FALSE;
}

void get_fifties(int* temp_num, char array_to_print[], int* char_index) {
    int is_forty = FALSE;
    while (*temp_num >= 40 && *temp_num <= 89) {
        array_to_print[*char_index] = 'L';
        if (*temp_num >= 40 && *temp_num <= 49) {
            ++*char_index;
            array_to_print[*char_index] = 'X';
            is_forty = TRUE;
            flip_the_array(array_to_print);
        }
        ++*char_index;
        *temp_num -= 50;
        if (*temp_num < 0) {
            *temp_num *= -1;
        }
        if (is_forty) {
            *temp_num -= 10;
            if (*temp_num < 0) {
                *temp_num *= -1;
            }
        }
    }
}

void get_tens(int* temp_num, char array_to_print[], int* char_index, int* should_be_flipped, const int forties) {
    if (!forties) {
        while (*temp_num >= 9 && *temp_num <= 39) {
            array_to_print[*char_index] = 'X';
            if (*should_be_flipped) {
                flip_the_array(array_to_print);
                *should_be_flipped = FALSE;
            }
            ++*char_index;
            if (*temp_num == 9) {
                *should_be_flipped = TRUE;
            }
            *temp_num -= 10;
            if (*temp_num < 0) {
                *temp_num *= -1;
            }
        }
    }
}

void get_fives(int* temp_num, char array_to_print[], int* char_index, int* should_be_flipped) {
    if (*temp_num >= 4  && *temp_num <= 8) {
        while (*temp_num >= 4  && *temp_num <= 8) {
            array_to_print[*char_index] = 'V';
            if (*temp_num == 4) {
                *should_be_flipped = TRUE;
            }
            ++*char_index;
            *temp_num -= 5;
            if (*temp_num < 0) {
                *temp_num *= -1;
            }
        }
    }
}

void get_ones(int* temp_num, char array_to_print[], int* char_index, int* should_be_flipped) {
    if (*temp_num > 0 && *temp_num <= 3) {
        while (*temp_num > 0) {
            array_to_print[*char_index] = 'I';
            ++*char_index;
            --*temp_num;
        }
    }
    if (*should_be_flipped) {
        flip_the_array(array_to_print);
    }
}

// Copyright School 21 finchren 2023

/*
Task:
Write a C program to display the sizes and ranges for each of C's data types
Sample Output:
Size of C data types:

Type               Bytes

--------------------------------
char                 1
int8_t               1
unsigned char        1
uint8_t              1
short                2
int16_t              2
uint16t              2
int                  4
unsigned             4
long                 8
unsigned long        8
int32_t              4
uint32_t             4
long long            8
int64_t              8
unsigned long long   8
uint64_t             8
float                4
double               8
long double          16
_Bool                1

✔ 1. Write a plan to complete the exercise
✔ 2. Find out what are "ranges of C data types"
✔ 3. Print out the sizes
✔ 3.1 Bonus from me - output the ranges as in the text of the task but not in the sample output 
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

void print_header();
void print_char_type();
void print_int8t_type();
void print_unsigned_char_type();
void print_uint8_t_type();
void print_short_type();
void print_int16_t_type();
void print_uint16t_type();
void print_int_type();
void print_unsigned_type();
void print_long_type();
void print_unsigned_long_type();
void print_int32_t_type();
void print_uint32_t_type();
void print_long_long_type();
void print_int64_t_type();
void print_unsigned_long_long_type();
void print_uint64_t_type();
void print_float_type();
void print_double_type();
void print_long_double_type();
void print_bool_type();

int main() {
    print_header();
    print_char_type();
    print_int8t_type();
    print_unsigned_char_type();
    print_uint8_t_type();
    print_short_type();
    print_int16_t_type();
    print_uint16t_type();
    print_int_type();
    print_unsigned_type();
    print_long_type();
    print_unsigned_long_type();
    print_int32_t_type();
    print_uint32_t_type();
    print_long_long_type();
    print_int64_t_type();
    print_unsigned_long_long_type();
    print_uint64_t_type();
    print_float_type();
    print_double_type();
    print_long_double_type();
    print_bool_type();
    return 0;
}

void print_bool_type() {
    char type_name[6] = "_Bool";
    printf("%-20s%-20lld%-25d%-25d\n", type_name, sizeof(bool), 0, 1);
}

void print_long_double_type() {
    char type_name[14] = "long double";
    printf("%-20s%-20lld%-25LE%-25LE\n", type_name, sizeof(long double), LDBL_MIN, LDBL_MAX);
}

void print_double_type() {
    char type_name[9] = "double";
    printf("%-20s%-20lld%-25E%-25E\n", type_name, sizeof(double), DBL_MIN, DBL_MAX);
}

void print_float_type() {
    char type_name[6] = "float";
    printf("%-20s%-20lld%-25E%-25E\n", type_name, sizeof(float), FLT_MIN, FLT_MAX);
}

void print_uint64_t_type() {
    char type_name[9] = "uint64_t";
    printf("%-20s%-20lld%-25u%-25llu\n", type_name, sizeof(uint64_t), 0, UINT64_MAX);
}

void print_unsigned_long_long_type() {
    char type_name[19] = "unsigned long long";
    printf("%-20s%-20lld%-25u%-25llu\n", type_name, sizeof(unsigned long long), 0, ULLONG_MAX);
}

void print_int64_t_type() {
    char type_name[8] = "int64_t";
    printf("%-20s%-20lld%-25lld%-25lld\n", type_name, sizeof(int64_t), INT64_MIN, INT64_MAX);
}

void print_long_long_type() {
    char type_name[10] = "long long";
    printf("%-20s%-20lld%-25lld%-25lld\n", type_name, sizeof(long long), LLONG_MIN, LLONG_MAX);
}

void print_uint32_t_type() {
    char type_name[9] = "uint32_t";
    printf("%-20s%-20lld%-25u%-25u\n", type_name, sizeof(uint32_t), 0, UINT32_MAX);
}

void print_int32_t_type() {
    char type_name[8] = "int32_t";
    printf("%-20s%-20lld%-25d%-25d\n", type_name, sizeof(int32_t), INT32_MIN, INT32_MAX);
}

void print_unsigned_long_type() {
    char type_name[14] = "unsigned long";
    printf("%-20s%-20lld%-25u%-25lu\n", type_name, sizeof(unsigned long), 0, ULONG_MAX);
}

void print_long_type() {
    char type_name[5] = "long";
    printf("%-20s%-20lld%-25ld%-25ld\n", type_name, sizeof(long), LONG_MIN, LONG_MAX);
}

void print_unsigned_type() {
    char type_name[9] = "unsigned";
    printf("%-20s%-20lld%-25u%-25u\n", type_name, sizeof(unsigned), 0, UINT_MAX);
}

void print_int_type() {
    char type_name[4] = "int";
    printf("%-20s%-20lld%-25d%-25d\n", type_name, sizeof(int), INT_MIN, INT_MAX);
}

void print_uint16t_type() {
    char type_name[8] = "uint16t";
    printf("%-20s%-20lld%-25d%-25d\n", type_name, sizeof(uint16_t), 0, UINT16_MAX);
}

void print_int16_t_type() {
    char type_name[8] = "int16_t";
    printf("%-20s%-20lld%-25d%-25d\n", type_name, sizeof(int16_t), INT16_MIN, INT16_MAX);
}

void print_short_type() {
    char type_name[6] = "short";
    printf("%-20s%-20lld%-25d%-25d\n", type_name, sizeof(short), SHRT_MIN, SHRT_MAX);
}

void print_uint8_t_type() {
    char type_name[8] = "uint8_t";
    printf("%-20s%-20lld%-25d%-25d\n", type_name, sizeof(uint8_t), 0, UINT8_MAX);
}

void print_unsigned_char_type() {
    char type_name[14] = "unsigned char";
    printf("%-20s%-20lld%-25d%-25d\n", type_name, sizeof(unsigned char), WCHAR_MIN, UCHAR_MAX);
}

void print_int8t_type() {
    char type_name[7] = "int8_t";
    printf("%-20s%-20lld%-25d%-25d\n", type_name, sizeof(int8_t), INT8_MIN, INT8_MAX);
}

void print_char_type() {
    char type_name[5] = "char";
    printf("%-20s%-20lld%-25d%-25d\n", type_name, sizeof(char), CHAR_MIN, CHAR_MAX);
}

void print_header() {
    char type[5] = "Type";
    char bytes[6] = "Bytes";
    char min_range[10] = "Min range";
    char max_range[10] = "Max range";
    printf("%-19s%-19s%-25s%-25s\n"
           "\n"
           "---------------------------------"
           "---------------------------------"
           "---------------------\n",
           type, bytes, min_range, max_range);
}

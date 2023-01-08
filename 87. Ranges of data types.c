// Copyright School 21 finchren 2023

/*
Task:
Write a C program to display the sizes and ranges for each of C's data types
Sample Output:
Ranges for integer data types in C

------------------------------------------------------------
int8_t                    -128                   127
int16_t                 -32768                 32767
int32_t            -2147483648            2147483647
int64_t   -9223372036854775808   9223372036854775807
uint8_t                      0                   255
uint16_t                     0                 65535
uint32_t                     0            4294967295
uint64_t                     0  18446744073709551615

============================================================

Ranges for real number data types in C

------------------------------------------------------------
float          1.175494e-38    3.402823e+38
double        2.225074e-308   1.797693e+308
long double  3.362103e-4932  1.189731e+4932

✔ 1. Write a plan to complete the exercise
✔ 2. Print out the integer data types
✔ 3. Print out the real number data types
✔ 3.1 Find out how to output the number in scientific notation
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdint.h>
#include <float.h>

void print_out_header_int_data_types();
void print_int8t_type();
void print_int16_t_type();
void print_int32_t_type();
void print_int64_t_type();
void print_uint8_t_type();
void print_uint16t_type();
void print_uint32_t_type();
void print_uint64_t_type();
void print_out_header_real_num_data_types();
void print_float_type();
void print_double_type();
void print_long_double_type();

int main() {
    print_out_header_int_data_types();
    print_int8t_type();
    print_int16_t_type();
    print_int32_t_type();
    print_int64_t_type();
    print_uint8_t_type();
    print_uint16t_type();
    print_uint32_t_type();
    print_uint64_t_type();
    print_out_header_real_num_data_types();
    print_float_type();
    print_double_type();
    print_long_double_type();
    return 0;
}

void print_long_double_type() {
    char type_name[14] = "long double";
    printf("%-26s%-23LE%-23LE\n", type_name, LDBL_MIN, LDBL_MAX);
}

void print_double_type() {
    char type_name[9] = "double";
    printf("%-26s%-23E%-23E\n", type_name, DBL_MIN, DBL_MAX);
}

void print_float_type() {
    char type_name[6] = "float";
    printf("%-26s%-23E%-23E\n", type_name, FLT_MIN, FLT_MAX);
}

void print_out_header_real_num_data_types() {
    printf("\n"
           "============================================================\n"
           "\n"
           "Ranges for real number data types in C\n"
           "\n"
           "------------------------------------------------------------\n");
}

void print_uint64_t_type() {
    char type_name[9] = "uint64_t";
    printf("%-26s%-23u%-23llu\n", type_name, 0, UINT64_MAX);
}

void print_uint32_t_type() {
    char type_name[9] = "uint32_t";
    printf("%-26s%-23u%-23u\n", type_name, 0, UINT32_MAX);
}

void print_uint16t_type() {
    char type_name[9] = "uint16_t";
    printf("%-26s%-23d%-23d\n", type_name, 0, UINT16_MAX);
}

void print_uint8_t_type() {
    char type_name[8] = "uint8_t";
    printf("%-26s%-23d%-23d\n", type_name, 0, UINT8_MAX);
}

void print_int64_t_type() {
    char type_name[8] = "int64_t";
    printf("%-26s%-23lld%-23lld\n", type_name, INT64_MIN, INT64_MAX);
}

void print_int32_t_type() {
    char type_name[8] = "int32_t";
    printf("%-26s%-23d%-23d\n", type_name, INT32_MIN, INT32_MAX);
}

void print_int16_t_type() {
    char type_name[8] = "int16_t";
    printf("%-26s%-23d%-23d\n", type_name, INT16_MIN, INT16_MAX);
}

void print_int8t_type() {
    char type_name[7] = "int8_t";
    printf("%-26s%-23d%-23d\n", type_name, INT8_MIN, INT8_MAX);
}

void print_out_header_int_data_types() {
    printf("Ranges for integer data types in C\n"
           "\n"
           "------------------------------------------------------------\n");
}

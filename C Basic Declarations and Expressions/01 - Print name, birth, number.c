// Copyright 2022 finchren
/*
Write a C program to print your name, date of birth. and mobile number
Expected Output:

Name   : Alexandra Abramov  
DOB    : July 14, 1975  
Mobile : 99-9999999999
*/

#include <stdio.h>

int main() {
    char name[] = "Anton Kononenko";
    char date_of_birth[] = "May 10th, 1991";
    char mobile_number[] = "+7 950 032 26 44";
    printf("Name: %s\nDate of birth: %s\nMobile number: %s",
    name, date_of_birth, mobile_number);
    return 0;
}

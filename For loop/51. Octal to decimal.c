// Copyright 2022 finchren
/*
Write a program in C to convert an octal number to a decimal without using an array
Test Data :
Input an octal number (using digit 0 - 7) :745
Expected Output :
The Octal Number : 745
The equivalent Decimal Number : 485
*/

#include <stdio.h>

// Enum test
enum State {WORKING = 0, FAILED, FREEZED};
enum State currState = 2;
  
enum State FindState() {
    return currState;
}
  
int main() {
   (FindState() == WORKING)? printf("WORKING"): printf("NOT WORKING");
   return 0;
}

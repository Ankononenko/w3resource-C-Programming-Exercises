// Copyright School 21 finchren 2023

/*
Task:
Write a C program to print the corresponding Fahrenheit to Celsius and Celsius
to Fahrenheit Both cases initial tempratue = 00, maximum temperature = 1500 and
step 100 Sample Output: Fahrenheit to Celsius
---------------------
Fahrenheit  Celsius
   0.0      -17.8
  10.0      -12.2
  20.0       -6.7
...
 130.0       54.4
 140.0       60.0
 150.0       65.6


Celsius to Fahrenheit
---------------------
Celsius   Fahrenheit
   0.0       32.0
  10.0       50.0
  20.0       68.0
 ...

 130.0      266.0
 140.0      284.0
 150.0      302.0


✔ 1. Write a plan to complete the exercise
✔ 2. Convert Fahrenheit to Celsius
✔ 3. Convert Celsius to Fahrenheit
✔ 4. Output the result - iterate over the ranges
✔ 5. Test
✔ 6. Google style check - clang-format
✔ 7. Add and push
*/

#include <stdio.h>

void fahrenheit_to_celsius(const double fahrenheit, double *celsius);
void celsius_to_fahrenheit(const double celsius, double *fahrenheit);
void output_fahrenheit_to_celsius();
void output_celsius_to_fahrenheit();

int main() {
  output_fahrenheit_to_celsius();
  output_celsius_to_fahrenheit();
}

void output_celsius_to_fahrenheit() {
  printf("Celsius to Fahrenheit\n"
         "---------------------\n"
         "Celsius   Fahrenheit\n");
  for (int index = 0; index <= 150; index += 10) {
    double celsius = (double)index;
    double fahrenheit = 0.0;
    celsius_to_fahrenheit(celsius, &fahrenheit);
    printf("%6.1lf %10.1lf\n", celsius, fahrenheit);
  }
}

void output_fahrenheit_to_celsius() {
  printf("Fahrenheit to Celsius\n"
         "---------------------\n"
         "Fahrenheit  Celsius\n");
  for (int index = 0; index <= 150; index += 10) {
    double fahrenheit = (double)index;
    double celsius = 0.0;
    fahrenheit_to_celsius(fahrenheit, &celsius);
    printf("%6.1lf %10.1lf\n", fahrenheit, celsius);
  }
  printf("\n");
}

// To convert temperatures in degrees Celsius to Fahrenheit, multiply by 1.8
// (or 9/5) and add 32.
void celsius_to_fahrenheit(const double celsius, double *fahrenheit) {
  *fahrenheit = celsius * 1.8 + 32;
}

// To convert temperatures in degrees Fahrenheit to Celsius, subtract 32 and
// divide by 1.8
void fahrenheit_to_celsius(const double fahrenheit, double *celsius) {
  *celsius = (fahrenheit - 32) / 1.8;
}

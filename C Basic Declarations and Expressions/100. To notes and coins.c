// Copyright School 21 finchren 2023

/*
Write a C program to convert a currency value (floating point with two decimal
places) to possible number of notes and coins Sample Output: Input the currency
value (floating point with two decimal places): 10357.75

Currency Notes:
100 number of Note(s): 103
50 number of Note(s): 1
5 number of Note(s): 1
2 number of Note(s): 1

Currency Coins:
.50 number of Coin(s): 1
.25 number of Coin(s): 1

✔ 1. Write a plan to complete the exercise
✔ 2. Input and incorrect input
✔ 3. Function to convert the value to notes and coins
✔ 3.5 Output the result
✔ 4. Test
✔ 5. Google style check - clang-format
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

enum is_valid { FALSE, TRUE };

int input_value(double *value, const double eps);
void invalid_input();
void convert_to_bills(double *temp_value, int *hundreds, int *fifties,
                      int *twenties, int *tens, int *fives, int *twos,
                      int *ones);
void convert_to_coins(const double eps, double *temp_value, int *fifty_cent,
                      int *twenty_five_cent, int *ten_cent, int *five_cent,
                      int *one_cent);
void output_result(const int hundreds, const int fifties, const int twenties,
                   const int tens, const int fives, const int twos,
                   const int ones, const int fifty_cent,
                   const int twenty_five_cent, const int ten_cent,
                   const int five_cent, const int one_cent);
void output_bills(const int hundreds, const int fifties, const int twenties,
                  const int tens, const int fives, const int twos,
                  const int ones);
void output_coins(const int fifty_cent, const int twenty_five_cent,
                  const int ten_cent, const int five_cent, const int one_cent);

int main(void) {
  double const eps = 1E-9;
  double value = 0.0;
  if (input_value(&value, eps)) {
    int hundreds = 0, fifties = 0, twenties = 0, tens = 0, fives = 0, twos = 0,
        ones = 0;
    double temp_value = value;
    convert_to_bills(&temp_value, &hundreds, &fifties, &twenties, &tens, &fives,
                     &twos, &ones);
    int fifty_cent = 0, twenty_five_cent = 0, ten_cent = 0, five_cent = 0,
        one_cent = 0;
    convert_to_coins(eps, &temp_value, &fifty_cent, &twenty_five_cent,
                     &ten_cent, &five_cent, &one_cent);
    output_result(hundreds, fifties, twenties, tens, fives, twos, ones,
                  fifty_cent, twenty_five_cent, ten_cent, five_cent, one_cent);
  } else {
    invalid_input();
  }
  return EXIT_SUCCESS;
}

void output_bills(const int hundreds, const int fifties, const int twenties,
                  const int tens, const int fives, const int twos,
                  const int ones) {
  printf("Currency Notes:\n");
  if (hundreds) {
    printf("100 number of Note(s): %d\n", hundreds);
  }
  if (fifties) {
    printf("50 number of Note(s): %d\n", fifties);
  }
  if (twenties) {
    printf("25 number of Note(s): %d\n", twenties);
  }
  if (tens) {
    printf("10 number of Note(s): %d\n", tens);
  }
  if (fives) {
    printf("5 number of Note(s): %d\n", fives);
  }
  if (twos) {
    printf("2 number of Note(s): %d\n", twos);
  }
  if (ones) {
    printf("1 number of Note(s): %d\n", ones);
  }
}

void output_coins(const int fifty_cent, const int twenty_five_cent,
                  const int ten_cent, const int five_cent, const int one_cent) {
  printf("Currency Coins:\n");
  if (fifty_cent) {
    printf(".50 number of Coin(s): %d\n", fifty_cent);
  }
  if (twenty_five_cent) {
    printf(".25 number of Coin(s): %d\n", twenty_five_cent);
  }
  if (ten_cent) {
    printf(".10 number of Coin(s): %d\n", ten_cent);
  }
  if (five_cent) {
    printf(".05 number of Coin(s): %d\n", five_cent);
  }
  if (one_cent) {
    printf(".01 number of Coin(s): %d\n", one_cent);
  }
}

void output_result(const int hundreds, const int fifties, const int twenties,
                   const int tens, const int fives, const int twos,
                   const int ones, const int fifty_cent,
                   const int twenty_five_cent, const int ten_cent,
                   const int five_cent, const int one_cent) {
  output_bills(hundreds, fifties, twenties, tens, fives, twos, ones);
  output_coins(fifty_cent, twenty_five_cent, ten_cent, five_cent, one_cent);
}

void convert_to_coins(const double eps, double *temp_value, int *fifty_cent,
                      int *twenty_five_cent, int *ten_cent, int *five_cent,
                      int *one_cent) {
  while (*temp_value >= 0.50) {
    *temp_value -= 0.50;
    ++*fifty_cent;
  }
  while (*temp_value >= 0.25) {
    *temp_value -= 0.25;
    ++*twenty_five_cent;
  }
  while (*temp_value >= 0.10) {
    *temp_value -= 0.10;
    ++*ten_cent;
  }
  while (*temp_value >= 0.05) {
    *temp_value -= 0.05;
    ++*five_cent;
  }
  while (*temp_value >= eps) {
    *temp_value -= 0.01;
    ++*one_cent;
  }
}

void convert_to_bills(double *temp_value, int *hundreds, int *fifties,
                      int *twenties, int *tens, int *fives, int *twos,
                      int *ones) {
  while (*temp_value >= 100.0) {
    *temp_value -= 100.0;
    ++*hundreds;
  }
  while (*temp_value >= 50.0) {
    *temp_value -= 50.0;
    ++*fifties;
  }
  while (*temp_value >= 20.0) {
    *temp_value -= 20.0;
    ++*twenties;
  }
  while (*temp_value >= 10.0) {
    *temp_value -= 10.0;
    ++*tens;
  }
  while (*temp_value >= 5.0) {
    *temp_value -= 5.0;
    ++*fives;
  }
  while (*temp_value >= 2.0) {
    *temp_value -= 2.0;
    ++*twos;
  }
  while (*temp_value >= 1.0) {
    *temp_value -= 1.0;
    ++*ones;
  }
}

void invalid_input() {
  printf("The value should be a positive number\n"
         "At the end of the line a newline is expected\n");
}

int input_value(double *value, const double eps) {
  int is_valid_input = FALSE;
  char newline = '\0';
  printf(
      "Input the currency value (floating point with two decimal places):\n");
  if (scanf("%lf%c", value, &newline) && newline == '\n' && *value > eps) {
    is_valid_input = TRUE;
  }
  return is_valid_input;
}

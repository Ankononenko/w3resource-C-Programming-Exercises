// Task - output first 100 roman numbers
// Convert decimal to roman in a loop

#include <stdio.h>
#include <stdlib.h>

void iterate_over_range(const unsigned char start, const unsigned char end);
void convert_to_roman(const unsigned char num);
void roman_hundred(unsigned char *temp_num);
void roman_fifty(unsigned char *temp_num);
void roman_ten(unsigned char *temp_num);
void roman_five(unsigned char *temp_num);
void roman_one(unsigned char *temp_num);
void print_newline();
void print_decimal(const unsigned char num);
void print_header();

int main(void) {
  const unsigned char start = 1, end = 100;
  print_header();
  iterate_over_range(start, end);
  return EXIT_SUCCESS;
}

void print_header() {
  printf("Decimal  Roman\n"
         "numbers  numerals\n"
         "-------------------\n");
}

// I = 1, V = 5, X = 10, L = 50, C = 100
void convert_to_roman(const unsigned char num) {
  unsigned char temp_num = num;
  while (temp_num) {
    roman_hundred(&temp_num);
    roman_fifty(&temp_num);
    roman_ten(&temp_num);
    roman_five(&temp_num);
    roman_one(&temp_num);
  }
}

void roman_one(unsigned char *temp_num) {
while (*temp_num) {
    printf("I");
    --*temp_num;
  }
}

void roman_five(unsigned char *temp_num) {
  if (*temp_num >= 5) {
    printf("V");
    *temp_num -= 5;
  }
  if (*temp_num == 4) {
    printf("IV");
    *temp_num -= 4;
  }
}

void roman_ten(unsigned char *temp_num) {
  while (*temp_num >= 10) {
    printf("X");
    *temp_num -= 10;
  }
  if (*temp_num == 9) {
    printf("IX");
    *temp_num -= 9;
  }
}

void roman_fifty(unsigned char *temp_num) {
  if (*temp_num >= 50) {
    printf("L");
    *temp_num -= 50;
  }
  if (*temp_num >= 40) {
    printf("XL");
    *temp_num -= 40;
  }
}

void roman_hundred(unsigned char *temp_num) {
  if (*temp_num >= 100) {
    printf("C");
    *temp_num -= 100;
  }
  if (*temp_num >= 90) {
    printf("XC");
    *temp_num -= 90;
  }
}

void print_newline() { printf("\n"); }

void print_decimal(const unsigned char num) { printf("  %-9d", num); }

void iterate_over_range(const unsigned char start, const unsigned char end) {
  for (unsigned char index = start; index <= end; ++index) {
    print_decimal(index);
    convert_to_roman(index);
    print_newline();
  }
}

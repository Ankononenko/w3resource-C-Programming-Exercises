// Copyright School 21 finchren 2023

/*
Task:
Write a C program to check if a given number is nearly prime or not
Nearly prime number is a positive integer which is equal to product of two prime
numbers. 
Sample Output: 55
55 is a Nearly prime number.

✔ 1. Write a plan to complete the exercise
✔ 2. Input and invalid input
✔ 3. Check if a num is prime function
✔ 4. Check if the product if prime - iterate down from the input num
✔ 5. Test
✔ 6. Google style check - clang-format
✔ 7. Add and push
*/

#include <stdio.h>

enum is_valid { FALSE, TRUE };

int input_num(int *num);
void invalid_input();
int check_if_num_is_prime(const int num);
int check_if_num_is_nearly_prime(const int num);
void is_nearly_prime_output(const int num);
void is_not_nearly_prime_output(const int num);

int main() {
  int num = 0;
  if (input_num(&num)) {
    if (check_if_num_is_nearly_prime(num)) {
      is_nearly_prime_output(num);
    } else {
      is_not_nearly_prime_output(num);
    }
  } else {
    invalid_input();
  }
  return 0;
}

void is_not_nearly_prime_output(const int num) {
  printf("%d is not a Nearly prime number.\n", num);
}

void is_nearly_prime_output(const int num) {
  printf("%d is a Nearly prime number.\n", num);
}

int check_if_num_is_nearly_prime(const int num) {
  int is_nearly_prime = FALSE, is_first_prime = FALSE, is_second_prime = FALSE,
      first = 2, second = 0;
  while (first <= num && !is_nearly_prime) {
    if (!(num % first)) {
      is_first_prime = check_if_num_is_prime(first);
      if (is_first_prime) {
        second = num / first;
        is_second_prime = check_if_num_is_prime(second);
      }
    }
    if (is_first_prime && is_second_prime) {
      is_nearly_prime = TRUE;
    }
    ++first;
  }
  return is_nearly_prime;
}

int check_if_num_is_prime(const int num) {
  int is_prime = TRUE, index = 2;
  while (is_prime && index < num) {
    if (!(num % index)) {
      is_prime = FALSE;
    }
    ++index;
  }
  if (num <= 1) {
    is_prime = FALSE;
  }
  return is_prime;
}

void invalid_input() {
  printf("The script takes only a single number\n"
         "At the end of the line a newline is expected\n");
}

int input_num(int *num) {
  int is_valid_input = FALSE;
  char newline = '\0';
  if (scanf("%d%c", num, &newline) && newline == '\n') {
    is_valid_input = TRUE;
  }
  return is_valid_input;
}

// Copyright School 21 finchren 2023

/*
Task:
Write a C program that takes two integers and test
whether they are multiplies or not
In science, a multiple is the product of any quantity and an integer.
In other words, for the quantities a and b, we say that b is a multiple of a if
b = na for some integer n, which is called the multiplier. If a is not zero,
this is equivalent to saying that b/a is an integer.

Sample Output:
Input two integers:
3
9
Multiplies

✔ 1. Write a plan to complete the exercise
✔ 2. Input and incorrect input
✔ 3. Function to check if multiple and output the result
✔ 4. Test
✔ 5. Google style check - clang-format
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

enum is_valid { FALSE, TRUE };

int input_nums(int *num);
void invalid_input();
void print_greeting();
int is_multiple(const int first, const int second);
void are_multiples();
void are_not_multiples();

int main(void) {
  int first = 0;
  print_greeting();
  if (input_nums(&first)) {
    int second = 0;
    if (input_nums(&second)) {
      if (is_multiple(first, second)) {
        are_multiples();
      } else {
        are_not_multiples();
      }
    } else {
      invalid_input();
    }
  } else {
    invalid_input();
  }
  return EXIT_SUCCESS;
}

void are_not_multiples() { printf("Not multiplies\n"); }

void are_multiples() { printf("Multiplies\n"); }

int is_multiple(const int first, const int second) {
  return !(first % second) || !(second % first) ? TRUE : FALSE;
}

void invalid_input() {
  printf("The script takes only one number at a time\n"
         "At the end of the line a newline is expected\n"
         "Input nums cannot be zeros\n");
}

void print_greeting() { printf("Input two integers:\n"); }

int input_nums(int *num) {
  int is_valid_input = FALSE;
  char newline = '\0';
  if (scanf("%d%c", num, &newline) && newline == '\n' && *num) {
    is_valid_input = TRUE;
  }
  return is_valid_input;
}

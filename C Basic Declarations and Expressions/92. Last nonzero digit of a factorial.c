// Copyright School 21 finchren 2023

/*
Task:
Write a C program to find the last non-zero digit of the factorial of a given
positive integer For example for 5!, the output will be "2" because 5! = 120,
and 2 is the last nonzero digit of 120 Sample Output: Input a positive number:
The last non-zero digit of the said factorial:
0

✔ 1. Write a plan to complete the exercise
✔ 2. Input and invalid input
✔ 3. Factorial fucntion
✔ 3.5 Function to get last nonzero digit of the factorial output
✔ 4. Test
✔ 5. Google style check - clang-format
✔ 6. Add and push
*/

#include <stdio.h>

enum is_valid { FALSE, TRUE };

int input_num(int *num);
void invalid_input();
int s21_factorial(const int num);
int get_last_nonzero(const int factorial);
void output_result(const int last_nonzero);

int main() {
  int num = 0;
  if (input_num(&num)) {
    int factorial = s21_factorial(num);
    int last_nonzero = get_last_nonzero(factorial);
    output_result(last_nonzero);
  } else {
    invalid_input();
  }
  return 0;
}

void output_result(const int last_nonzero) {
  printf("The last non-zero digit of the said factorial: %d\n", last_nonzero);
}

int get_last_nonzero(const int factorial) {
  int temp_factorial = factorial, remainder = temp_factorial % 10;
  while (!remainder) {
    temp_factorial /= 10;
    remainder = temp_factorial % 10;
  }
  return remainder;
}

int s21_factorial(const int num) {
  int factorial = num;
  for (int index = num - 1; index > 1; --index) {
    factorial *= index;
  }
  return factorial;
}

void invalid_input() {
  printf("The script takes only a positive number\n"
         "At the end of the input only a newline is accepted\n");
}

int input_num(int *num) {
  int is_valid_input = FALSE;
  char newline = '\0';
  printf("Input a positive number: ");
  if (scanf("%d%c", num, &newline) && *num > 0 && newline == '\n') {
    is_valid_input = TRUE;
  }
  return is_valid_input;
}

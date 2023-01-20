// Copyright School 21 finchren 2023

/*
Task:
Write a C program that takes some integer values from the user
and print a histogram.
Sample Output:
Input number of histogram bar (Maximum 10):
4
Input the values between 0 and 10 (separated by a newline):
9
7
4
3

Histogram:
#########
#######
####
###

✔ 1. Write a plan to complete the exercise
✔ 2. Input and incorrect input
✔ 3. Write the input to an array of ints and output the result
✔ 4. Test
✔ 5. Google style check - clang-format
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_num_of_elements(int *num_elements);
void invalid_input_num_elements();
int input_the_elements(const int num_elements, int array_of_elements[]);
void invalid_input_elements();
void output_hashes(const int num_elements, const int array_of_elements[]);

enum s21_bool { FALSE, TRUE };

int main(void) {
  int num_elements = 0;
  if (input_num_of_elements(&num_elements)) {
    const int kArraySize = num_elements - 1;
    int array_of_elements[kArraySize];
    memset(array_of_elements, 0, kArraySize * sizeof(int));
    if (input_the_elements(num_elements, array_of_elements)) {
      output_hashes(num_elements, array_of_elements);
    } else {
      invalid_input_elements();
    }

  } else {
    invalid_input_num_elements();
  }
  return EXIT_SUCCESS;
}

void output_hashes(const int num_elements, const int array_of_elements[]) {
  printf("Histogram:\n");
  for (int e_index = 0; e_index < num_elements; ++e_index) {
    for (int n_hashes = array_of_elements[e_index]; n_hashes > 0; --n_hashes) {
      printf("#");
    }
    printf("\n");
  }
}

void invalid_input_elements() {
  printf("Each element should be in range from 0 to 10\n"
         "At the end of the line a newline is expected\n"
         "Please try agagin\n");
}

int input_the_elements(const int num_elements, int array_of_elements[]) {
  int is_valid_input = TRUE, index = 0;
  char newline = '\0';
  printf("Input the values between 0 and 10 (separated by a newline):\n");
  while (is_valid_input && index < num_elements) {
    if ((!scanf("%d%c", &array_of_elements[index], &newline)) ||
        newline != '\n' ||
        (array_of_elements[index] > 10 || array_of_elements[index] < 0)) {
      is_valid_input = FALSE;
    }
    newline = '\0';
    ++index;
  }
  return is_valid_input;
}

void invalid_input_num_elements() {
  printf("Number of elements can range from 0 to 10\n"
         "At the end of the line a newline is expected\n"
         "Please try agagin\n");
}

int input_num_of_elements(int *num_elements) {
  int is_valid_input = FALSE;
  char newline = '\0';
  printf("Input number of histogram bar (Maximum 10):\n");
  if (scanf("%d%c", num_elements, &newline) && newline == '\n' &&
      *num_elements >= 0 && *num_elements <= 10) {
    is_valid_input = TRUE;
  }
  return is_valid_input;
}

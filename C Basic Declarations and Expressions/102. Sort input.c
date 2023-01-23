// Copyright School 21 finchren 2023

/*
Task:
Write a C program that reads three integers and sorts the numbers
in ascending order. Print the original numbers and sorted numbers.
Sample Output:
Input 3 integers: 17
-5
25

---------------------------
Original numbers: 17, -5, 25
Sorted numbers: -5, 17, 25

✔ 1. Write a plan to complete the exercise
✔ 2. Input and incorrect input
✔ 3. Output ordinal
✔ 3.5 Output sorted
✔ 4. Test
✔ 5. Google style check - clang-format
6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum is_valid { FALSE, TRUE };

int input_nums(int nums[]);
void invalid_input();
void output_ordinal(const int kArraySize, const int nums[]);
void output_sorted(const int kArraySize, const int nums[]);

int main(void) {
  int kArraySize = 3;
  int nums[kArraySize];
  memset(nums, 0, kArraySize * sizeof(int));
  if (input_nums(nums)) {
    output_ordinal(kArraySize, nums);
    output_sorted(kArraySize, nums);
  } else {
    invalid_input();
  }
  return EXIT_SUCCESS;
}

void output_sorted(const int kArraySize, const int nums[]) {
  int min = nums[0];
  for (int index = 1; index < kArraySize; ++index) {
    if (nums[index] < min) {
      min = nums[index];
    }
  }
  int max = nums[0];
  for (int index = 1; index < kArraySize; ++index) {
    if (nums[index] > max) {
      max = nums[index];
    }
  }
  int average = nums[0];
  for (int index = 1; index < kArraySize; ++index) {
    if (nums[index] < max && nums[index] > min) {
      average = nums[index];
    }
  }
  printf("Sorted numbers: %d %d %d\n", min, average, max);
}

void output_ordinal(const int kArraySize, const int nums[]) {
  printf("---------------------------\n"
         "Original numbers: ");
  for (int index = 0; index < kArraySize; ++index) {
    printf("%d", nums[index]);
    if (index != kArraySize - 1) {
      printf(" ");
    }
  }
  printf("\n");
}

void invalid_input() {
  printf("The script takes only one number at a time\n"
         "At the end of the line a newline is expected\n");
}

int input_nums(int nums[]) {
  int is_valid_input = TRUE, index = 0;
  char newline = '\0';
  printf("Input 3 integers: \n");
  while (is_valid_input && index < 3) {
    if (scanf("%d%c", &nums[index], &newline) && newline == '\n') {
      is_valid_input = TRUE;
      ++index;
    } else {
      is_valid_input = FALSE;
    }
  }
  return is_valid_input;
}

// Copyright School 21 finchren 2023

/*
Task:
Write a C program to replace more than one blanks
with a single blank in a input string
Sample Output:
Input a string. Several blanks in a row
are going to get replaced with a single one:
The quick    brown fox jumps over             the    lazy    dog
^Z

The quick brown fox jumps over the lazy dog

✔ 1. Write a plan to complete the exercise
✔ 2. Function to replace the blanks
✔ 3. Output the result
✔ 4. Test
✔ 5. Google style check - clang-format
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

void replace_blanks_with_one(char current_char);
void output_greeting();

int main(void) {
  output_greeting();
  char current_char = '\0';
  replace_blanks_with_one(current_char);
  return EXIT_SUCCESS;
}

void replace_blanks_with_one(char current_char) {
  while (current_char != EOF) {
    current_char = getchar();
    while (current_char == ' ') {
      current_char = getchar();
      if (current_char != ' ') {
        printf(" ");
      }
    }
    printf("%c", current_char);
  }
}

void output_greeting() {
  printf(
      "Input a string."
      "Several blanks in a row are going to get replaced with a single one:\n"
      "Enter 'ctrl + z' to end the script on Windows"
      "And 'ctrl + d' to end the script on Unix\n");
}

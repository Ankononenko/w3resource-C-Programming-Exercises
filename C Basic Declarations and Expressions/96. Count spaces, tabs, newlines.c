// Copyright School 21 finchren 2023

/*
Task:
Write a C program to count blanks, tabs, and newlines in an input text
Sample Output:
Number of blanks, tabs, and newlines:
Input few words/tab/newlines
The quick
brown fox jumps
over the lazy dog
^Z
blank=7,tab=2,newline=3

✔ 1. Write a plan to complete the exercise
✔ 2. Take the input until EOF (ctrl + z on Windows, ctrl + d in Unix)
✔ 3. Count blanks, tabs, newlines
✔ 4. Output the result
✔ 5. Test
✔ 6. Google style check - clang-format
✔ 7. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

void output_greeting();
void count_symbols(int *blanks, int *tabs, int *newlines);
void output_result(const int blanks, const int tabs, const int newlines);

int main(void) {
  int blanks = 0, tabs = 0, newlines = 0;
  output_greeting();
  count_symbols(&blanks, &tabs, &newlines);
  output_result(blanks, tabs, newlines);
  return EXIT_SUCCESS;
}

void output_result(const int blanks, const int tabs, const int newlines) {
  printf("Number of blanks = %d, tabs = %d, newlines = %d\n", blanks, tabs,
         newlines);
}

void output_greeting() {
  printf("Number of blanks, tabs, and newlines:\n"
         "Input few words/tab/newlines.\n"
         "Enter 'ctrl + z' to end the script on Windows"
         "And 'ctrl + d' to end the script on Unix\n");
}

void count_symbols(int *blanks, int *tabs, int *newlines) {
  char c = '\0';
  while (c != EOF) {
    c = getchar();
    if (c == ' ') {
      ++*blanks;
    } else if (c == ' ') {
      ++*tabs;
    } else if (c == '\n') {
      ++*newlines;
    }
  }
}

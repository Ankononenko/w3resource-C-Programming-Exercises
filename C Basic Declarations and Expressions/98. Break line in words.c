// Copyright School 21 finchren 2023

/*
Task:
Write a C program which accepts some text from the user and
prints each word of that text in separate line.
Sample Output:
Input some text:
The quick brown fox jumps over the lazy dog
The
quick
brown
fox
jumps
over
the
lazy
dog

✔ 1. Write a plan to complete the exercise
✔ 2. Function to iterate over the input
✔ 2.5 Write to a temp array until space and output the result
✔ 3. Output the result
✔ 4. Test
✔ 5. Google style check - clang-format
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

void output_greeting();
void iterate_over_input();
void output_word(char temp_array[]);
int check_if_char_is_letter(const char character);

enum s21_bool { FALSE, TRUE };

int main(void) {
  output_greeting();
  iterate_over_input();
  return EXIT_SUCCESS;
}

int check_if_char_is_letter(const char character) {
  int is_letter = FALSE;
  if ((character >= 65 && character <= 90) ||
      (character >= 97 && character <= 122)) {
    is_letter = TRUE;
  }
  return is_letter;
}

void iterate_over_input() {
  char newline = '\n', current_char = '\0';
  int index = 0;
  while (current_char != newline && current_char != EOF) {
    char *temp_array;
    current_char = getchar();
    temp_array = (char *)malloc(sizeof(char));
    if (temp_array == NULL) {
      printf("Memory cannot be allocated\n");
      return;
    }
    while (current_char != ' ' && current_char != newline) {
      if (check_if_char_is_letter(current_char)) {
        temp_array[index] = current_char;
        ++index;
        temp_array = (char *)realloc(temp_array, (index + 1) * sizeof(char));
      }
      current_char = getchar();
    }
    if ((current_char == ' ' || current_char == newline) && index) {
      temp_array[index] = '\0';
      output_word(temp_array);
      index = 0;
      free(temp_array);
    }
  }
}

void output_word(char temp_array[]) { printf("%s\n", temp_array); }

void output_greeting() {
  printf("Input some text:\n"
         "A newline marks the end of the entered text\n");
}

// Copyright School 21 finchren 2023

/*
Task:
Write a C program to count characters, words, lines input string
Sample Output:
Input a string and get number of charcters, words and lines:
The quick brown fox jumps over the lazy dog
^Z

Number of Characters = 44
Number of words = 9
Number of lines = 1

✔ 1. Write a plan to complete the exercise
✔ 2. Function to iterate over the input
✔ 2.5 Count chars, words, lines
✔ 3. Output the result
✔ 4. Test
✔ 5. Google style check - clang-format
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

enum s21_bool { FALSE, TRUE };

void iterate_over_input(int *num_chars, int *num_words, int *num_lines);
void output_greeting();
void count_chars(int *num_chars);
void count_words(const char current_char, const char next_char, int *num_words);
int check_if_char_is_letter(const char character);
void count_lines(const char current_char, int *num_lines);
void output_result(const int num_chars, const int num_words,
                   const int num_lines);

int main(void) {
  output_greeting();
  int num_chars = 0, num_words = 0, num_lines = 0;
  iterate_over_input(&num_chars, &num_words, &num_lines);
  output_result(num_chars, num_words, num_lines);
  return EXIT_SUCCESS;
}

void output_result(const int num_chars, const int num_words,
                   const int num_lines) {
  printf("Number of Characters = %d\n"
         "Number of words = %d\n"
         "Number of lines = %d\n",
         num_chars, num_words, num_lines);
}

int check_if_char_is_letter(const char character) {
  int is_letter = FALSE;
  if ((character >= 65 && character <= 90) ||
      (character >= 97 && character <= 122)) {
    is_letter = TRUE;
  }
  return is_letter;
}

void count_lines(const char current_char, int *num_lines) {
  if (current_char == '\n') {
    ++*num_lines;
  }
}

void count_words(const char current_char, const char next_char,
                 int *num_words) {
  int is_current_letter = FALSE, is_next_letter = FALSE;
  is_current_letter = check_if_char_is_letter(current_char);
  is_next_letter = check_if_char_is_letter(next_char);
  if (is_current_letter && !is_next_letter) {
    ++*num_words;
  }
}

void count_chars(int *num_chars) { ++*num_chars; }

void iterate_over_input(int *num_chars, int *num_words, int *num_lines) {
  char current_char = '\0';
  char next_char = getchar();
  current_char = next_char;
  next_char = getchar();
  while (next_char != EOF) {
    count_chars(num_chars);
    count_words(current_char, next_char, num_words);
    count_lines(current_char, num_lines);
    current_char = next_char;
    next_char = getchar();
    if (next_char == EOF) {
      count_chars(num_chars);
      count_words(current_char, next_char, num_words);
      count_lines(current_char, num_lines);
    }
  }
}

void output_greeting() {
  printf("Input a string and get number of charcters, words and lines:\n"
         "Enter 'ctrl + z' to end the script on Windows"
         "And 'ctrl + d' to end the script on Unix\n");
}

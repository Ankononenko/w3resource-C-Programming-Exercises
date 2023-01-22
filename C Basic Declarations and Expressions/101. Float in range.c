  // Copyright School 21 finchren 2023

  /*
  There are three given ranges, write a C program that reads
  a floating-point number and find the range where it belongs
  from four given ranges
  Ranges: 0-30, 31-50, 51-80, 81-100
  Sample Output:
  Input a number: 87
  Range (80,100]
  ✔ 1. Write a plan to complete the exercise
  ✔ 2. Input and incorrect input
  ✔ 3. Find the correct range
  ✔ 3.5 Output result
  ✔ 4. Test
  ✔ 5. Google style check - clang-format
  ✔ 6. Add and push
  */

  #include <stdio.h>
  #include <stdlib.h>

  enum is_valid { FALSE, TRUE };
  enum range { THIRTY, FIFTY, EIGHTY, HUNDRED, ERROR };

  int input_value(float *value);
  void invalid_input();
  enum range check_ranges(const float num);
  void output_result(const int result);

  int main(void) {
    float num = 0.0;
    if (input_value(&num)) {
      int result = check_ranges(num);
      output_result(result);
    } else {
      invalid_input();
    }
    return EXIT_SUCCESS;
  }

  void output_result(const int result) {
    switch (result) {
    case THIRTY:
      printf("Range (0,30]\n");
      break;
    case FIFTY:
      printf("Range (31,50]\n");
      break;
    case EIGHTY:
      printf("Range (51,80]\n");
      break;
    case HUNDRED:
      printf("Range (81,100]\n");
      break;
    case ERROR:
      printf("Error. Range doesn't suit any condition\n");
      break;
    default:
      printf("Error. Unknown switch case\n");
    }
  }

  // Ranges: 0-30, 31-50, 51-80, 81-100
  enum range check_ranges(const float num) {
    return num <= 30.0f ? THIRTY :
            num <= 50.0f ? FIFTY :
            num <= 80.0f ? EIGHTY :
            num <= 100.0f ? HUNDRED :
            ERROR;
  }

  void invalid_input() {
    printf("The script takes only one positve number that is less than 100\n"
          "At the end of the line a newline is expected\n");
  }

  int input_value(float *value) {
    int is_valid_input = FALSE;
    char newline = '\0';
    printf("Input a number:\n");
    if (scanf("%f%c", value, &newline) && newline == '\n' &&
        *value >= 0.0 && *value <= 100.0) {
      is_valid_input = TRUE;
    }
    return is_valid_input;
  }

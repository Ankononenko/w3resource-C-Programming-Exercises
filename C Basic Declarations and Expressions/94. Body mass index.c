// Copyright School 21 finchren 2023

/*
Task:
Write a C program to calculate body mass index and display the grade
Sample Output:
Input the weight: 65
Input the height: 5.6
BMI = 2.072704

Grade: Under

✔ 1. Write a plan to complete the exercise
✔ 2. Input and invalid input
✔ 3. Count the body mass index
✔ 4. Output the result
✔ 5. Test
✔ 6. Google style check - clang-format
✔ 7. Add and push
*/

#include <stdio.h>
#include <string.h>

enum is_valid { FALSE, TRUE };

int input_num(char string[], double *num);
void invalid_input();
void calculate_bmi(const double weight, const double height, double *bmi);
void output_bmi(const double bmi);
void output_grage(const double bmi);

int main() {
  char ask_weight[26] = "Input the weight in kilos";
  double weight = 0.0;
  if (input_num(ask_weight, &weight)) {
    char ask_height[27] = "Input the height in meters";
    double height = 0.0;
    if (input_num(ask_height, &height)) {
      double bmi = 0.0;
      calculate_bmi(weight, height, &bmi);
      output_bmi(bmi);
      output_grage(bmi);
    } else {
      invalid_input();
    }
  } else {
    invalid_input();
  }
  return 0;
}

void output_grage(const double bmi) {
  char grade[15] = {'\0'};
  if (bmi < 18.5) {
    strcpy(grade, "Underweight");
  } else if (bmi >= 18.5 && bmi <= 24.9) {
    strcpy(grade, "Normal");
  } else if (bmi >= 25.0 && bmi < -29.9) {
    strcpy(grade, "Overweight");
  } else {
    strcpy(grade, "Obese");
  }
  printf("Grade: %s\n", grade);
}

void output_bmi(const double bmi) { printf("BMI = %lf\n", bmi); }

void calculate_bmi(const double weight, const double height, double *bmi) {
  *bmi = weight / (height * height);
}

void invalid_input() {
  printf("The script takes only a single positive number at a time\n"
         "At the end of the line a newline is expected\n");
}

int input_num(char string[], double *num) {
  int is_valid_input = FALSE;
  char newline = '\0';
  printf("%s: ", string);
  if (scanf("%lf%c", num, &newline) && newline == '\n' && *num > 0) {
    is_valid_input = TRUE;
  }
  return is_valid_input;
}

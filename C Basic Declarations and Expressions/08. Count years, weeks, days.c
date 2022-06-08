/* 
Write a C program to convert specified days into years, weeks and days
Note: Ignore leap year.

Test Data :
Number of days : 1329
Expected Output :
Years: 3
Weeks: 33
Days: 3

+ 1. Scan int that is going to be value for the numbe of days
+ 2. Invalid input
+ 3. Pass to a function that is going to 
+ 4. Test
+ 5. Cpplint test
+ 6. Add and push
*/

#include <stdio.h>

enum is_true {
    FALSE,
    TRUE
};

int enter_number_of_day(int *number_of_days);
void count_output_data(int *number_of_days);
void invalid_input();

int main() {
    int number_of_days = 0;
    if (enter_number_of_day(&number_of_days) == FALSE) {
        invalid_input();
    } else {
        count_output_data(&number_of_days);
    }
    return 0;
}

int enter_number_of_day(int *number_of_days) {
    int is_valid = TRUE;
    char endline = '\n';
    if (!scanf("%d%c", number_of_days, &endline) || *number_of_days < 1 || endline != '\n') {
        is_valid = FALSE;
    }
    return is_valid;
}

void invalid_input() {
    printf("Invalid input\n"
    "Days can only be positive whole number\n");
}

void count_output_data(int *number_of_days) {
    int years = *number_of_days / 365;
    *number_of_days -= years * 365;
    int weeks = *number_of_days / 7;
    *number_of_days -= weeks * 7;
    int days = *number_of_days;
    printf("Years: %d\n"
        "Weeks: %d\n"
        "Days: %d\n", years, weeks, days);
}

// Copyright School 21 finchren 2022

/*
Task:
Write a C program to create enumerated data type for 7 days and display their values in integer constants
Sun = 0
Mon = 1
Tue = 2
Wed = 3
Thu = 4
Fri = 5
Sat = 6

✔ 1. Write a plan to complete the exercise
✔ 2. Make array of strings with the days
✔ 3. Iterate over the enum and output the values
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

void output_days(const char* days[]);

int main() {
    const char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    output_days(days);
    return 0;
}

void output_days(const char* days[]) {
    int days_in_a_week = 7;
    for (int index = 0; index < days_in_a_week; ++index) {
        printf("%s = %d\n", days[index], index);
    }
}

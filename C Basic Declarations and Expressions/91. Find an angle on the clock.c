// Copyright School 21 finchren 2023

/*
Task:
Write a C program to find the angle between (12:00 to 11:59) the hour hand and the minute hand of a clock
The hour hand and the minute hand is always among 0 degree and 180 degree. 
For example, when it's 12 o'clock, the angle of the two hands is 0 while 3:00 is 45 degree and 6:00 is 180 degree.
Sample Output:
Input hour(h) and minute(m) (separated by a space): 3 00
The angle is 45.0 degrees at 3:00.

✔ 1. Write a plan to complete the exercise
✔ 2. Input and invalid input
✔ 3. Function to count the degrees and output the result
✔ 3.5 Figure out the way to count the degrees based on the time
✔ 3.6 Fix the issue with 00 minutes or 00 hours output
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>

enum is_valid{
    FALSE,
    TRUE
};

int input_time(int* hour, int* minute);
void invalid_input();
void convert_24_time_to_12(int* hour);
void print_time(const int degrees, const int hour, const int minute);
int count_degrees(const int hour, const int minute);
void convert_hours_mins_to_degrees(int* converted_hours, int* converted_minutes);
void insert_zeros(char hour_string[], char minute_string[], const int hour, const int minute);

int main() {
    int hour = 0, minute = 0;
    if (input_time(&hour, &minute)) {
        int converted_hours = hour, converted_minutes = minute;
        convert_24_time_to_12(&converted_hours);
        convert_hours_mins_to_degrees(&converted_hours, &converted_minutes);
        int degrees = count_degrees(converted_hours, converted_minutes);
        print_time(degrees, hour, minute);
    } else {
        invalid_input();
    }
    return 0;
}

void convert_hours_mins_to_degrees(int* converted_hours, int* converted_minute) {
    *converted_hours *= 30;
    *converted_minute *= 6;
}

int count_degrees(const int hour, const int minute) {
    int degrees = 0;
    if (hour > minute || minute > hour) {
        degrees = hour > minute ? hour - minute : minute - hour;
    }
    return degrees;
}

void insert_zeros(char hour_string[], char minute_string[], const int hour, const int minute) {
    if (!hour) {
        hour_string[0] = '0';
        hour_string[1] = '0';
    }
    if (!minute) {
        minute_string[0] = '0';
        minute_string[1] = '0';
    }
    if (hour <= 9) {
        hour_string[0] = '0';
        hour_string[1] = hour + 48;
    }
    if (minute <= 9) {
        minute_string[0] = '0';
        minute_string[1] = minute + 48;
    }
}

void print_time(const int degrees, const int hour, const int minute) {
    char hour_string[3] = {'\0'}, minute_string[3] = {'\0'};
    itoa(hour, hour_string, 10);
    itoa(minute, minute_string, 10);
    insert_zeros(hour_string, minute_string, hour, minute);
    printf("The angle is %d degrees at %s:%s\n", degrees, hour_string, minute_string);
}

void convert_24_time_to_12(int* hour) {
    if (*hour == 24 || *hour == 0) {
        *hour = 0;
    } else {
        *hour = *hour > 12 ? *hour - 12 : *hour;
    }
}

void invalid_input() {
    printf("The hours and minutes should be entered separetaed by a space\n"
           "0 >= hour <= 24, 0 >= minute <= 60\n");
}

int input_time(int* hour, int* minute) {
    int is_valid = FALSE;
    char newline = '\0';
    printf("Input hour(h) and minute(m) (separated by a space): ");
    if (scanf("%d %d%c", hour, minute, &newline) && newline == '\n'&&
    *hour <= 24 && *hour >= 0 &&
    *minute <= 60 && *minute >= 0) {
        is_valid = TRUE;
    }
    return is_valid;
}

  // Copyright School 21 finchren 2022

/*
Task:
Write a C program to demonstrate the difference between predecrementing and postdecrementing using the decrement operator --.
Sample Output:
Predecrementing:
x = 10
x-- = 10
x = 9

✔ 1. Write a plan to complete the exercise
✔ 2. Function for predecrementing
✔ 3. Postdecrementing
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

void output_predecrementing(const int num);
void output_postdecrementing(const int num);
void output_midway(const int num);

int main() {
    int num = 10;
    output_predecrementing(num);
    output_midway(num);
    output_postdecrementing(num);
    return 0;
}

void output_midway(const int num) {
    printf("x-- = %d\n", num);
}

void output_postdecrementing(const int num) {
    int temp_num = num;
    temp_num--;
    printf("x = %d\n", temp_num);
}

void output_predecrementing(const int num) {
    printf("Predecrementing:\n"
            "x = %d\n", num);
}

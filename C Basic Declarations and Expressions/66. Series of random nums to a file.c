// Copyright School 21 finchren 2022

/*
Task:
 Write a C program that generates 50 random numbers between -0.5 and 0.5 and writes them in a file rand.dat.
 The first line of ran.dat contains the number of data and the next 50 lines contains the 50 random numbers
50
-0.4215
0.2620
0.3065
-0.0485
.... 0.3980
0.1750
0.4780
-0.2915
0.0715
0.3565

✔ 1. Write a plan to complete the exercise
✔ 2. Function to generate random numbers
✔ 3. Write them to the file
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_num(const double lower, const double upper, double* num);

int main() {
    FILE *file_pointer;
    file_pointer = fopen("ran.dat", "w");
    fprintf(file_pointer, "%d\n", 50);
    // Use current time as a seed for random number generator
    srand(time(0));
    double upper = 0.5, lower = -0.5, num = 0.0;
    for (double i = 0; i < 50; ++i) {
        generate_random_num(lower, upper, &num);
        fprintf(file_pointer, "%.4lf\n", num);
    }
    fclose(file_pointer);
    return 0;
}

void  generate_random_num(const double lower, const double upper, double* num) {
    double range = (upper - lower);
    double divisor = RAND_MAX / range;
    *num = lower + (rand_r() / divisor);
}

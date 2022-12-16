// Copyright School 21 finchren 2022

/*
Task:
Write a C program that prints out the prime numbers between 1 and 200. 
The output should be such that each row contains a maximum of 10 prime numbers.
Expected output:
The prime numbers between 1 and 199 are:
2 3 5 7 11 13 17 19 23 29
31 37 41 43 47 53 59 61 67 71
73 79 83 89 97 101 103 107 109 113
127 131 137 139 149 151 157 163 167 173
179 181 191 193 197 199

✔ 1. Write a plan to complete the exercise
✔ 2. Function to find prime number
✔ 3. Function to iterate over the range and print out the result
✔ 4. Test
✔ 5. Cpplint test
✔ 6. Add and push
*/

#include <stdio.h>

enum my_bool{
    FALSE,
    TRUE
};

int is_prime(const int num);
void output_primes(const int start, const int end);

int main() {
    int start = 1, end = 200;
    output_primes(start, end);
    return 0;
}

void output_primes(const int start, const int end) {
    printf("The prime numbers between %d and %d are\n", start, end);
    int newline_index = 0;
    for (int index = start; index <= end; ++index) {
        if (is_prime(index)) {
            printf("%d ", index);
            ++newline_index;
        }
        if (newline_index == 10) {
            printf("\n");
            newline_index = 0;
        }
    }
}

int is_prime(const int num) {
    int is_prime = TRUE;
    if (num == 1) {
        is_prime = FALSE;
    }
    for (int index = 2; index < num; ++index) {
        if (!(num % index)) {
            is_prime = FALSE;
            break;
        }
    }
    return is_prime;
}

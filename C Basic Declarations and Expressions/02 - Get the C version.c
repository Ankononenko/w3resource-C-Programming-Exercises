// Copyright 2022 finchren 
/*
Write a C program to get the C version you are using.
Expected Output:
We are using C18!
*/

#include <stdio.h>
#include <string.h>

int main() {
    char version_to_print[] = "C90";
    char our_version_is[] = "We are using";
    #if defined __STDC_VERSION__
        long version = __STDC_VERSION__;
        if (version == 199409) {
            strcpy(version_to_print, "C94");
            printf("%s %s!", our_version_is, version_to_print);    
        }
        if (version == 199901) {
            strcpy(version_to_print, "C99");
            printf("%s %s!", our_version_is, version_to_print);    
        }
        if (version == 201112) {
            strcpy(version_to_print, "C11");
            printf("%s %s!", our_version_is, version_to_print);    
        }
        if (version == 201710) {
            strcpy(version_to_print, "C18");
            printf("%s %s!", our_version_is, version_to_print);    
        }
    #else
        printf("%s %s!", our_version_is, version_to_print);
    #endif
    return 0;
}

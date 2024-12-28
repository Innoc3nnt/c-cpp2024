#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compare_int(const void* a, const void* b){
        return (*(int*)a - *(int*)b);
}

// ЗДЕСЬ ТОЛЬКО ПРИМЕРЫ ИСПОЛЬЗОВАНИЯ!!!!
// за тонкостями реализации идти в лекции!!

int main(){

    // int atoi(const char* str)

    int a = atoi("123"); // a = 123

    a = atoi("123.45"); // 123, use atof instead

    a = atoi("abc"); // UB, usually 0

    a = atoi("123abc"); // a = 123, ignores all NaN symbols

    printf("%d\n", a);


    // double atof(const char* str) // long double atolf(const char* str)

    double b = atof("123.44"); // b = 123.440000, similar behavior to atoi, accepts only dot as delimiter

    printf("%f\n", b);


    // long strtol(const char *start, char **end, int radix) // unsigned long strtoul(const char *start, char **end, int radix)
    char *end = NULL;

    long c = strtol("123", &end, 0); // c = 123, end = ""

    c = strtol("123a123", &end, 0); // c = 123, end = "a123", returns pointer to the first non-numeric symbol

    c = strtol("123.123", &end, 0); // c = 123, end = ".123", returns pointer to the first non-numeric symbol

    c = strtol("10", &end, 2); // c = 123, end = "", radix is the base of number, binary in this example

    c = strtol("0azzz", &end, 16); // c = 10, end = "zzz", radix is the base of number, hex in this example

    // if radix != 0 then 2 <= radix <= 36

    printf("%ld ", c);
    printf("%s\n", end);

    // int rand(); Returns a pseudo-random integer value between ​0​ and RAND_MAX (0 and RAND_MAX included)

    int d = rand(); // random integer from 0 to RAND_MAX = 2147483647 by default (Ubuntu + gcc), can be modified by #define RAND_MAX <any_value>

    // void srand( unsigned seed ); default seed = 1. Sets seed to rand().

    srand(52); // rand() seed set to 52

    printf("%d", d);

    // void qsort( void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*) );
        // sorts any type of data with given number of elements, data size and comparator function
    int arr[5] = {5, 3, 1, 2, 4};

    qsort(arr, 5, sizeof(int), compare_int); // arr = {5, 3, 1, 2, 4} -> arr = {1, 2, 3, 4, 5}, to see comp implementation see line 5

}
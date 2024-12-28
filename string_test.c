#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// ЗДЕСЬ ТОЛЬКО ПРИМЕРЫ ИСПОЛЬЗОВАНИЯ!!!!
// за тонкостями реализации идти в лекции!!

int main(){

    // void* memcpy( void *dest, const void *src, size_t count );
    // Copies count characters from the object pointed to by src to the object pointed to by dest. Both objects are interpreted as arrays of unsigned char
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5];

    memcpy(arr2, arr1, 10); // UB

    memcpy(arr2, arr1, 5); // arr2 = {} -> arr2 = {1, 2, 3, 4, 5}


    int arr3[3];
    memcpy(arr3, arr1, 4); // UB

    // int memcmp( const void* lhs, const void* rhs, size_t count );
    // Compares the first count bytes of the objects pointed to by lhs and rhs. The comparison is done lexicographically.

    int comp = memcmp(arr1, arr2, 5); // comp = 0

    // char* strcpy( char* dest, const char* src );
    // Copies the character string pointed to by src, including the null terminator, to the character array whose first element is pointed to by dest.

    char* src = "test";
    char dest[10];

    strcpy(dest, src); // dest = "" -> dest = "test"
    // UB if length of dest buffer less than src


    // int strcmp( const char* lhs, const char* rhs );
    // Compares two null-terminated byte strings lexicographically.

    char* str1 = "abc";
    char* str2 = "abd";

    int cmp = strcmp(str1, str2); // str1 < str2, differs by 1 in ASCII -> cmp = -1

    // char * strcat ( char * destination, const char * source );

    //   Appends a copy of the source string to the destination string. The terminating null character in destination is 
    // overwritten by the first character of source, and a null-character is included at the end of the new string 
    // formed by the concatenation of both in destination.

    // Pointer to the destination array, which should contain a C string, and be large enough to contain the concatenated resulting string.
    // UB in other cases

    char str[50] = ""; // str = ""
    strcat(str, "test"); // str = "test"
    strcat(str, "test"); // str = "testtest"

    // const char* strstr( const char* haystack, const char* needle );
    // Finds the first occurrence of the byte string needle in the byte string pointed to by haystack. The terminating null characters are not compared.

    const char* haystack = "2345123451";
    const char* needle = "12";

    char* test = strstr(haystack, needle); // test = "123451"

    needle = "0";
    test = strstr(haystack, needle); // test = NULL

    // printf("%s\n", test);

    
    // char* strchr( const char* str, int ch );
    // Finds the first occurrence of ch (after conversion to char as if by (char)ch) in the null-terminated byte string 
    // pointed to by str (each character interpreted as unsigned char). The terminating null character is considered to be 
    // a part of the string and can be found when searching for '\0'

    haystack = "2345123451";

    test = strchr(haystack, '1'); // test = "123451"

    test = strchr(haystack, '0'); // test = NULL


    // char * strtok ( char * str, const char * delimiters );
    // A sequence of calls to this function split str into tokens, 
    // which are sequences of contiguous characters separated by any of the characters that are part of delimiters.

    char toSplit[] = "23451234561";
    char *delimiter = "12";

    char* test1 = strtok(toSplit, delimiter);
    while (test1 != NULL) {
        printf("%s\n", test1); // test1 = "345" on 1 iter, test1 = "3456" on 2 iter, test1 = NULL on 3 iter
        test1 = strtok(NULL, delimiter);
    }

    // дальше я заебался и хочу спать время 4:12, все можно посмотреть в лекциях по идее
}
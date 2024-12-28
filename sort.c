#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(void* a, void* b, size_t elem_size){
    char *ptr_a = (char*)a;
    char *ptr_b = (char*)b;
    char *tmp = (char*)malloc(elem_size);
    if (!tmp){
        fprintf(stderr, "Memory allocation error!");
        free(tmp);
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < elem_size; i++){
        tmp[i] = ptr_a[i];
        ptr_a[i] = ptr_b[i];
        ptr_b[i] = tmp[i];
    }
    free(tmp);
}

void sort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)){
    if (num < 2){
        exit(0);
    }
    char *array = (char*)base;
    for (size_t i = 0; i < num - 1; i++){
        for (size_t j = 0; j < num - i - 1; j++){
            if (compar(array + j * size, array + (j + 1) * size) >= 0){
                swap(array + j * size, array + (j + 1) * size, size);
            }
        }
    }
}


int comp_int(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int comp_char(const void* a, const void* b){
    return (*(char*)a - *(char*)b);
}

int compare_str(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}


int main(){
    int n = 5;
    // int arr[5] = {4, 5, 2, 3, 1};
    // char arr[5] = {'5', '4', '2', '3', '1'};
    char arr[5][10] = {"5", "4", "2", "3", "1"};

    sort(arr, n, sizeof(arr[0]), compare_str);

    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}
#include <stdlib.h>
#include <stdio.h>

int main(){
    int rows = 5;
    int cols = 5;

    int **array = (int**)malloc(rows * sizeof(int*));
    if (!array){
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }

    *array = (int*)malloc(rows * cols * sizeof(int));
    if (!*array){
        fprintf(stderr, "Memory allocation error!");
        free(array);
        exit(EXIT_FAILURE);
    }
    *array = (int*)realloc(*array, rows * (cols + 1) * sizeof(int));
    if (!*array){
        fprintf(stderr, "Memory allocation error!");
        free(array);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < rows; i++){
        array[i] = array[0] + i * (cols + 1);
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols + 1; j++){
            array[i][j] = i * (cols + 1) + j;
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols + 1; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    free(*array);
    free(array);

    return 0;
}

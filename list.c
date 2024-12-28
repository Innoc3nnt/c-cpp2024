#include <stdlib.h>
#include <stdio.h>

typedef struct intlist
{
    struct intlist *next;
    int value;

} list_t;

void push(list_t **list, int value){
    list_t *tempNode = (list_t*)malloc(sizeof(list_t));
    tempNode->next = *list;
    tempNode->value = value;
    *list = tempNode;
}

int pop(list_t **list){
    if (*list != NULL){
        list_t *prev = (*list);
        int value = (*list)->value;
        (*list) = (*list)->next;
        free(prev);
        return value;
    }
    exit(-1);
}

void print_list(list_t *list){
    while (list){
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

void delete_all(list_t **list){
    while (*list){
        pop(list);
    }
}


int main(){
    list_t *list = NULL;
    push(&list, 1);
    push(&list, 2);
    push(&list, 3);
    print_list(list);
    printf("Extracted value: %d\n", pop(&list));
    printf("Extracted value: %d\n", pop(&list));
    printf("Extracted value: %d\n", pop(&list));
    printf("Extracted value: %d\n", pop(&list));
    print_list(list);
    delete_all(&list);
}
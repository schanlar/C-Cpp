#include <stdio.h>
#include <stdlib.h>

typedef struct list_properties{
    double *array;
    int size;
}List;


List insert(List l, double num){
    l.array = (double *) realloc(l.array, sizeof(double) * (l.size + 1));
    l.array[l.size] = num;
    (l.size)++;
    return l;
}

void append(List *pl, double num){
    pl -> array = (double *) realloc(pl -> array, sizeof(double) * (pl -> size + 1));
    pl -> array[pl -> size] = num;
    (pl -> size)++;
    return;
}

void freeList(List *pl){
    if (pl == NULL){
        return;
    }
    else{
        free(pl -> array);
        pl = NULL;
        return;
    }
}

void display(List l){
    printf("[");
    for (int i = 0; i < l.size; i++){
        char *s = (i < l.size - 1) ? "%.1lf, " : "%.1lf";
        printf(s, l.array[i]);
    }
    printf("]\n");
}



int main(void){
    List my_list;
    my_list.size = 0;

    for (int i = 1; i < 5; i++){
        append(&my_list, i);
    }
    display(my_list);
    
    for (int j = 10; j < 13; j++){
        my_list = insert(my_list, j);
    }
    display(my_list);
    
    freeList(&my_list);
    
    return 0;
}
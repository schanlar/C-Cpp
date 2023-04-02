#include <stdio.h>
#include <stdlib.h>

typedef struct list_properties{
    double *array;
    int size;
}List;

List append(List v, double num){
    v.array = (double*) realloc(v.array, sizeof(double) * (v.size + 1));
    v.array[v.size] = num;
    (v.size)++;
    return v;
}

void freeList(List* vp){;
    if (vp == NULL){
        return;
    }
    else {
        free(vp -> array); // free the part that is stored in heap
        vp = NULL;
        return;
    }
}

void display(List v){
    printf("[");
    for (int i = 0; i < v.size; i++){
        char *s = (i < v.size - 1) ? "%.1lf, " : "%.1lf";
        printf(s, v.array[i]);
    }
    printf("]\n");
}


int main(void){
    List my_list;
    my_list.size = 0;
    
    for (int i = 1; i < 21; i++){
        my_list = append(my_list, i);
    }
    
    display(my_list);
    freeList(&my_list);
    
    return 0;
}
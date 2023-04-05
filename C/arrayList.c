#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <float.h>


typedef struct list_properties{
    double *array;
    int size;
}List;


int contain(List l, double num, double eps){
    // serial search
    for (int idx = 0; idx < l.size; idx++){
        if (fabs(l.array[idx] - num) <= eps){
            return idx;
        }
    }
    return -1;
}

List insert(List l, double num){
    l.array = (double *) realloc(l.array, sizeof(double) * (l.size + 1));
    l.array[l.size] = num;
    (l.size)++;
    return l;
}

List extract(List l, double num){
    /* index of number in list (-1 if number does not exist) */
    int idx = contain(l, num, 1e-6);
    /* If number exists in List then move elements one position back */
    if (idx != -1){
        for (int i = idx; i < l.size - 1; i++){
            int i_next = i + 1;
            l.array[i] = l.array[i_next];
        }
        /* Re-allocate memory and update size */
        l.array = (double *) realloc(l.array, sizeof(double) * (l.size - 1));
        (l.size)--;
    }
    return l;
}

void append(List *pl, double num){
    pl -> array = (double *) realloc(pl -> array, sizeof(double) * (pl -> size + 1));
    pl -> array[pl -> size] = num;
    (pl -> size)++;
    return;
}

double pop(List *pl, double num){
    /* index of number in list (-1 if number does not exist) */
    int idx = contain(*pl, num, 1e-6);
    /* If number exists in List then move elements one position back */
    if (idx != -1){
        double popped_value = (pl -> array [idx]);
        for (int i = idx; i < (pl -> size - 1); i++){
            int i_next = i + 1;
            pl -> array[i] = (pl -> array[i_next]);
        }
        /* Re-allocate memory and update size */
        pl -> array = (double *) realloc(pl -> array, sizeof(double) * (pl -> size - 1));
        (pl -> size)--;
        
        return popped_value;
    }
    return -DBL_MAX;
}

void freeList(List *pl){
    if (pl == NULL){
        return;
    }
    else {
        free(pl -> array); // De-allocate the part of the structure that is allocated in heap memory
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
    return;
}


int main(void){
    srand(time(NULL));
    
    /* 
    * This is a variable stored in stack memory.
    * Within the stack frame there is a pointer (my_list.array) 
    * that points to the allocated memory in heap where the array is defined. 
    * In other words, the pointer "my_list.array" is stored in stack
    * but it points to the heap memory where the actual data are stored.
    */
    List my_list; 
    my_list.size = 0;
    
    /* Add random numbers using the append function */ 
    for (int i = 1; i < 5; i++){
        append(&my_list, i + (rand() % 10) / 10.);
    }
    display(my_list);
    
    /* Add numbers using the insert function */
    for (int j = 10; j < 12; j++){
        my_list = insert(my_list, j);
    }
    display(my_list);
    
    /* Remove number using the pop function */
    double tmp = pop(&my_list, 10.000001);
    display(my_list);
    
    /* Remove number using the extract function */
    my_list = extract(my_list, 11.0);
    display(my_list);
    
    freeList(&my_list);
    
    return 0;
}
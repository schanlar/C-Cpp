#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <float.h>


typedef struct list_properties{
    double *array;
    int size;
    // Maybe add more fields later (?)
}List;

/* Check if number exists in List. If yes, return its index location
otherwise return -1 */
int contain(List l, double num, double eps){
    // serial search
    for (int idx = 0; idx < l.size; idx++){
        if (fabs(l.array[idx] - num) <= eps){
            return idx;
        }
    }
    return -1;
}

/* Add number to List and return the new List */
List insert(List l, double num){
    l.array = (double *) realloc(l.array, sizeof(double) * (l.size + 1));
    l.array[l.size] = num;
    (l.size)++;
    return l;
}

/* Remove number from List and return the new List */
List erase(List l, double num, double eps){
    /* index of number in list (-1 if number does not exist) */
    int idx = contain(l, num, eps);
    /* If number exists in List then move elements one position back */
    if (idx != -1){
        for (int i = idx; i < l.size - 1; i++){
            l.array[i] = l.array[i+1];
        }
        /* Re-allocate memory and update size */
        l.array = (double *) realloc(l.array, sizeof(double) * (l.size - 1));
        (l.size)--;
    }
    return l;
}

/* Add number to List (in-place) */
void append(List *pl, double num){
    pl->array = (double *) realloc(pl->array, sizeof(double) * (pl->size + 1));
    pl->array[pl -> size] = num;
    (pl->size)++;
    return;
}

/* Remove number from List and return it */
double pop(List *pl, double num, double eps){
    int idx = contain(*pl, num, eps);
    // If number exists in List then move elements one position back 
    if (idx != -1){
        double popped_value = (pl->array [idx]);
        for (int i = idx; i < (pl->size - 1); i++){
            pl->array[i] = (pl->array[i+1]);
        }
        // Re-allocate memory and update size 
        pl->array = (double *) realloc(pl->array, sizeof(double) * (pl->size - 1));
        (pl->size)--;
        
        return popped_value;
    }
    return -DBL_MAX;
}

int is_equal(List l, List n, double eps){
    if (l.length == n.length){
        for (int i=0; i<l.length; i++){
            if (fabs(l.array[i] - n.array[i]) > eps){
                printf("Found different numbers at index %d: %.1f != %.1f\n", i, l.array[i], n.array[i]);
                return 0;
            }
        }
        return 1;
    }
    printf("Lists do not have the same length!\n");
    return 0;
}

/* Deallocate part of List that is stored in heap memory */
void deallocate(List *pl){
    if (pl == NULL || pl->array == NULL){
        return;
    }
    else {
        free(pl->array);
        pl = NULL;
        pl->array = NULL;
        return;
    }
}

/* Display elements of List */
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
    
    /* Initialize an empty List, named my_list.
    * my_list is a variable of type List that is stored in stack memory.
    * Within the main stack frame, there is a pointer (my_list.array) that
    * itself is stored in stack but it points to a location in heap memory: the 
    * address where the actual array data are stored.
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
    double tmp = pop(&my_list, 10.001, 1e-2);
    display(my_list);
    printf("%.1lf\n", tmp);
    
    /* Remove number using the erase function */
    my_list = erase(my_list, 11, 1e-6);
    display(my_list);

    /* Test equality */
    List ml1, ml2;
    ml1.length = 0;
    ml2.length = 0;
    
    printf("%d\n", is_equal(my_list, ml1, 1e-6));
    
    for (int i=8; i<15; i++){
        append(&ml1, i);
        append(&ml2, i);
    }
    display(ml1);
    display(ml2);
    
    printf("%d\n", is_equal(ml1, ml2, 1e-6));
    
    append(&ml1, rand()%10);
    append(&ml2, rand()%10);
    
    display(ml1);
    display(ml2);
    
    printf("%d\n", is_equal(ml1, ml2, 1e-6));
    
    deallocate(&my_list);
    
    return 0;
}
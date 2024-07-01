#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>


typedef struct stack_properties{
    double* array;
    unsigned int capacity;
    unsigned int length;
    unsigned int top_idx;
    unsigned int bottom_idx;
}STACK;


void* safe_malloc(size_t size){
    void* ptr = malloc(size);
    if (!ptr){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void* safe_realloc(void* ptr, size_t size){
    void* new_ptr = realloc(ptr, size);
    if (!new_ptr){
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

STACK initialize(size_t initial_capacity){
    STACK s;
    s.array = (double*) safe_malloc(sizeof(double) * initial_capacity);
    s.capacity = initial_capacity;
    for (unsigned int i=0; i<s.capacity; i++){
        s.array[i] = NAN;
    }
    s.length = 0;
    s.top_idx = - 1;
    s.bottom_idx = - 1;
    return s;
}

int is_stack_initialized(const STACK* ps){
    if (ps && ps->array) return 1;
    printf("Stack has not been initialized!\n");
    return 0;
}

int is_empty(const STACK* ps){
    if (!is_stack_initialized(ps)) return -1;
    if (ps->top_idx == -1 && ps->bottom_idx == -1) return 1;
    return 0;
}

void deallocate(STACK* ps){
    if (!is_stack_initialized(ps)) return;
    free(ps->array);
    ps->array = NULL;
    ps->capacity = 0;
    ps->length = 0;
    ps->top_idx = -1;
    ps->bottom_idx = -1;
}

void resize(STACK* ps, size_t size){
    if (!is_stack_initialized(ps)) return;
    // printf("Resizing...\n");
    ps->array = (double*) safe_realloc(ps->array, sizeof(double) * size);
    ps->capacity = size;

    unsigned int new_top_idx = ps->capacity - 1;
    unsigned int new_bottom_idx = ps->top_idx + 1;
    
    for (unsigned int i=new_bottom_idx; i<=new_top_idx; i++){
        ps->array[i] = ps->array[ps->bottom_idx];
        ps->array[ps->bottom_idx++] = NAN;
    }
    ps->top_idx = new_top_idx;
    ps->bottom_idx = new_bottom_idx;
}

double peek(const STACK* ps){
    if (!is_stack_initialized(ps)) return -DBL_MAX;
    if (is_empty(ps)) {
        printf("Stack is empty!\n");
        return -DBL_MAX;
    }
    return ps->array[ps->top_idx];
}

void push(STACK* ps, double num){
    if (!is_stack_initialized(ps)) return;
    if (isnan(num)){
        printf("Cannot push nan!\n");
        return;
    }
    if (ps->length == ps->capacity){
        resize(ps, ps->capacity * 2);
    }
    if (is_empty(ps)){
        ps->top_idx = ps->capacity - 1;
        ps->bottom_idx = ps->capacity - 1;
        
        ps->array[ps->top_idx] = num;
        ps->length++;
    } else {
        unsigned int new_bottom_idx = ps->bottom_idx - 1;
        for (unsigned int i=new_bottom_idx; i<ps->top_idx; i++){
            ps->array[i] = ps->array[i+1];
        }
        ps->array[ps->top_idx] = num;
        ps->bottom_idx = new_bottom_idx;
        ps->length++;
    }
}

double pop(STACK* ps){
    if (!is_stack_initialized(ps)) return -DBL_MAX;
    if (is_empty(ps)) {
        printf("Stack is empty!\n");
        return -DBL_MAX;
    }
    double xnum = ps->array[ps->top_idx];
    //unsigned int new_bottom_idx = ps->bottom_idx + 1;
    for (unsigned int i=ps->top_idx; i>ps->bottom_idx; i--){
       ps->array[i] = ps->array[i-1];
       ps->array[i-1] = NAN;
    }
    ps->bottom_idx++;
    ps->length--;
    return xnum;
}

void display(const STACK* ps){
    if (!is_stack_initialized(ps)) return;
    if (ps->length == 0){
        printf("[]\n");
        return;
    }
    printf("[\n");
    unsigned int i = ps->capacity-1;
    while(1){
        if (!isnan(ps->array[i])){
            printf(" %.1lf\n", ps->array[i]);
        }
        if (i == 0) break;
        i--;
    }
    printf("]\n");
}

void status(const STACK* ps){
    if (!is_stack_initialized(ps)) return;
    int bars_length = 100;
    printf("CAPACITY: %d; NUMBER OF ACTIVE ELEMENTS:%d; POSITION OF FIRST ELEMENT: %d; POSITION OF LAST ELEMENT:%d\n",
        ps->capacity, ps->length, ps->top_idx, ps->bottom_idx);
    for (int i=0; i<bars_length; i++){
        printf("-");
        if (i == bars_length - 1) printf("\n");
    }
}



int main(void){
    STACK ms = initialize(10);
    printf("Peeking: %.1lf\n", peek(&ms));
    printf("Popped: %.1lf\n", pop(&ms));
    display(&ms);
    status(&ms);
    
    for (int i=1; i<23; i++){
        push(&ms, i);
        printf("Peeking: %.1lf\n", peek(&ms));
        display(&ms);
        status(&ms);
    }
    
    printf("Popped: %.1lf\n", pop(&ms));
    printf("Peeking: %.1lf\n", peek(&ms));
    display(&ms);
    status(&ms);
    
    printf("Popped: %.1lf\n", pop(&ms));
    printf("Peeking: %.1lf\n", peek(&ms));
    display(&ms);
    status(&ms);
    
    return 0;
}
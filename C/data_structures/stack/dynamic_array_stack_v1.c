/**
 * @file dynamic_array_stack_v1.c
 * @brief A dynamic array-based stack implementation in C. This constitutes an improvement on a previous implementation
 * in file "dynamic_array_stack_v0.c"
 *
 * This module provides a stack data structure with dynamic resizing capabilities.
 * The stack supports typical operations such as push, pop, peek, and additional
 * utility functions like converting to an array and reversing the stack.
 *
 * Error codes:
 * - STACK_SUCCESS (1): Operation was successful.
 * - STACK_ERROR_NOT_INITIALIZED (-1): Stack is not initialized.
 * - STACK_ERROR_EMPTY (-2): Stack is empty.
 *
 * Functions:
 * - STACK initStack(size_t initial_capacity): Initialize the stack with the specified initial capacity.
 * - int isInitialized(const STACK* ps): Check if the stack is initialized.
 * - void freeStack(STACK* ps): Free the memory allocated for the stack.
 * - int isEmpty(const STACK* ps): Check if the stack is empty.
 * - void resizeStack(STACK* ps, size_t size): Resize the stack to the specified size.
 * - int peek(const STACK* ps, double* out): Peek at the top element of the stack without removing it.
 * - int push(STACK* ps, double num): Push a new element onto the stack.
 * - int pop(STACK* ps, double* out): Pop the top element off the stack.
 * - int toArray(const STACK* ps, double* out): Convert the stack to an array.
 * - void reverse(STACK* ps): Reverse the elements of the stack.
 * - void display(const STACK* ps): Display the elements of the stack.
 * - void status(const STACK* ps): Display the status of the stack.
 * 
 * Example usage:
 * ```
 * STACK s = initStack(4);
 * push(&s, 1.1);
 * push(&s, 2.2);
 * push(&s, 3.3);
 * push(&s, 4.4);
 * 
 * double value;
 * if (peek(&s, &value) == STACK_SUCCESS) {
 *     printf("Peeked value: %.1f\n", value);
 * }
 * 
 * display(&s);
 * status(&s);
 * 
 * reverse(&s);
 * display(&s);
 * 
 * while (pop(&s, &value) == STACK_SUCCESS) {
 *     printf("Popped value: %.1f\n", value);
 * }
 * 
 * status(&s);
 * freeStack(&s);
 * ```
 */

#include <stdio.h>
#include <stdlib.h>

#define STACK_SUCCESS 1
#define STACK_ERROR_NOT_INITIALIZED -1
#define STACK_ERROR_EMPTY -2

typedef struct stack {
    double* data;
    size_t capacity;
    size_t size;
} STACK;

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void* safe_realloc(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    if (!new_ptr) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

// Initialize the stack with the specified initial capacity
STACK initStack(size_t initial_capacity) {
    STACK s;
    s.data = safe_malloc(sizeof(double) * initial_capacity);
    s.capacity = initial_capacity;
    s.size = 0;
    return s;
}

// Check if the stack is initialized
int isInitialized(const STACK* ps) {
    return (ps && ps->data) ? STACK_SUCCESS : STACK_ERROR_NOT_INITIALIZED;
}

// Free the memory allocated for the stack
void freeStack(STACK* ps) {
    if (isInitialized(ps) == STACK_SUCCESS) {
        free(ps->data);
        ps->data = NULL;
        ps->capacity = 0;
        ps->size = 0;
    }
}

// Check if the stack is empty
int isEmpty(const STACK* ps) {
    if (isInitialized(ps) != STACK_SUCCESS) return STACK_ERROR_NOT_INITIALIZED;
    return ps->size == 0;
}

// Resize the stack to the specified size
void resizeStack(STACK* ps, size_t size) {
    if (isInitialized(ps) != STACK_SUCCESS) return;
    ps->data = (double*) safe_realloc(ps->data, sizeof(double) * size);
    ps->capacity = size;
}

// Peek at the top element of the stack without removing it
int peek(const STACK* ps, double* out) {
    if (isInitialized(ps) != STACK_SUCCESS) return STACK_ERROR_NOT_INITIALIZED;
    if (isEmpty(ps)) return STACK_ERROR_EMPTY;
    *out = ps->data[ps->size - 1];
    return STACK_SUCCESS;
}

// Push a new element onto the stack
int push(STACK* ps, double num) {
    if (isInitialized(ps) != STACK_SUCCESS) return STACK_ERROR_NOT_INITIALIZED;
    if (ps->size == ps->capacity) {
        resizeStack(ps, ps->capacity * 2);
    }
    ps->data[ps->size++] = num;
    return STACK_SUCCESS;
}

// Pop the top element off the stack
int pop(STACK* ps, double* out) {
    if (isInitialized(ps) != STACK_SUCCESS) return STACK_ERROR_NOT_INITIALIZED;
    if (isEmpty(ps)) return STACK_ERROR_EMPTY;
    *out = ps->data[--ps->size];
    return STACK_SUCCESS;
}

// Convert the stack to an array
int toArray(const STACK* ps, double* out) {
    if (isInitialized(ps) != STACK_SUCCESS) return STACK_ERROR_NOT_INITIALIZED;
    for (size_t i = 0; i < ps->size; i++) {
        out[i] = ps->data[i];
    }
    return ps->size;
}

// Reverse the elements of the stack
void reverse(STACK* ps) {
    if (isInitialized(ps) != STACK_SUCCESS) return;
    size_t bottom_idx = 0;
    size_t top_idx = ps->size - 1;
    while (bottom_idx < top_idx) {
        double tmp = ps->data[bottom_idx];
        ps->data[bottom_idx] = ps->data[top_idx];
        ps->data[top_idx] = tmp;
        bottom_idx++;
        top_idx--;
    }
}

// Display the elements of the stack
void display(const STACK* ps) {
    if (isInitialized(ps) != STACK_SUCCESS) {
        printf("Stack is not initialized.\n");
        return;
    }
    printf("[\n");
    if (isEmpty(ps)) {
        printf("]\n");
        return;
    }
    for (size_t i = ps->size; i > 0; i--) {
        printf(" %.1lf\n", ps->data[i - 1]);
    }
    printf("]\n");
}

// Display the status of the stack
void status(const STACK* ps) {
    if (isInitialized(ps) != STACK_SUCCESS) {
        printf("Stack is not initialized.\n");
        return;
    }
    int bar_length = 100;
    printf("CAPACITY: %zu; SIZE: %zu\n", ps->capacity, ps->size);
    for (int i = 0; i <= bar_length; i++) {
        printf("-");
        if (i == bar_length) printf("\n");
    }
}



// Example usage
int main() {
    STACK stack = initStack(5);
    display(&stack);
    status(&stack);

    for (int i=1; i<8; i++){
        push(&stack, i);
    }
    display(&stack);
    status(&stack);
    
    double popped_value;
    for (int i=0; i<2; i++){
        pop(&stack, &popped_value);
        printf("Popped value: %.1lf\n", popped_value);
        display(&stack);
        status(&stack);
    }
    

    printf("Stack contents:\n");
    double arr[stack.capacity];
    int size = toArray(&stack, arr);
    for (int i = 0; i < size; ++i) {
        printf("%.1f\n", arr[i]);
    }

    reverse(&stack);

    printf("Reversed stack contents:\n");
    size = toArray(&stack, arr);
    for (int i = 0; i < size; ++i) {
        printf("%.1f\n", arr[i]);
    }
    
    freeStack(&stack);

    return 0;
}
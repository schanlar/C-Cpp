#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100  // Define the maximum size of the stack

/**
 * @struct stack_properties
 * @brief Structure to represent the stack properties
 * 
 * @var stack_properties::data
 * Array to store stack elements
 * 
 * @var stack_properties::top_idx
 * Index of the top element in the stack
 */
typedef struct stack_properties {
    double data[MAX_STACK_SIZE];
    int top_idx;
} STACK;

/**
 * @brief Initialize the stack and return it
 * 
 * @return STACK Initialized stack with top_idx set to -1
 */
STACK initStack(void) {
    STACK s;
    s.top_idx = -1;  // Set the initial top index to -1 indicating the stack is empty
    return s;
}

/**
 * @brief Check if the stack is empty
 * 
 * @param ps Pointer to the stack
 * @return true if the stack is empty, false otherwise
 */
bool isEmpty(const STACK* ps) {
    return ps->top_idx == -1;
}

/**
 * @brief Check if the stack is full
 * 
 * @param ps Pointer to the stack
 * @return true if the stack is full, false otherwise
 */
bool isFull(const STACK* ps) {
    return ps->top_idx == MAX_STACK_SIZE - 1;
}

/**
 * @brief Get the current size of the stack
 * 
 * @param ps Pointer to the stack
 * @return int Current size of the stack
 */
int getSize(const STACK* ps) {
    return ps->top_idx + 1;
}

/**
 * @brief Clear the stack
 * 
 * @param ps Pointer to the stack
 */
void clear(STACK* ps) {
    ps->top_idx = -1;  // Reset the top index to -1 to clear the stack
}

/**
 * @brief Peek at the top element of the stack without removing it
 * 
 * @param ps Pointer to the stack
 * @param out Pointer to store the top element
 * @return true if the stack is not empty and the top element is stored in out, false otherwise
 */
bool peek(const STACK* ps, double* out) {
    if (isEmpty(ps)) return false;  // Return false if the stack is empty
    *out = ps->data[ps->top_idx];   // Set the output parameter to the top element
    return true;
}

/**
 * @brief Push an element onto the stack
 * 
 * @param ps Pointer to the stack
 * @param num Element to push onto the stack
 * @return true if the element is successfully pushed, false if the stack is full
 */
bool push(STACK* ps, double num) {
    if (isFull(ps)) return false;   // Stack overflow, return false
    ps->data[++ps->top_idx] = num;  // Increment the top index and set the new element
    return true;
}

/**
 * @brief Pop an element from the stack
 * 
 * @param ps Pointer to the stack
 * @param out Pointer to store the popped element
 * @return true if the element is successfully popped, false if the stack is empty
 */
bool pop(STACK* ps, double* out) {
    if (isEmpty(ps)) return false;  // Stack underflow, return false
    *out = ps->data[ps->top_idx--]; // Set the output parameter to the top element and decrement the top index
    return true;
}

/**
 * @brief Convert the stack to an array
 * 
 * @param ps Pointer to the stack
 * @param out Array to store the stack elements
 * @return int Number of elements copied to the array
 */
int toArray(const STACK* ps, double* out) {
    for (int i = 0; i <= ps->top_idx; i++) {
        out[i] = ps->data[i];  // Copy elements from the stack to the output array
    }
    return ps->top_idx + 1;    // Return the number of elements copied
}

/**
 * @brief Reverse the order of elements in the stack
 * 
 * @param ps Pointer to the stack
 */
void reverse(STACK* ps) {
    int bottom_idx = 0;
    int top_idx = ps->top_idx;
    while (bottom_idx < top_idx) {
        // Swap the elements at bottom_idx and top_idx
        double tmp = ps->data[bottom_idx];
        ps->data[bottom_idx] = ps->data[top_idx];
        ps->data[top_idx] = tmp;
        bottom_idx++;
        top_idx--;
    }
}

/**
 * @brief Display the elements of the stack
 * 
 * @param ps Pointer to the stack
 */
void display(const STACK* ps) {
    printf("[\n");
    for (int i = ps->top_idx; i >= 0; i--) {
        printf(" %.3lf\n", ps->data[i]);  // Print each element of the stack
    }
    printf("]\n");
}

// Example usage
int main() {
    STACK stack = initStack();
    display(&stack);

    push(&stack, 10.5);
    push(&stack, 20.75);
    push(&stack, 30.125);
    display(&stack);

    printf("Stack contents:\n");
    double arr[MAX_STACK_SIZE];
    int size = toArray(&stack, arr);
    for (int i = 0; i < size; ++i) {
        printf("%.3f\n", arr[i]);
    }

    reverse(&stack);

    printf("Reversed stack contents:\n");
    size = toArray(&stack, arr);
    for (int i = 0; i < size; ++i) {
        printf("%.3f\n", arr[i]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define STACK_SUCCESS 0                     // Success
#define STACK_NOT_INITIALIZED -1            // Stack initialization errors
#define STACK_IS_EMPTY -2                   // Stack is empty error
#define EPSILON 1e-6                        // Tolerance level for comparing doubles

typedef struct node {
    double value;
    struct node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

typedef struct stack {
    LinkedList* list;
    size_t size;
} Stack;

/**
 * @brief Safe memory allocation with error checking.
 * 
 * @param size Size of memory to allocate.
 * @return Pointer to allocated memory.
 */
void* safeMalloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

/**
 * @brief Compare two double values with a small tolerance.
 * 
 * @param a Pointer to the first double.
 * @param b Pointer to the second double.
 * @return 0 if equal, 1 if a > b, -1 if a < b.
 */
int compareDoubles(const void* a, const void* b) {
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;
    double diff = fabs(arg1 - arg2);
    if (diff <= EPSILON) return 0;
    if (arg1 > arg2) return 1;
    return -1;
}

/**
 * @brief Create a new node with the given value.
 * 
 * @param value Value to store in the node.
 * @return Pointer to the newly created node.
 */
Node* createNode(double value) {
    Node* pNewNode = (Node*)safeMalloc(sizeof(Node));
    pNewNode->value = value;
    pNewNode->next = NULL;
    return pNewNode;
}

/**
 * @brief Create an empty linked list.
 * 
 * @return Pointer to the newly created linked list.
 */
LinkedList* createLinkedList(void) {
    LinkedList* pl = (LinkedList*)safeMalloc(sizeof(LinkedList));
    pl->head = NULL;
    return pl;
}

/**
 * @brief Create an empty stack.
 * 
 * @return Pointer to the newly created stack.
 */
Stack* createStack(void) {
    Stack* ps = (Stack*)safeMalloc(sizeof(Stack));
    ps->list = createLinkedList();
    ps->size = 0;
    return ps;
}

/**
 * @brief Check if the stack is empty.
 * 
 * @param ps Pointer to the stack.
 * @return True if the stack is empty, false otherwise.
 */
bool isStackEmpty(Stack* ps) {
    return ps->size == 0;
}

/**
 * @brief Clear the stack by freeing all nodes.
 * 
 * @param ps Pointer to the stack.
 */
void clearStack(Stack* ps) {
    if (!ps) {
        fprintf(stderr, "Stack not initialized\n");
        return;
    }

    Node* pCurrentNode = ps->list->head;
    Node* pNextNode = NULL;

    // Iterate through the list and free each node
    while (pCurrentNode != NULL) {
        pNextNode = pCurrentNode->next;
        free(pCurrentNode);
        pCurrentNode = pNextNode;
    }

    ps->list->head = NULL;
    ps->size = 0;
}

/**
 * @brief Push a value onto the stack.
 * 
 * @param ps Pointer to the stack.
 * @param num Value to push.
 * @return Status code indicating success or failure.
 */
int pushToStack(Stack* ps, double num) {
    if (!ps) return STACK_NOT_INITIALIZED;

    Node* pNewNode = createNode(num);
    Node* pCurrentNode = ps->list->head;

    pNewNode->next = pCurrentNode;
    ps->list->head = pNewNode;

    ps->size++;

    return STACK_SUCCESS;
}

/**
 * @brief Get the value at the top of the stack without removing it.
 * 
 * @param ps Pointer to the stack.
 * @param out Pointer to store the value at the top of the stack.
 * @return Status code indicating success or failure.
 */
int peekStack(Stack* ps, double* out) {
    if (!ps) return STACK_NOT_INITIALIZED;

    if (isStackEmpty(ps)) return STACK_IS_EMPTY;

    Node* pFirstNode = ps->list->head;
    *out = pFirstNode->value;

    return STACK_SUCCESS;
}

/**
 * @brief Pop a value from the top of the stack.
 * 
 * @param ps Pointer to the stack.
 * @param out Pointer to store the popped value.
 * @return Status code indicating success or failure.
 */
int popFromStack(Stack* ps, double* out) {
    if (!ps) return STACK_NOT_INITIALIZED;
    if (isStackEmpty(ps)) return STACK_IS_EMPTY;

    Node* pFirstNode = ps->list->head;

    *out = pFirstNode->value;
    ps->list->head = pFirstNode->next;

    free(pFirstNode);

    ps->size--;

    return STACK_SUCCESS;
}

/**
 * @brief Convert the stack to an array of values.
 * 
 * @param ps Pointer to the stack.
 * @return Pointer to the array of values or NULL if stack is empty or not initialized.
 */
double* stackToArray(Stack* ps) {
    if (!ps) return NULL;
    if (isStackEmpty(ps)) return NULL;

    unsigned int idx = 0;
    double* out = (double*)safeMalloc(sizeof(double) * ps->size);

    Node* pCurrentNode = ps->list->head;
    
    // Traverse the stack and store each value in the array
    while (pCurrentNode != NULL) {
        out[idx++] = pCurrentNode->value;
        pCurrentNode = pCurrentNode->next;
    }

    return out;
}
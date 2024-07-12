#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define QUEUE_SUCCESS 0                     // Success
#define QUEUE_NOT_INITIALIZED -1            // Queue initialization errors
#define QUEUE_IS_EMPTY -2                   // Queue is empty error
#define EPSILON 1e-6                        // Tolerance level for comparing doubles

typedef struct node {
    double value;
    struct node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

typedef struct queue {
    LinkedList* list;
    size_t size;
} Queue;

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
    pl->tail = NULL; 
    return pl;
}

/**
 * @brief Create an empty queue.
 * 
 * @return Pointer to the newly created queue.
 */
Queue* createQueue(void) {
    Queue* pq = (Queue*)safeMalloc(sizeof(Queue));
    pq->list = createLinkedList();
    pq->size = 0;
    return pq;
}

/**
 * @brief Check if the queue is empty.
 * 
 * @param pq Pointer to the queue.
 * @return True if the queue is empty, false otherwise.
 */
bool isQueueEmpty(Queue* pq) {
    return pq->size == 0;
}

/**
 * @brief Peek at the front value of the queue.
 * 
 * @param pq Pointer to the queue.
 * @param out Pointer to the variable where the value will be stored.
 * @return Status code indicating success or failure.
 */
int peekQueue(Queue* pq, double* out) {
    if (!pq) return QUEUE_NOT_INITIALIZED;
    if (isQueueEmpty(pq)) return QUEUE_IS_EMPTY;

    *out = pq->list->head->value;
    return QUEUE_SUCCESS;
}

/**
 * @brief Add a value to the end of the queue.
 * 
 * @param pq Pointer to the queue.
 * @param num Value to add to the queue.
 * @return Status code indicating success or failure.
 */
int enqueue(Queue* pq, double num) {
    if (!pq) return QUEUE_NOT_INITIALIZED; 

    Node* pNewNode = createNode(num);

    // If the queue is not empty, link the new node to the end of the list
    if (pq->list->tail) 
    {
        pq->list->tail->next = pNewNode;  // Set the next of the current tail to the new node
    } 
    else // If the queue is empty, set the head to the new node
    {
        
        pq->list->head = pNewNode;        // This is the first node, so it's both head and tail
    }
    
    // Update the tail pointer to the new node
    pq->list->tail = pNewNode;            // New node is now the last node in the list

    // Increment the size of the queue
    pq->size++;                          

    return QUEUE_SUCCESS;
}

/**
 * @brief Remove a value from the front of the queue.
 * 
 * @param pq Pointer to the queue.
 * @param out Pointer to the variable where the value will be stored.
 * @return Status code indicating success or failure.
 */
int dequeue(Queue* pq, double* out) {
    if (!pq) return QUEUE_NOT_INITIALIZED;
    if (isQueueEmpty(pq)) return QUEUE_IS_EMPTY;

    Node* pFirstNode = pq->list->head;
    *out = pFirstNode->value;
    pq->list->head = pFirstNode->next;

    if (pq->list->head == NULL) {
        pq->list->tail = NULL;
    }

    free(pFirstNode);
    pq->size--;

    return QUEUE_SUCCESS;
}

/**
 * @brief Clear the queue.
 * 
 * @param pq Pointer to the queue.
 */
void clearQueue(Queue* pq) {
    if (!pq) return;

    Node* pCurrentNode = pq->list->head;
    Node* pNextNode = NULL;

    while (pCurrentNode != NULL) {
        pNextNode = pCurrentNode->next;
        free(pCurrentNode);
        pCurrentNode = pNextNode;
    }
    pq->list->head = NULL;
    pq->list->tail = NULL;
    pq->size = 0;
}
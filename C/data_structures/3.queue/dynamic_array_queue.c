#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUEUE_SUCCESS 1
#define QUEUE_ERROR_NOT_INITIALIZED -1
#define QUEUE_ERROR_FULL -2 
#define QUEUE_ERROR_EMPTY -3 

/**
 * Queue structure definition.
 * - items: Dynamic array to store queue elements.
 * - capacity: Total capacity of the queue.
 * - front: Index of the front element.
 * - rear: Index of the rear element.
 * - size: Current number of elements in the queue.
 */
typedef struct queue {
    double* items;
    size_t capacity;
    size_t front;
    size_t rear;
    size_t size;
} QUEUE;

/**
 * Safely allocates memory and exits on failure.
 * @param size The size of memory to allocate.
 * @return Pointer to the allocated memory.
 */
void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/**
 * Safely reallocates memory and exits on failure.
 * @param ptr Pointer to the existing memory block.
 * @param size The new size of memory to allocate.
 * @return Pointer to the reallocated memory.
 */
void* safe_realloc(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    if (!new_ptr) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

/**
 * Initializes a new queue.
 * @param size Initial capacity of the queue.
 * @return A new QUEUE with initialized fields.
 */
QUEUE initQueue(size_t size) {
    QUEUE q;
    q.items = safe_malloc(sizeof(double) * size);
    q.capacity = size;
    q.front = 0;
    q.rear = size - 1;
    q.size = 0;
    return q;
}

/**
 * Checks if the queue is initialized.
 * @param pq Pointer to the QUEUE to check.
 * @return QUEUE_SUCCESS if initialized, otherwise QUEUE_ERROR_NOT_INITIALIZED.
 */
int isInitialized(const QUEUE* pq) {
    return (pq && pq->items) ? QUEUE_SUCCESS : QUEUE_ERROR_NOT_INITIALIZED;
}

/**
 * Frees the queue's resources.
 * @param pq Pointer to the QUEUE to free.
 */
void freeQueue(QUEUE* pq) {
    if (isInitialized(pq) == QUEUE_SUCCESS) {
        free(pq->items);
        pq->items = NULL;
        pq->capacity = 0;
        pq->front = 0;
        pq->rear = 0;
        pq->size = 0;
    }
}

/**
 * Checks if the queue is empty.
 * @param pq Pointer to the QUEUE to check.
 * @return 1 if the queue is empty, otherwise 0.
 */
int isEmpty(const QUEUE* pq) {
    if (isInitialized(pq) != QUEUE_SUCCESS) return QUEUE_ERROR_NOT_INITIALIZED;
    return pq->size == 0;
}

/**
 * Checks if the queue is full.
 * @param pq Pointer to the QUEUE to check.
 * @return 1 if the queue is full, otherwise 0.
 */
int isFull(const QUEUE* pq) {
    if (isInitialized(pq) != QUEUE_SUCCESS) return QUEUE_ERROR_NOT_INITIALIZED;
    return pq->size == pq->capacity;
}

/**
 * Clears the queue.
 * @param pq Pointer to the QUEUE to clear.
 * @return QUEUE_SUCCESS if cleared successfully.
 */
int clear(QUEUE* pq) {
    if (isInitialized(pq) != QUEUE_SUCCESS) return QUEUE_ERROR_NOT_INITIALIZED;
    pq->front = 0;
    pq->rear = pq->capacity - 1;
    pq->size = 0;
    return QUEUE_SUCCESS;
}

/**
 * Resizes the queue to a new capacity.
 * @param pq Pointer to the QUEUE to resize.
 * @param size The new capacity.
 * @return QUEUE_SUCCESS if resized successfully.
 */
int resize(QUEUE* pq, size_t size) {
    if (isInitialized(pq) != QUEUE_SUCCESS) return QUEUE_ERROR_NOT_INITIALIZED;
    pq->items = (double*) safe_realloc(pq->items, sizeof(double) * size);
    pq->capacity = size;
    return QUEUE_SUCCESS;
}

/**
 * Peeks at the front element of the queue without removing it.
 * @param pq Pointer to the QUEUE to peek.
 * @param out Pointer to store the front element.
 * @return QUEUE_SUCCESS if successful, otherwise error code.
 */
int peek(QUEUE* pq, double* out) {
    if (isInitialized(pq) != QUEUE_SUCCESS) return QUEUE_ERROR_NOT_INITIALIZED;
    if (isEmpty(pq)) {
        *out = 0; // Initialize out to a known value
        return QUEUE_ERROR_EMPTY;
    }
    *out = pq->items[pq->front];
    return QUEUE_SUCCESS;
}

/**
 * Adds an element to the rear of the queue.
 * @param pq Pointer to the QUEUE to add to.
 * @param num The element to add.
 * @return QUEUE_SUCCESS if successful, otherwise error code.
 */
int enqueue(QUEUE* pq, double num) {
    if (isInitialized(pq) != QUEUE_SUCCESS) return QUEUE_ERROR_NOT_INITIALIZED;
    if (isFull(pq)) {
        resize(pq, pq->capacity * 2);
    }
    pq->rear = (pq->rear + 1) % pq->capacity;
    pq->items[pq->rear] = num;
    pq->size++;
    if (pq->size == 1) pq->front = pq->rear; // Correct initialization of front
    return QUEUE_SUCCESS;
}

/**
 * Removes an element from the front of the queue.
 * @param pq Pointer to the QUEUE to remove from.
 * @param out Pointer to store the removed element.
 * @return QUEUE_SUCCESS if successful, otherwise error code.
 */
int dequeue(QUEUE* pq, double* out) {
    if (isInitialized(pq) != QUEUE_SUCCESS) return QUEUE_ERROR_NOT_INITIALIZED;
    if (isEmpty(pq)) {
        *out = 0;
        return QUEUE_ERROR_EMPTY;
    }
    *out = pq->items[pq->front];
    pq->front = (pq->front + 1) % pq->capacity;
    pq->size--;
    if (pq->size == 0) {
        clear(pq);
    }
    return QUEUE_SUCCESS;
}

/**
 * Displays the status of the queue.
 * @param pq Pointer to the QUEUE to display.
 */
void status(const QUEUE* pq) {
    int bar_length = 100;
    printf("CAPACITY: %zu; SIZE: %zu; POSITION OF FRONT ELEMENT: %zu; POSITION OF REAR ELEMENT: %zu\n",
           pq->capacity, pq->size, pq->front, pq->rear);
    for (int i = 0; i <= bar_length; i++) {
        (i < bar_length) ? printf("-") : printf("\n");
    }
}

/**
 * Displays the elements of the queue.
 * @param pq Pointer to the QUEUE to display.
 */
void display(const QUEUE* pq) {
    printf("[\n");
    if (isEmpty(pq)) {
        printf("]\n");
        return;
    }
    for (size_t i = 0; i < pq->size; i++) {
        size_t idx = (pq->front + i) % pq->capacity;
        printf(" %.1lf\n", pq->items[idx]);
    }
    printf("]\n");
}

int main(void) {
    srand(time(NULL));
    QUEUE q = initQueue(4);
    display(&q);
    status(&q);

    double peeked_val;
    if (peek(&q, &peeked_val) == QUEUE_SUCCESS) {
        printf("Peeked value: %.1f\n", peeked_val);
    } else {
        printf("Peek failed: Queue is empty.\n");
    }

    enqueue(&q, 1);
    display(&q);
    status(&q);
    enqueue(&q, 2);
    display(&q);
    status(&q);
    enqueue(&q, 3);
    display(&q);
    status(&q);

    // Attempt to enqueue more elements than the queue can hold
    for (int i = 4; i < 102; i++) {
        if (enqueue(&q, i) != QUEUE_SUCCESS) {
            printf("Failed to enqueue %d: Queue is full.\n", i);
            break; // Stop enqueuing when the queue is full
        }
    }
    display(&q);
    status(&q);

    if (peek(&q, &peeked_val) == QUEUE_SUCCESS) {
        printf("Peeked value: %.1f\n", peeked_val);
    } else {
        printf("Peek failed: Queue is empty.\n");
    }

    double xnum;
    if (dequeue(&q, &xnum) == QUEUE_SUCCESS) {
        printf("Dequeued: %.1lf\n", xnum);
    } else {
        printf("Dequeue failed: Queue is empty.\n");
    }
    display(&q);
    status(&q);

    if (dequeue(&q, &xnum) == QUEUE_SUCCESS) {
        printf("Dequeued: %.1lf\n", xnum);
    } else {
        printf("Dequeue failed: Queue is empty.\n");
    }
    display(&q);
    status(&q);

    enqueue(&q, 113);
    display(&q);
    status(&q);

    freeQueue(&q);  // Make sure to free allocated memory
    return 0;
}
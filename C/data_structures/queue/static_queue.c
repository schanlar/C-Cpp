#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100 

/**
 * Queue structure definition.
 * - items: Array to store queue elements.
 * - front: Index of the front element.
 * - rear: Index of the rear element.
 * - size: Current number of elements in the queue.
 */
typedef struct queue {
    double items[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} QUEUE;

/**
 * Initializes a new queue.
 * @return A new QUEUE with front, rear set to -1 and size set to 0.
 */
QUEUE initQueue(void) {
    QUEUE q;
    q.front = -1;
    q.rear = -1;
    q.size = 0;
    return q;
}

/**
 * Clears the queue.
 * @param pq Pointer to the QUEUE to be cleared.
 */
void clear(QUEUE* pq) {
    pq->front = -1;
    pq->rear = -1;
    pq->size = 0;
}

/**
 * Checks if the queue is empty.
 * @param pq Pointer to the QUEUE to be checked.
 * @return true if the queue is empty, false otherwise.
 */
bool isEmpty(const QUEUE* pq) {
    return (pq->size == 0);
}

/**
 * Checks if the queue is full.
 * @param pq Pointer to the QUEUE to be checked.
 * @return true if the queue is full, false otherwise.
 */
bool isFull(const QUEUE* pq) {
    return (pq->size == MAX_QUEUE_SIZE);
}

/**
 * Peeks at the front element of the queue without removing it.
 * @param pq Pointer to the QUEUE to be peeked.
 * @param out Pointer to store the front element.
 * @return true if the operation is successful, false if the queue is empty.
 */
bool peek(const QUEUE* pq, double* out) {
    if (isEmpty(pq)) {
        *out = 0; // Initialize out to a known value
        return false;
    }
    *out = pq->items[pq->front];
    return true;
}

/**
 * Adds an element to the rear of the queue.
 * @param pq Pointer to the QUEUE to be modified.
 * @param num The element to be added.
 * @return true if the operation is successful, false if the queue is full.
 */
bool enqueue(QUEUE* pq, double num) {
    if (isFull(pq)) return false;
    // Update the rear index, wrapping around if necessary
    pq->rear = (pq->rear + 1) % MAX_QUEUE_SIZE;
    pq->items[pq->rear] = num;
    pq->size++;
    if (pq->size == 1) pq->front = pq->rear; // Correct initialization of front
    return true;
}

/**
 * Removes an element from the front of the queue.
 * @param pq Pointer to the QUEUE to be modified.
 * @param out Pointer to store the removed element.
 * @return true if the operation is successful, false if the queue is empty.
 */
bool dequeue(QUEUE* pq, double* out) {
    if (isEmpty(pq)) {
        *out = 0; // Initialize out to a known value
        return false;
    }
    *out = pq->items[pq->front];
    // Update the front index, wrapping around if necessary
    pq->front = (pq->front + 1) % MAX_QUEUE_SIZE; 
    pq->size--;
    if (pq->size == 0) {
        pq->front = -1;
        pq->rear = -1;
    }
    return true;
}

/**
 * Displays the elements of the queue.
 * @param pq Pointer to the QUEUE to be displayed.
 */
void display(const QUEUE* pq) {
    printf("[\n");
    if (isEmpty(pq)) {
        printf("]\n");
        return;
    }
    for (int i = 0; i < pq->size; i++) {
        int idx = (pq->front + i) % MAX_QUEUE_SIZE;
        printf(" %.1lf\n", pq->items[idx]);
    }
    printf("]\n");
}

/**
 * Displays the status of the queue.
 * @param pq Pointer to the QUEUE to be checked.
 */
void status(const QUEUE* pq) {
    int bar_length = 100;
    printf("CAPACITY: %d; SIZE: %d; POSITION OF FRONT ELEMENT: %d; POSITION OF REAR ELEMENT: %d\n",
        MAX_QUEUE_SIZE, pq->size, pq->front, pq->rear);
    for (int i = 0; i <= bar_length; i++) {
        (i < bar_length) ? printf("-") : printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    QUEUE q = initQueue();
    display(&q);
    status(&q);

    double peeked_val;
    if (peek(&q, &peeked_val)) {
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
        if (!enqueue(&q, i)) {
            printf("Failed to enqueue %d: Queue is full.\n", i);
            break; // Stop enqueuing when the queue is full
        }
    }
    display(&q);
    status(&q);

    if (peek(&q, &peeked_val)) {
        printf("Peeked value: %.1f\n", peeked_val);
    } else {
        printf("Peek failed: Queue is empty.\n");
    }

    double xnum;
    if (dequeue(&q, &xnum)) {
        printf("Dequeued: %.1lf\n", xnum);
    } else {
        printf("Dequeue failed: Queue is empty.\n");
    }
    display(&q);
    status(&q);

    if (dequeue(&q, &xnum)) {
        printf("Dequeued: %.1lf\n", xnum);
    } else {
        printf("Dequeue failed: Queue is empty.\n");
    }
    display(&q);
    status(&q);

    enqueue(&q, 113);
    display(&q);
    status(&q);

    return 0;
}
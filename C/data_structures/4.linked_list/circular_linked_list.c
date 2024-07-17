#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIST_NOT_INITIALIZED -1
#define LIST_IS_EMPTY -2
#define LIST_INVALID_POSITION -3
#define NODE_NOT_FOUND -4
#define MEMORY_ALLOCATION_ERROR -5
#define LIST_SUCCESS 10
#define EPSILON 1e-6


typedef struct node
{
    double value;
    struct node* next;
    struct node* prev;
} Node;


typedef struct LinkedList 
{
    Node* head;
    Node* tail;
    size_t size;
} LinkedList;


void* safeMalloc(size_t size)
{
    void* ptr = malloc(size);
    if (!ptr)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}


int compareDoubles(const void* a, const void* b)
{
    double arg1 = *(const double*) a;
    double arg2 = *(const double*) b;
    double diff = fabs(arg1 - arg2);
    if (diff <= EPSILON) return 0;
    if (arg1 > arg2) return 1;
    return -1;
}


Node* createNode(double value)
{
    Node* pNewNode = (Node*) safeMalloc(sizeof(Node));
    pNewNode -> value = value;
    pNewNode -> next = pNewNode; // Points to itself to make it cyclic initially
    pNewNode -> prev = pNewNode; // Points to itself to make it cyclic initially
    return pNewNode;
}


LinkedList* createLinkedList(void)
{
    LinkedList* pl = (LinkedList*) safeMalloc(sizeof(LinkedList));
    pl -> head = NULL;
    pl -> tail = NULL;
    pl -> size = 0;
    return pl;
}


bool isLinkedListEmpty(LinkedList* pl)
{
    return pl -> size == 0;
}


int insertAtBeginning(LinkedList* pl, double num)
{
    if (!pl) return LIST_NOT_INITIALIZED;

    Node* pNewNode = createNode(num);
    if (isLinkedListEmpty(pl))
    {
        // If the list is empty, initialize the head and tail to the new node
        pl -> head = pNewNode;
        pl -> tail = pNewNode;
        
    }
    else
    {
        // If the list is not empty, insert the new node at the beginning
        Node* pCurrentHeadNode = pl -> head;

        pNewNode -> next = pCurrentHeadNode;    // Point the new node's next to the current head
        pNewNode -> prev = pl -> tail;          // Point the new node's prev to the tail

        // Adjust the pointers for the surrounding nodes
        pCurrentHeadNode -> prev = pNewNode;    // Update the current head's prev to the new node
        pl -> tail -> next = pNewNode;          // Update the tail's next to the new node
        pl -> head = pNewNode;                  // Update the head to the new node
    }

    pl -> size++;
    return LIST_SUCCESS;
}


int insertAtEnd(LinkedList* pl, double num)
{
    if (!pl) return LIST_NOT_INITIALIZED;

    Node* pNewNode = createNode(num);
    
    if (isLinkedListEmpty(pl))
    {
        pl -> head = pNewNode;
        pl -> tail = pNewNode;
    }
    else
    {
        Node* pCurrentTailNode = pl -> tail;

        pNewNode -> next = pl -> head;
        pNewNode -> prev = pCurrentTailNode;

        pCurrentTailNode -> next = pNewNode;
        pl -> head -> prev = pNewNode;
        pl -> tail = pNewNode;
    }

    pl -> size++;
    return LIST_SUCCESS;
}


int insertAtPosition(LinkedList* pl, double num, unsigned int position)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (position > pl -> size) return LIST_INVALID_POSITION;

    if (isLinkedListEmpty(pl))
    {
        if (position > 0) return LIST_INVALID_POSITION;

        return insertAtBeginning(pl, num);
    }

    if (position == pl -> size) return insertAtEnd(pl, num);

    Node* pNewNode = createNode(num);
    Node* pCurrentNode = pl -> head;

    for (unsigned int idx = 0; idx < position; idx++)
    {
        pCurrentNode = pCurrentNode -> next;
    }

    Node* pNextNode = pCurrentNode -> next;

    pNewNode -> next = pNextNode;
    pNewNode -> prev = pCurrentNode;

    pCurrentNode -> next = pNewNode;
    pNextNode -> prev = pNewNode;

    pl -> size++;

    return LIST_SUCCESS;
}


int deleteFirstNode(LinkedList* pl)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;

    Node* pCurrentHeadNode = pl -> head;

    if (pl -> size == 1)
    {
        pl -> head = NULL;
        pl -> tail = NULL;
    }
    else
    {
        pCurrentHeadNode -> next -> prev = pl -> tail;
        pl -> tail -> next = pCurrentHeadNode -> next;
        pl -> head = pCurrentHeadNode -> next;
    }
    
    free(pCurrentHeadNode);

    pl -> size--;

    return LIST_SUCCESS;
}


int deleteLastNode(LinkedList* pl)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;

    Node* pCurrentTailNode = pl -> tail;

    if (pl -> size == 1)
    {
        pl -> head = NULL;
        pl -> tail = NULL;
    }
    else 
    {
        pCurrentTailNode -> prev -> next = pl -> head;
        pl -> head -> prev = pCurrentTailNode -> prev;
        pl -> tail = pCurrentTailNode -> prev;
    }

    free(pCurrentTailNode);

    pl -> size--;

    return LIST_SUCCESS;
}


int deleteNodeAtPosition(LinkedList* pl, unsigned int position)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;
    if (position >= pl -> size) return LIST_INVALID_POSITION;

    if (position == 0) return deleteFirstNode(pl);
    if (position == pl -> size - 1) return deleteLastNode(pl);

    Node* pCurrentNode = pl -> head;
    for (unsigned int i = 0; i < position; i++)
    {
        pCurrentNode = pCurrentNode -> next;
    }

    pCurrentNode -> prev -> next = pCurrentNode -> next;
    pCurrentNode -> next -> prev = pCurrentNode -> prev;

    free(pCurrentNode);

    pl -> size--;

    return LIST_SUCCESS;
}


int deleteNodeWithKey(LinkedList* pl, double key, bool deleteAll)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;

    size_t idx = 0;
    bool nodeFound = false;
    Node* pCurrentNode = pl -> head;
    Node* pNextNode = NULL;

    while (idx < pl -> size)
    {
        if (compareDoubles(&pCurrentNode -> value, &key) == 0)
        {
            nodeFound = true;

            pNextNode = pCurrentNode -> next;

            pCurrentNode -> prev -> next = pNextNode;
            pNextNode -> prev = pCurrentNode -> prev;

            if (pCurrentNode == pl -> head) pl -> head = pNextNode;
            if (pCurrentNode == pl -> tail) pl -> tail = pCurrentNode -> prev;

            free(pCurrentNode);

            pCurrentNode = pNextNode;

            pl -> size--;

            if (!deleteAll) break;
        }
        else 
        {
            pCurrentNode = pCurrentNode -> next;
        }
        idx++;
    }

    if (!nodeFound) return NODE_NOT_FOUND;

    return LIST_SUCCESS;
}


int deleteLinkedList(LinkedList* pl)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;

    Node* pCurrentNode = pl -> head;
    Node* pNextNode = NULL;

    for (size_t idx = 0; idx < pl -> size; idx++)
    {
        pNextNode = pCurrentNode -> next;
        free(pCurrentNode);
        pCurrentNode = pNextNode;
    }
    pl -> head = NULL;
    pl -> tail = NULL;
    pl -> size = 0;

    return LIST_SUCCESS;
}

void deallocate(LinkedList* pl)
{
    if (!pl) return;

    int deleteResult = deleteLinkedList(pl);
    if (deleteResult != LIST_SUCCESS)
    {
        fprintf(stderr, "Error deleting linked list: %d\n", deleteResult);
        return;
    }

    free(pl);
}


int findNodeWithKey(LinkedList* pl, double key, Node** out, bool stopAtFirst) {
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;

    Node* pCurrentNode = pl -> head;
    bool nodeFound = false;
    unsigned int foundCount = 0;

    for (unsigned int i = 0; i < pl -> size; i++) {
        if (compareDoubles(&pCurrentNode -> value, &key) == 0) {
            nodeFound = true;
            out[foundCount++] = pCurrentNode;

            if (stopAtFirst) {
                return LIST_SUCCESS;
            }
        }
        pCurrentNode = pCurrentNode -> next;
    }

    if (!nodeFound) {
        *out = NULL;
        return NODE_NOT_FOUND;
    }
    return LIST_SUCCESS;
}


int mergeLinkedList(LinkedList* pla, LinkedList* plb) {
    if (!pla || !plb) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pla) || isLinkedListEmpty(plb)) return LIST_IS_EMPTY;

    // Update the connections to merge plb into pla
    pla->tail->next = plb->head;
    plb->head->prev = pla->tail;
    pla->head->prev = plb->tail;
    plb->tail->next = pla->head;

    // Update the size of pla
    pla->size += plb->size;

    // Reset plb to an empty list
    plb->head = NULL;
    plb->tail = NULL;
    plb->size = 0;

    return LIST_SUCCESS;
}


int copyLinkedList(LinkedList* pl, LinkedList** copy) {
    if (!pl) return LIST_NOT_INITIALIZED;
    if (!copy) return LIST_NOT_INITIALIZED;

    if (isLinkedListEmpty(pl)) {
        *copy = createLinkedList();
        return LIST_SUCCESS;
    }

    *copy = createLinkedList();
    if (!(*copy)) return MEMORY_ALLOCATION_ERROR;

    Node* currentOriginalNode = pl->head;

    // Create the first node for the copy
    Node* newNode = createNode(currentOriginalNode->value);

    (*copy)->head = newNode;
    (*copy)->tail = newNode;

    // Iterate through the original list and create new nodes for the copy
    currentOriginalNode = currentOriginalNode->next;
    while (currentOriginalNode != pl->head) {
        Node* newNode = createNode(currentOriginalNode->value);

        newNode->prev = (*copy)->tail;
        (*copy)->tail->next = newNode;
        (*copy)->tail = newNode;
        currentOriginalNode = currentOriginalNode->next;
    }

    // Complete the circular link
    (*copy)->head->prev = (*copy)->tail;
    (*copy)->tail->next = (*copy)->head;
    (*copy)->size = pl->size;

    return LIST_SUCCESS;
}


int reverseLinkedList(LinkedList* pl, LinkedList** reversed) {
    if (!pl) return LIST_NOT_INITIALIZED;
    if (!reversed) return LIST_NOT_INITIALIZED;

    if (isLinkedListEmpty(pl)) {
        *reversed = createLinkedList();
        return LIST_SUCCESS;
    }

    *reversed = createLinkedList();
    if (!(*reversed)) return MEMORY_ALLOCATION_ERROR;

    Node* currentOriginalNode = pl->tail;

    // Create the first node for the reversed list
    Node* newNode = createNode(currentOriginalNode->value);

    (*reversed)->head = newNode;
    (*reversed)->tail = newNode;

    // Iterate through the original list and create new nodes for the reversed list
    currentOriginalNode = currentOriginalNode->prev;
    while (currentOriginalNode != pl->tail) {
        Node* newNode = createNode(currentOriginalNode->value);

        newNode->prev = (*reversed)->tail;
        (*reversed)->tail->next = newNode;
        (*reversed)->tail = newNode;
        currentOriginalNode = currentOriginalNode->prev;
    }

    // Complete the circular link
    (*reversed)->head->prev = (*reversed)->tail;
    (*reversed)->tail->next = (*reversed)->head;
    (*reversed)->size = pl->size;

    return LIST_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


#define LIST_SUCCESS 0                     // Success
#define LIST_NOT_INITIALIZED -1            // List initialization errors
#define LIST_IS_EMPTY -2
#define LIST_IS_NOT_EMPTY -3
#define LIST_POSITION_INVALID -10          // Position-related errors
#define NODE_NOT_FOUND -20                 // Node-related errors
#define LIST_MEMORY_ERROR -30              // Memory errors
#define EPSILON 1e-6

/** STRUCTURE DEFINITIONS 
=========================
*/

// Structure of a node
typedef struct node 
{
    double value;
    struct node* next;
    struct node* prev;
} Node;


// Structure of linked list
typedef struct LinkedList 
{
    unsigned int size;
    Node* head;
    Node* tail;
} LinkedList;

/* ======================================================== */

/** INITIALIZATION FUNCTIONS 
============================
*/

/**
 * createNode - Create a node with a specific value.
 * @value: The value to be stored in the node.
 * 
 * Returns:
 *  - A pointer to the newly created node.
 * 
 * Logic:
 *  - Allocate memory for the new node.
 *  - Initialize the node with the given value and set the next and prev pointers to NULL.
 */
Node* createNode(double value)
{
    Node* pNewNode = (Node*) safeMalloc(sizeof(Node));
    pNewNode -> value = value;
    pNewNode -> next = NULL;
    pNewNode -> prev = NULL;
    return pNewNode;
}

/**
 * createLinkedList - Create an empty linked list.
 * 
 * Returns:
 *  - A pointer to the newly created linked list.
 * 
 * Logic:
 *  - Allocate memory for the linked list.
 *  - Initialize the size to 0 and head and tail pointers to NULL.
 */
LinkedList* createLinkedList(void)
{
    LinkedList* pl = (LinkedList*) safeMalloc(sizeof(LinkedList));
    pl -> size = 0;
    pl -> head = NULL;
    pl -> tail = NULL;
    return pl;
}

/* ======================================================== */

/** MISCELLANEOUS FUNCTIONS 
===========================
*/

/**
 * safeMalloc - Allocate memory and handle allocation failure.
 * @size: Size of the memory block to be allocated.
 * 
 * Returns:
 *  - A pointer to the allocated memory block.
 * 
 * Logic:
 *  - Allocate memory of the given size.
 *  - If allocation fails, print an error message and exit.
 *  - Return the allocated memory pointer.
 */
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

/**
 * compareDoubles - Compare two double values within a tolerance level.
 * @a: Pointer to the first double value.
 * @b: Pointer to the second double value.
 * 
 * Returns:
 *  - 0 if the values are equal within the tolerance level.
 *  - 1 if the first value is greater than the second.
 *  - -1 if the first value is less than the second.
 * 
 * Logic:
 *  - Calculate the absolute difference between the two values.
 *  - Compare the difference with EPSILON to determine equality.
 *  - Return 0, 1, or -1 based on the comparison.
 */
int compareDoubles(const void* a, const void* b)
{
    double arg1 = *(const double*) a;
    double arg2 = *(const double*) b;
    double diff = fabs(arg1 - arg2);
    if (diff <= EPSILON) return 0;
    if (arg1 > arg2) return 1;
    return -1;
}

/* ======================================================== */

/** UTILITY FUNCTIONS 
=====================
*/

/**
 * displayList - Display the values in the linked list.
 * @pl: Pointer to the linked list.
 * 
 * Logic:
 *  - Traverse the linked list.
 *  - Print the value of each node followed by an arrow.
 *  - Print "NULL" at the end to indicate the end of the list.
 */
void displayList(LinkedList* pl)
{
    if (!pl) {
        printf("List not initialized.\n");
        return;
    }
    if (isLinkedListEmpty(pl)) {
        printf("List is empty.\n");
        return;
    }

    Node* pCurrentNode = pl -> head;

    while (pCurrentNode != NULL) {
        printf("%.1lf -> ", pCurrentNode -> value);
        pCurrentNode = pCurrentNode -> next;
    }
    printf("NULL\n");
}

/**
 * isLinkedListEmpty - Check if the linked list is empty.
 * @pl: Pointer to the linked list.
 * 
 * Returns:
 *  - true if the list is empty; otherwise, false.
 * 
 * Logic:
 *  - Check if the head and tail pointers are NULL.
 */
bool isLinkedListEmpty(LinkedList* pl)
{
    return (pl -> head == NULL && pl -> tail == NULL);
}

/* ======================================================== */

/** INSERTION OPERATIONS 
==========================
*/

/**
 * insertAtBeginning - Insert a node at the beginning of the linked list.
 * @pl: Pointer to the linked list.
 * @value: The value to be inserted.
 * 
 * Returns:
 *  - LIST_SUCCESS if the insertion is successful.
 *  - LIST_NOT_INITIALIZED if the linked list is not initialized.
 * 
 * Logic:
 *  - Create a new node with the given value.
 *  - If the list is empty, set head and tail to the new node.
 *  - Otherwise, update head and the previous pointer of the current head.
 */
int insertAtBeginning(LinkedList* pl, double value) {
    if (!pl) return LIST_NOT_INITIALIZED;

    Node* pNewNode = createNode(value);

    if (isLinkedListEmpty(pl)) 
    {
        pl -> head = pNewNode;
        pl -> tail = pNewNode;
    } 
    else 
    {
        Node* pCurrentNode = pl -> head;

        pCurrentNode -> prev = pNewNode;
        pNewNode -> next = pCurrentNode;
        pl -> head = pNewNode;
    }
    pl -> size++;

    return LIST_SUCCESS;
}

/**
 * insertAtEnd - Insert a node at the end of the linked list.
 * @pl: Pointer to the linked list.
 * @value: The value to be inserted.
 * 
 * Returns:
 *  - LIST_SUCCESS if the insertion is successful.
 *  - LIST_NOT_INITIALIZED if the linked list is not initialized.
 * 
 * Logic:
 *  - Create a new node with the given value.
 *  - If the list is empty, set head and tail to the new node.
 *  - Otherwise, update tail and the next pointer of the current tail.
 */
int insertAtEnd(LinkedList* pl, double value)
{
    if (!pl) return LIST_NOT_INITIALIZED;

    Node* pNewNode = createNode(value);

    if (isLinkedListEmpty(pl))
    {
        pl -> head = pNewNode;
        pl -> tail = pNewNode;
    } 
    else 
    {
        Node* pCurrentNode = pl -> tail;

        pCurrentNode -> next = pNewNode;
        pNewNode -> prev = pCurrentNode;
        pl -> tail = pNewNode;
    }
    pl -> size++;

    return LIST_SUCCESS;
}

/**
 * insertAtPosition - Insert a node at a specific position in the linked list.
 * @pl: Pointer to the linked list.
 * @value: The value to be inserted.
 * @position: The position at which the value is to be inserted.
 * 
 * Returns:
 *  - LIST_SUCCESS if the insertion is successful.
 *  - LIST_NOT_INITIALIZED if the linked list is not initialized.
 *  - LIST_POSITION_INVALID if the position is out of bounds.
 * 
 * Logic:
 *  - Create a new node with the given value.
 *  - If the position is 0, insert the node at the head.
 *  - If the position is at the end, insert the node at the tail.
 *  - Otherwise, traverse the list to the position, starting from the nearest end, and insert the node.
 */
int insertAtPosition(LinkedList* pl, double value, unsigned int position)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (position > pl -> size) return LIST_POSITION_INVALID;

    if (position == 0) 
    {
        return insertAtBeginning(pl, value);
    }

    if (position == pl -> size) 
    {
        return insertAtEnd(pl, value);
    }

    Node* pNewNode = createNode(value);
    Node* pCurrentNode;

    // Optimize traversal by starting from the nearest end
    if (position <= pl -> size / 2) // Start from the head if the position is in the first half
    {
        pCurrentNode = pl -> head;

        for (unsigned int i = 0; i < position; i++)
        {
            pCurrentNode = pCurrentNode -> next;
        }
    }
    else // Start from the tail if the position is in the second half
    {
        pCurrentNode = pl -> tail;

        for (unsigned int i = pl -> size - 1; i > position; i--)
        {
            pCurrentNode = pCurrentNode -> prev;
        }
    }

    // pPrevNode is the node just before pCurrentNode
    Node* pPrevNode = pCurrentNode -> prev;

    // Adjust the pointers for the new node
    pNewNode -> prev = pPrevNode;
    pNewNode -> next = pCurrentNode;

    // Adjust the pointers of the surrounding nodes
    pPrevNode -> next = pNewNode;
    pCurrentNode -> prev = pNewNode;

    // Increment the list size
    pl -> size++;

    return LIST_SUCCESS;
}

/* ======================================================== */

/** DELETION OPERATIONS 
=======================
*/

/**
 * deleteFirstNode - Delete the first node of the linked list.
 * @pl: Pointer to the linked list.
 * 
 * Returns:
 *  - LIST_SUCCESS if the deletion is successful.
 *  - LIST_NOT_INITIALIZED if the linked list is not initialized.
 *  - LIST_IS_EMPTY if the linked list is empty.
 * 
 * Logic:
 *  - Check if the list is initialized and not empty.
 *  - Update the head pointer to the next node.
 *  - If the list becomes empty, update the tail pointer to NULL.
 *  - Free the memory of the deleted node.
 */
int deleteFirstNode(LinkedList* pl)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (pl -> size == 0) return LIST_IS_EMPTY;

    Node* pCurrentNode = pl -> head;
    
    if (pl -> size == 1)
    {
        pl -> head = NULL;
        pl -> tail = NULL;
    }
    else
    {
        Node* pNextNode = pCurrentNode -> next;

        pl -> head = pNextNode;
        pNextNode -> prev = NULL;
    }
    
    pl -> size--;

    free(pCurrentNode);

    return LIST_SUCCESS;
}

/**
 * deleteLastNode - Delete the last node of the linked list.
 * @pl: Pointer to the linked list.
 * 
 * Returns:
 *  - LIST_SUCCESS if the deletion is successful.
 *  - LIST_NOT_INITIALIZED if the linked list is not initialized.
 *  - LIST_IS_EMPTY if the linked list is empty.
 * 
 * Logic:
 *  - Check if the list is initialized and not empty.
 *  - Update the tail pointer to the previous node.
 *  - If the list becomes empty, update the head pointer to NULL.
 *  - Free the memory of the deleted node.
 */
int deleteLastNode(LinkedList* pl)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (pl -> size == 0) return LIST_IS_EMPTY;

    Node* pCurrentNode = pl -> tail;

    if (pl -> size == 1)
    {
        pl -> head = NULL;
        pl -> tail = NULL;
    }
    else
    {
        Node* pPrevNode = pCurrentNode -> prev;

        pl -> tail = pPrevNode;
        pPrevNode -> next = NULL;
    }

    pl -> size--;

    free(pCurrentNode);

    return LIST_SUCCESS;
}

/**
 * deleteNodeAtPosition - Deletes a node at a specific position in the linked list.
 * @pl: Pointer to the linked list.
 * @position: The position of the node to delete (0-based index).
 * 
 * Returns:
 *  - LIST_NOT_INITIALIZED if the list is not initialized.
 *  - LIST_POSITION_INVALID if the position is invalid.
 *  - LIST_SUCCESS upon successful deletion.
 * 
 * Logic:
 *  - Check if the list is initialized and not empty.
 *  - If the position is 0, delete the head node.
 *  - If the position is at the end, delete the tail node.
 *  - Otherwise, traverse the list to the position and delete the node.
 */
int deleteNodeAtPosition(LinkedList* pl, unsigned int position)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (pl -> size == 0) return LIST_IS_EMPTY;
    if (position >= pl -> size) return LIST_POSITION_INVALID;

    if (position == 0)
    {
        return deleteFirstNode(pl);
    }

    if (position == pl -> size - 1)
    {
        return deleteLastNode(pl);
    }

    Node* pCurrentNode;

    // Optimize traversal by starting from the nearest end
    if (position <= pl -> size / 2) // Start from the head if the position is in the first half
    {
        pCurrentNode = pl -> head;

        for (unsigned int i = 0; i < position; i++)
        {
            pCurrentNode = pCurrentNode -> next;
        }
    }
    else // Start from the tail if the position is in the second half
    {
        pCurrentNode = pl -> tail;

        for (unsigned int i = pl -> size - 1; i > position; i--)
        {
            pCurrentNode = pCurrentNode -> prev;
        }
    }

    Node* pPrevNode = pCurrentNode -> prev;
    Node* pNextNode = pCurrentNode -> next;

    pPrevNode -> next = pNextNode;
    pNextNode -> prev = pPrevNode;

    pl -> size--;

    free(pCurrentNode);

    return LIST_SUCCESS;
}

/**
 * deleteNodeWithKey - Deletes the first node with a given key from the linked list.
 * @pl: Pointer to the linked list.
 * @key: The key to delete.
 * @deleteAll: Boolean to indicate whether to delete all nodes with the key.
 * 
 * Returns:
 *  - LIST_NOT_INITIALIZED if the list is not initialized.
 *  - LIST_IS_EMPTY if the list is empty.
 *  - LIST_SUCCESS upon successful deletion.
 * 
 * Logic:
 *  - Check if the list is initialized and not empty.
 *  - Traverse the list to find nodes with the given key.
 *  - Delete the nodes and update pointers.
 */
int deleteNodeWithKey(LinkedList* pl, double key, bool deleteAll)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;

    Node* pCurrentNode = pl -> head;
    unsigned int position = 0;

    while (pCurrentNode != NULL)
    {
        if (compareDoubles(&pCurrentNode -> value, &key) == 0)
        {
            Node* pNextNode = pCurrentNode -> next;
            deleteNodeAtPosition(pl, position);
            if (!deleteAll) break;
            pCurrentNode = pNextNode;
        }
        else
        {
            pCurrentNode = pCurrentNode -> next;
            position++;
        }
    }
    return LIST_SUCCESS;
}

/**
 * deleteLinkedList - Deletes the entire linked list.
 * @pl: Pointer to the linked list.
 * 
 * Logic:
 *  - Traverse the list and free the memory of each node.
 *  - Set the head and tail pointers to NULL.
 *  - Free the memory of the linked list structure.
 */
int deleteLinkedList(LinkedList* pl)
{
    if (!pl) return LIST_NOT_INITIALIZED;

    Node* pCurrentNode = pl -> head;
    while (pCurrentNode != NULL)
    {
        Node* pNextNode = pCurrentNode -> next;
        free(pCurrentNode);
        pCurrentNode = pNextNode;
    }

    pl -> size = 0;
    pl -> head = NULL;
    pl -> tail = NULL;
    
    free(pl);
    
    return LIST_SUCCESS;
}

/* ======================================================== */

/** SEARCH OPERATIONS 
=====================
*/

/**
 * findFirstNodeWithKey - Finds the first node with the specified key in the linked list.
 * @pl: Pointer to the linked list.
 * @key: The key to search for.
 * @out: Pointer to store the first node with the specified key.
 * 
 * Returns:
 *  - LIST_NOT_INITIALIZED if the linked list is not initialized.
 *  - LIST_IS_EMPTY if the linked list is empty.
 *  - NODE_NOT_FOUND if no node with the specified key is found.
 *  - LIST_SUCCESS on success.
 * 
 * Logic:
 *  - Check if the list is initialized and not empty.
 *  - Traverse the list to find the first node with the specified key.
 *  - If found, set the out pointer to the node and return LIST_SUCCESS.
 *  - If not found, set the out pointer to NULL and return NODE_NOT_FOUND.
 */
int findFirstNodeWithKey(LinkedList* pl, double key, Node** out)
{
    if (!pl) 
    {
        *out = NULL;
        return LIST_NOT_INITIALIZED;
    }
    if (isLinkedListEmpty(pl)) 
    {
        *out = NULL;
        return LIST_IS_EMPTY;
    }

    Node* pCurrentNode = pl -> head;
    while (pCurrentNode != NULL && compareDoubles(&pCurrentNode -> value, &key) != 0)
    {
        pCurrentNode = pCurrentNode -> next;
    }

    if (pCurrentNode == NULL)
    {
        *out = NULL;
        return NODE_NOT_FOUND;
    }

    *out = pCurrentNode;
    return LIST_SUCCESS;
}

/**
 * findAllNodesWithKey - Finds all nodes with the specified key in the linked list.
 * @pl: Pointer to the linked list.
 * @key: The key to search for.
 * @out: Array of pointers to store nodes with the specified key.
 * 
 * Returns:
 *  - LIST_NOT_INITIALIZED if the linked list is not initialized.
 *  - LIST_IS_EMPTY if the linked list is empty.
 *  - NODE_NOT_FOUND if no nodes with the specified key are found.
 *  - LIST_SUCCESS on success.
 * 
 * Logic:
 *  - Check if the list is initialized and not empty.
 *  - Traverse the list to find all nodes with the specified key.
 *  - Store each found node in the out array.
 *  - If no nodes are found, set the out pointer to NULL and return NODE_NOT_FOUND.
 */
int findAllNodesWithKey(LinkedList* pl, double key, Node** out)
{
    if (!pl)
    {
        *out = NULL;
        return LIST_NOT_INITIALIZED;
    }

    if (isLinkedListEmpty(pl))
    {
        *out = NULL;
        return LIST_IS_EMPTY;
    }

    unsigned int idx = 0;
    Node* pCurrentNode = pl -> head;

    while (pCurrentNode != NULL)
    {
        if (compareDoubles(&pCurrentNode -> value, &key) == 0)
        {
            out[idx++] = pCurrentNode;
        }
        pCurrentNode = pCurrentNode -> next;
    }

    if (idx == 0)
    {
        *out = NULL;
        return NODE_NOT_FOUND;
    }
    return LIST_SUCCESS;
}

/* ======================================================== */

/** ADVANCED OPERATIONS 
=======================
*/

/**
 * mergeLinkedLists - Merges two linked lists into the first list.
 * @pla: Pointer to the first linked list.
 * @plb: Pointer to the second linked list.
 * 
 * Returns:
 *  - LIST_NOT_INITIALIZED if either linked list is not initialized.
 *  - LIST_IS_EMPTY if the second linked list is empty.
 *  - LIST_SUCCESS upon successful merge.
 * 
 * Logic:
 *  - Check if both lists are initialized.
 *  - If the first list is empty, set its head and tail to the head and tail of the second list.
 *  - If the second list is empty, return LIST_IS_EMPTY.
 *  - Link the tail of the first list to the head of the second list.
 */
int mergeLinkedLists(LinkedList* pla, LinkedList* plb)
{
    if (!pla || !plb) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pla))
    {
        pla -> head = plb -> head;
        pla -> tail = plb -> tail;
        pla -> size = plb -> size;

        return LIST_SUCCESS;
    }

    if (isLinkedListEmpty(plb)) return LIST_IS_EMPTY;

    (pla -> tail) -> next = plb -> head;
    (plb -> head) -> prev = pla -> tail;
    pla -> tail = plb -> tail;
    pla -> size += plb ->size;

    return LIST_SUCCESS;
}

/**
 * copyLinkedList - Copies a linked list into another linked list.
 * @pl: Pointer to the source linked list.
 * @out: Pointer to the destination linked list.
 * 
 * Returns:
 *  - LIST_NOT_INITIALIZED if either linked list is not initialized.
 *  - LIST_IS_EMPTY if the source linked list is empty.
 *  - LIST_IS_NOT_EMPTY if the destination linked list is not empty.
 *  - LIST_SUCCESS upon successful copy.
 * 
 * Logic:
 *  - Check if both lists are initialized and the source list is not empty.
 *  - Traverse the source list, creating and linking new nodes in the destination list.
 */
int copyLinkedList(LinkedList* pl, LinkedList* out)
{
    if (!pl || !out) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;

    unsigned int position = 0;
    Node* pCurrentNode = pl -> head;
    
    while (pCurrentNode != NULL)
    {
        int insertResult = insertAtPosition(out, pCurrentNode -> value, position);
        if (insertResult != LIST_SUCCESS) return LIST_MEMORY_ERROR;

        pCurrentNode = pCurrentNode -> next;
        position++;
    }
    return LIST_SUCCESS;
}

/**
 * sortLinkedList - Sorts the linked list in ascending order.
 * @pl: Pointer to the linked list.
 * 
 * Returns:
 *  - LIST_NOT_INITIALIZED if the linked list is not initialized.
 *  - LIST_IS_EMPTY if the linked list is empty.
 *  - LIST_SUCCESS upon successful sort.
 * 
 * Logic:
 *  - Check if the list is initialized and not empty.
 *  - Copy the values of the nodes into an array.
 *  - Sort the array.
 *  - Copy the sorted values back into the nodes of the linked list.
 */
int sortLinkedList(LinkedList* pl)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;
    if (pl -> size == 1) return LIST_SUCCESS;

    // Allocate an array to hold the values from the linked list
    double* valuesArray = (double*) safeMalloc(sizeof(double) * pl -> size);
    unsigned int idx = 0;
    Node* pCurrentNode = pl -> head;

    // Copy values from the linked list to the array
    while (pCurrentNode != NULL)
    {
        valuesArray[idx++] = pCurrentNode -> value;
        pCurrentNode = pCurrentNode -> next;
    }

    // Sort the array
    qsort(valuesArray, pl -> size, sizeof(double), compareDoubles);

    // Copy sorted values back to the linked list
    pCurrentNode = pl -> head;
    for (unsigned int i = 0; i < pl -> size; i++)
    {
        pCurrentNode -> value = valuesArray[i];
        pCurrentNode = pCurrentNode -> next;
    }

    // Deallocate memory
    free(valuesArray);

    return LIST_SUCCESS;
}

/**
 * reverseLinkedList - Reverses a linked list and stores it in another linked list.
 * @pl: Pointer to the source linked list.
 * @out: Pointer to the destination linked list.
 * 
 * Returns:
 *  - LIST_NOT_INITIALIZED if either linked list is not initialized.
 *  - LIST_IS_EMPTY if the source linked list is empty.
 *  - LIST_IS_NOT_EMPTY if the destination linked list is not empty.
 *  - LIST_SUCCESS upon successful reversal.
 * 
 * Logic:
 *  - Check if both lists are initialized and the source list is not empty.
 *  - Traverse the source list from the tail, inserting nodes at the beginning of the destination list.
 */
int reverseLinkedList(LinkedList* pl, LinkedList* out)
{
    if (!pl || !out) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;

    unsigned int position = 0;
    Node* pCurrentNode = pl -> tail;

    while (pCurrentNode != NULL)
    {
        int insertResult = insertAtPosition(out, pCurrentNode -> value, position);
        if (insertResult != LIST_SUCCESS) return LIST_MEMORY_ERROR;

        pCurrentNode = pCurrentNode -> prev;
        position++;
    }

    return LIST_SUCCESS;
}

/* ======================================================== */
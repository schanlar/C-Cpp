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
} Node;


// Structure of linked list
typedef struct LinkedList
{
    Node* head;
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
 *  - Initialize the node with the given value and set the next pointer to NULL.
 */
Node* createNode(double value)
{
    Node* pNewNode = (Node*) safeMalloc(sizeof(Node));
    pNewNode -> value = value;
    pNewNode -> next = NULL;
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
 *  - Initialize the head pointer to NULL.
 */
LinkedList* createLinkedList(void)
{
    LinkedList* pl = (LinkedList*) safeMalloc(sizeof(LinkedList));
    pl -> head = NULL;
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
    // Dereference and cast the void pointers to double pointers, then calculate the difference
    double arg1 = *(const double*) a;
    double arg2 = *(const double*) b;
    double diff = fabs(arg1 - arg2);

    // Compare the difference with EPSILON to determine equality
    if (diff <= EPSILON) return 0;
    if (arg1 > arg2) return 1;
    return -1;
}


/* ======================================================== */


/** UTILITY FUNCTIONS 
=====================
*/

/**
 * displayLinkedList - Display the values in the linked list.
 * @pl: Pointer to the linked list.
 * 
 * Logic:
 *  - Traverse the linked list.
 *  - Print the value of each node followed by an arrow.
 *  - Print "NULL" at the end to indicate the end of the list.
 */
void displayLinkedList(LinkedList* pl)
{
    // Traverse the linked list
    Node* pCurrentNode = pl -> head;
    while (pCurrentNode!= NULL)
    {
        // Print the value of each node followed by an arrow
        printf("%.lf -> ", pCurrentNode -> value);
        pCurrentNode = pCurrentNode -> next;
    }
    // Print "NULL" at the end to indicate the end of the list
    printf("NULL\n");
}


/**
 * isLinkedListEmpty - Check if the linked list is empty.
 * @pl: Pointer to the linked list.
 * 
 * Returns:
 *  - true if the list is empty or the pointer is null; otherwise, false.
 * 
 * Logic:
 *  - Check if the linked list pointer is NULL or if the head pointer is NULL.
 *  - Return true if either condition is true; otherwise, return false.
 */
bool isLinkedListEmpty(LinkedList* pl)
{
    return (pl == NULL || pl -> head == NULL);
}


/**
 * sizeLinkedList - Get the size of the linked list.
 * @pl: Pointer to the linked list.
 * 
 * Returns:
 *  - The size of the linked list.
 *  - LIST_NOT_INITIALIZED if the linked list is not initialized.
 * 
 * Logic:
 *  - Check if the linked list is initialized.
 *  - Traverse the linked list and count the number of nodes.
 *  - Return the count.
 */
int sizeLinkedList(LinkedList* pl)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return 0;

    Node* pCurrentNode = pl -> head;
    unsigned int len = 0;

    // Traverse the linked list and count the number of nodes
    while (pCurrentNode != NULL)
    {
        len++;
        pCurrentNode = pCurrentNode -> next;
    }
    return len;
}

/* ======================================================== */


/** INSERTATION OPERATIONS 
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
 *  - Set the next pointer of the new node to the current head of the list.
 *  - Update the head pointer to the new node.
 */
int insertAtBeginning(LinkedList* pl, double value)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    Node* pNewNode = createNode(value);

    // Set the next pointer of the new node to the current head of the list
    pNewNode -> next = pl -> head;

    // Update the head pointer to the new node
    pl -> head = pNewNode;
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
 *  - If the list is empty, set the head pointer to the new node.
 *  - Otherwise, traverse to the end of the list and set the next pointer of the last node to the new node.
 */
int insertAtEnd(LinkedList* pl, double value)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    Node* pNewNode = createNode(value);

    // If the list is empty, set the head pointer to the new node
    if (pl -> head == NULL)
    {
        pl -> head = pNewNode;
        return LIST_SUCCESS;
    }

    // Traverse the linked list to find the end
    Node* pCurrentNode = pl -> head;
    while (pCurrentNode -> next != NULL)
    {
        pCurrentNode = pCurrentNode -> next;
    }

    // Set the next pointer of the last node to the new node
    pCurrentNode -> next = pNewNode;
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
 *  - Otherwise, traverse the list to the position and insert the node.
 */
int insertAtPosition(LinkedList* pl, double value, unsigned int position)
{
    if (isLinkedListEmpty(pl) && position > 0) return LIST_POSITION_INVALID;

    Node* pNewNode = createNode(value);
    if (position == 0) // Special case for inserting at the head
    {
        pNewNode->next = pl->head;
        pl->head = pNewNode;
        return LIST_SUCCESS;
    }

    Node* pCurrentNode = pl->head;
    Node* pPrevNode = NULL;

    // Traverse the list to the position
    for (unsigned int i = 0; i < position; i++)
    {
        if (pCurrentNode == NULL) return LIST_POSITION_INVALID; // Position out of bounds

        pPrevNode = pCurrentNode;
        pCurrentNode = pCurrentNode->next;
    }

    // Insert the new node at the specified position
    pNewNode->next = pCurrentNode;
    pPrevNode->next = pNewNode;

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
 *  - Free the memory of the deleted node.
 */
int deleteFirstNode(LinkedList* pl)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;

    Node* pCurrentNode = pl->head;

    pl->head = pCurrentNode->next; // Update the head pointer to the next node
    free(pCurrentNode);  // Free the memory of the deleted node

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
 *  - Traverse the list to find the last node and its previous node.
 *  - Update the next pointer of the previous node to NULL.
 *  - If the list has only one node, update the head pointer to NULL.
 *  - Free the memory of the deleted node.
 */
int deleteLastNode(LinkedList* pl)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;

    Node* pCurrentNode = pl->head;
    Node* pPrevNode = NULL;

    // Traverse to the end of the list
    while (pCurrentNode->next != NULL)
    {
        pPrevNode = pCurrentNode;
        pCurrentNode = pCurrentNode->next;
    }

    // If pPrevNode is NULL, it means there's only one node in the list
    if (pPrevNode == NULL)
    {
        pl->head = NULL;
    }
    else
    {
        pPrevNode->next = NULL;
    }

    // Free the memory of the deleted node
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
 *  - Otherwise, traverse the list to the position and delete the node.
 */
int deleteNodeAtPosition(LinkedList* pl, unsigned int position)
{
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_POSITION_INVALID;
    
    if (position == 0) 
    {
        deleteFirstNode(pl); // Delete the head node if position is 0
        return LIST_SUCCESS;
    }

    Node* pCurrentNode = pl -> head;
    Node* pPrevNode = NULL;

    // Traverse the list to the specified position
    for (unsigned int i = 0; i < position; i++)
    {
        if (pCurrentNode == NULL) return LIST_POSITION_INVALID; // Position out of bounds

        pPrevNode = pCurrentNode;
        pCurrentNode = pCurrentNode -> next;
    }
    if (pCurrentNode == NULL) return LIST_POSITION_INVALID; // Position out of bounds

    // Update the next pointer of the previous node to skip the deleted node
    pPrevNode -> next = pCurrentNode -> next;

    // Free the memory of the deleted node
    free(pCurrentNode);
    return LIST_SUCCESS;
}


/**
 * deleteNodeWithKey - Deletes the first node with a given key from the linked list.
 * @pl: Pointer to the linked list.
 * @key: The key to delete.
 * 
 * Returns:
 *  - LIST_NOT_INITIALIZED if the list is not initialized.
 *  - LIST_IS_EMPTY if the list is empty.
 *  - NODE_NOT_FOUND if no node with the specified key is found.
 *  - LIST_SUCCESS upon successful deletion.
 * 
 * Logic:
 *  - Check if the list is initialized and not empty.
 *  - Traverse the list to find the node with the given key.
 *  - If the node is found, update the next pointer of the previous node or head pointer.
 *  - Free the memory of the deleted node.
 */
int deleteNodeWithKey(LinkedList* pl, double key)
{
    if (!pl) return LIST_NOT_INITIALIZED;  // Check if the list is initialized
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;  // Check if the list is empty

    Node* pCurrentNode = pl->head;  // Pointer to traverse the list
    Node* pPrevNode = NULL;  // Pointer to keep track of the previous node

    // Traverse the list to find the node to be deleted
    while (pCurrentNode != NULL && compareDoubles(&pCurrentNode->value, &key) != 0)
    {
        pPrevNode = pCurrentNode;
        pCurrentNode = pCurrentNode->next;
    }

    if (pCurrentNode == NULL) return NODE_NOT_FOUND;  // Node with the specified key not found

    // If the node to be deleted is the head node
    if (pPrevNode == NULL)
    {
        pl->head = pCurrentNode->next;
    }
    else  // If the node to be deleted is not the head node
    {
        pPrevNode->next = pCurrentNode->next;
    }

    free(pCurrentNode);  // Free the memory allocated for the node
    return LIST_SUCCESS;  
}


/**
 * deleteLinkedList - Deletes the entire linked list.
 * @pl: Pointer to the linked list.
 * 
 * Logic:
 *  - Traverse the list and free the memory of each node.
 *  - Set the head pointer to NULL.
 *  - Free the memory of the linked list structure.
 */
void deleteLinkedList(LinkedList* pl)
{
    Node* pCurrentNode = pl -> head;
    Node* pNextNode;

    // Traverse the list and free the memory of each node
    while (pCurrentNode != NULL)
    {
        pNextNode = pCurrentNode -> next;
        free(pCurrentNode);
        pCurrentNode = pNextNode;
    }
    // Set the head pointer to NULL and free the memory of the linked list structure
    pl -> head = NULL;
    free(pl);
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

    // Traverse the list to find the first node with the specified key
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

    // Set the out pointer to the found node
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
 *  - 0 on success.
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

    Node* pCurrentNode = pl->head;
    unsigned int idx = 0;
    
    // Traverse the list to find all nodes with the specified key
    while (pCurrentNode != NULL)
    {
        if (compareDoubles(&pCurrentNode->value, &key) == 0)
        {
            out[idx++] = pCurrentNode;
        }
        pCurrentNode = pCurrentNode->next;
    }
    
    if (idx == 0)
    {
        *out = NULL;
        return NODE_NOT_FOUND;
    }
    return 0; 
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
 *  - If the first list is empty, set its head to the head of the second list.
 *  - If the second list is empty, return LIST_IS_EMPTY.
 *  - Traverse the first list to its end and link the last node to the head of the second list.
 */
int mergeLinkedLists(LinkedList* pla, LinkedList* plb)
{
    if (!pla || !plb) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pla))
    {
        // If the first list is empty, set its head to the head of the second list
        pla -> head = plb -> head;
        return LIST_SUCCESS;
    }
    if (isLinkedListEmpty(plb)) return LIST_IS_EMPTY;

    Node* pCurrentNode = pla -> head;

    // Traverse to the end of the first list
    while (pCurrentNode -> next != NULL)
    {
        pCurrentNode = pCurrentNode -> next;
    }

    // Merge the second list into the first list
    pCurrentNode -> next = plb -> head;

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
    if (!pl) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;
    if (!isLinkedListEmpty(out)) return LIST_IS_NOT_EMPTY;

    Node* pCurrentNode = pl -> head;
    Node* pLastNode = NULL;
    
    // Traverse the source list, creating and linking new nodes in the destination list
    while (pCurrentNode != NULL)
    {
        Node* pNewNode = createNode(pCurrentNode -> value);

        if (out -> head == NULL)
        {
            out -> head = pNewNode;
        } 
        else
        {
            pLastNode -> next = pNewNode;
        }
        // Update pLastNode to point to the new last node
        pLastNode = pNewNode;

        // Move to the next node in the original list
        pCurrentNode = pCurrentNode->next;
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

    int listSize = sizeLinkedList(pl);
    if (listSize == 1) return LIST_SUCCESS; // Already sorted if size == 1

    double* listValues = (double*) safeMalloc(sizeof(double) * listSize);

    Node* pCurrentNode = pl -> head;
    int idx = 0;

    // Copy values from linked list to array
    while (pCurrentNode != NULL)
    {
        listValues[idx++] = pCurrentNode -> value;
        pCurrentNode = pCurrentNode -> next;
    }

    // Sort the array
    qsort(listValues, listSize, sizeof(double), compareDoubles);

    // Copy sorted values back to linked list
    pCurrentNode = pl->head;
    idx = 0;
    while (pCurrentNode != NULL)
    {
        pCurrentNode->value = listValues[idx++];
        pCurrentNode = pCurrentNode->next;
    }

    free(listValues);
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
 *  - Copy the values of the nodes into an array in reverse order.
 *  - Create new nodes with the reversed values and link them in the destination list.
 */
int reverseLinkedList(LinkedList* pl, LinkedList* out)
{
    if (!pl || !out) return LIST_NOT_INITIALIZED;
    if (isLinkedListEmpty(pl)) return LIST_IS_EMPTY;
    if (!isLinkedListEmpty(out)) return LIST_IS_NOT_EMPTY;

    int listSize = sizeLinkedList(pl);
    double* listValues = (double*) safeMalloc(sizeof(double) * listSize);

    Node* pCurrentNode = pl -> head;
    int idx = listSize - 1;

    // Copy values from linked list to array in reverse order
    while (pCurrentNode != NULL)
    {
        listValues[idx--] = pCurrentNode -> value;
        pCurrentNode = pCurrentNode -> next;
    }

    // Create the reversed linked list
    Node* pPrevNode = NULL;
    for (int i = 0; i < listSize; i++)
    {
        Node* pNewNode = createNode(listValues[i]);

        if (out -> head == NULL)
        {
            out -> head = pNewNode;
        } 
        else
        {
            pPrevNode -> next = pNewNode;
        }
        pPrevNode = pNewNode;
    }
    free(listValues);
    return LIST_SUCCESS;
}

/* ======================================================== */
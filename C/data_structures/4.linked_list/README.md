# Linked List Data Structure Implementations

## Introduction

A **linked list** is a linear data structure in which elements are not stored in contiguous memory locations. Instead, each element (known as a node) contains a value and a reference (or link) to the next node in the sequence. Linked lists are dynamic in size, making them efficient for insertions and deletions.

## Types of Linked Lists

- **Singly Linked List**: Each node contains a single link to the next node.
- **Doubly Linked List**: Each node contains two links, one to the next node and one to the previous node.
- **Circular Linked List**: The last node contains a link back to the first node, forming a circular structure.

## Basic Operations

- **insertAtBeginning**: Insert a node at the beginning of the linked list.
- **insertAtEnd**: Insert a node at the end of the linked list.
- **insertAtPosition**: Insert a node at a specific position in the linked list.
- **deleteFirstNode**: Delete the first node of the linked list.
- **deleteLastNode**: Delete the last node of the linked list.
- **deleteNodeAtPosition**: Delete a node at a specific position in the linked list.
- **deleteNodeWithKey**: Delete the first node with a given key from the linked list.
- **deleteLinkedList**: Delete the entire linked list.
- **findFirstNodeWithKey**: Find the first node with the specified key in the linked list.
- **findAllNodesWithKey**: Find all nodes with the specified key in the linked list.
- **displayLinkedList**: Display the elements of the linked list.
- **isLinkedListEmpty**: Check if the linked list is empty.
- **sizeLinkedList**: Get the size (number of elements) of the linked list.

## Advanced Operations

- **mergeLinkedLists**: Merge two linked lists into the first list.
- **copyLinkedList**: Create a copy of a linked list.
- **sortLinkedList**: Sort the elements of the linked list in ascending order.
- **reverseLinkedList**: Reverse the elements of the linked list and store them in another linked list.

## Implementations

This directory contains the implementation of the linked list data structure in C:

- **File**: `singly_linked_list.c`
- **File**: `doubly_linked_list.c`
- **File**: `circular_linked_list.c`

Each implementation includes the necessary functions to perform both basic and advanced linked list operations.

## Error Handling

The linked list implementation uses the following error codes to handle various error conditions:

- **LIST_SUCCESS**: Operation completed successfully.
- **LIST_NOT_INITIALIZED**: The linked list is not initialized.
- **LIST_IS_EMPTY**: The linked list is empty.
- **LIST_IS_NOT_EMPTY**: The linked list is not empty.
- **LIST_POSITION_INVALID**: The specified position is invalid.
- **NODE_NOT_FOUND**: The specified node is not found.
- **LIST_MEMORY_ERROR**: Memory allocation failed.

These error codes help in diagnosing issues and ensuring robust error handling in the linked list operations.

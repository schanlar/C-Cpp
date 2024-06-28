# Stack Data Structure Implementations

## Introduction

A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. This means that the last element added to the stack is the first one to be removed. Stacks are commonly used in various applications such as expression evaluation, syntax parsing, and backtracking algorithms.

## Stack Operations

- **push**: Add an element to the top of the stack.
- **pop**: Remove and return the element from the top of the stack.
- **peek**: Return the top element without removing it.
- **isEmpty**: Check if the stack is empty.
- **isFull**: Check if the stack is full.
- **getSize**: Get the current number of elements in the stack.
- **clear**: Empty the stack.
- **toArray**: Convert the stack to an array.
- **reverse**: Reverse the elements in the stack.

## Implementations

There are multiple ways to implement a stack, each with its own advantages and use cases. This directory contains three different implementations of a stack data structure:

1. **Simple Fixed Size, Static Stack Data Structure**:
   - This implementation uses a fixed-size array where the maximum size of the stack is determined at compile-time. It is simple and efficient for scenarios where the maximum stack size is known and does not change.
   - **File**: `static_stack.c`

2. **Variable Length Stack Data Structure Using Dynamic Arrays**:
   - This implementation uses a dynamic array that can grow and shrink at runtime as needed. It is flexible and allows the stack to handle a varying number of elements.
   - **File**: `dynamic_array_stack.c`

3. **Variable Length Stack Data Structure Using Linked Lists**:
   - This implementation uses a linked list where each element (node) contains the data and a pointer to the next node. It allows for efficient memory usage and can handle an arbitrary number of elements.
   - **File**: `linked_list_stack.c`
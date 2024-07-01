# Queue Data Structure Implementations

## Introduction

A **queue** is a linear data structure that follows the **First In, First Out (FIFO)** principle. This means that the first element added to the queue is the first one to be removed. Queues are commonly used in various applications such as scheduling algorithms, buffering, and breadth-first search algorithms.

## Queue Operations

- **enqueue**: Add an element to the rear of the queue.
- **dequeue**: Remove and return the element from the front of the queue.
- **peek**: Return the front element without removing it.
- **isEmpty**: Check if the queue is empty.
- **isFull**: Check if the queue is full.
- **getSize**: Get the current number of elements in the queue.
- **clear**: Empty the queue.

## Implementations

There are multiple ways to implement a queue, each with its own advantages and use cases. This directory contains three different implementations of a queue data structure:

1. **Simple Fixed Size, Static Queue Data Structure**:
   - This implementation uses a fixed-size array where the maximum size of the queue is determined at compile-time. It is simple and efficient for scenarios where the maximum queue size is known and does not change.
   - **File**: `static_queue.c`

2. **Variable Length Queue Data Structure Using Dynamic Arrays**:
   - This implementation uses a dynamic array that can grow and shrink at runtime as needed. It is flexible and allows the queue to handle a varying number of elements.
   - **File**: `dynamic_array_queue.c`

3. **Variable Length Queue Data Structure Using Linked Lists**:
   - This implementation uses a linked list where each element (node) contains the data and a pointer to the next node. It allows for efficient memory usage and can handle an arbitrary number of elements.
   - **File**: `linked_list_queue.c`

Each implementation includes the necessary functions to perform the basic queue operations.
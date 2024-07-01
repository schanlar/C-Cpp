# Dynamic Array Implementations in C

This repository contains various implementations of a dynamic array in C. 
Each version includes enhancements and optimizations over the previous ones. The implementations are located in the following files:

- `arrayList_v1.c`
- `arrayList_v2.0.c`
- `arrayList_v2.1.c`
- `arrayList_v2.2.c` (latest)

## Overview

Dynamic arrays are data structures that allow the size of an array to be dynamically changed during runtime. The primary difference between a standard static array and a dynamic array is that the latter can grow and shrink as needed.

### Reallocation in Dynamic Arrays

Reallocation is the process of resizing an array when it grows beyond its current capacity or when elements are removed. This involves several steps:

1. **Memory Allocation:** When the array reaches its capacity and a new element needs to be added, a larger block of memory must be allocated to accommodate the new size. This new block needs to be contiguous, meaning all the elements must be stored sequentially in memory.

2. **Copying Elements:** Once a new, larger block of memory is allocated, all the existing elements in the current array must be copied to this new memory location. This ensures that the array maintains its sequential order.

3. **Freeing Old Memory:** After copying the elements, the old memory block is freed. This step helps in managing memory but can also lead to fragmentation if done frequently.

This process can be costly because:
- **Copying Overhead:** Each reallocation requires copying all elements from the old array to the new array. This can be time-consuming, especially for large arrays, as the time complexity of copying is O(n), where n is the number of elements.
- **Memory Allocation:** Allocating new memory blocks can be expensive in terms of both time and system resources, particularly if done frequently. The system needs to find a contiguous block of memory large enough to fit the new array, which can be challenging as memory becomes fragmented.
- **Fragmentation:** Repeated reallocations can lead to fragmentation of memory, where free memory is divided into small, non-contiguous blocks, reducing the efficiency of memory usage.

### Implementation Details

#### `arrayList_v1.c`

The first implementation handles resizing the array by reallocating memory each time an element is added or removed. This ensures that the array is always of the minimum necessary size.

**Pros:**
- **Memory Efficiency:** The array size is always precisely what is needed, avoiding unused space.
- **Simplicity:** The code is straightforward, with no need for additional logic to handle special cases like lazy deletions.

**Cons:**
- **Performance Overhead:** Frequent memory reallocations can be costly in terms of performance, especially when the array grows or shrinks often.
- **Fragmentation:** Continuous reallocation can lead to memory fragmentation, which may affect overall system performance.

#### `arrayList_v2.x.c`

The second implementation incorporates several advanced techniques to manage the dynamic array more efficiently:

- **Amortized Doubling Strategy:** When the array reaches its capacity, its size is doubled. This significantly reduces the frequency of memory reallocations.
- **Lazy Deletions:** Elements to be removed are marked with `NAN` (Not-a-Number) instead of immediately freeing memory. This approach aims to reduce the number of reallocations.
- **Dynamic Shrinking:** When the array's `NAN`s (deletions) exceed a certain threshold (e.g., a quarter of its capacity), the array size is compactified by removing the `NAN` entries in order to free up unused memory.

**Pros:**
- **Improved Performance:** Fewer reallocations can significantly reduce the performance overhead associated with dynamic memory operations.
- **Reduced Fragmentation:** By avoiding frequent reallocations, this approach minimizes the risk of memory fragmentation.
- **Lazy Deletion:** Allows the list to continue operating without the immediate overhead of memory deallocation, deferring it to a more optimal time.

**Cons:**
- **Memory Overhead:** The list may contain `NAN` markers, leading to potential unused memory until the list is compactified.
- **Complexity:** The code requires additional logic to handle the lazy deletion and compactification processes.

### Functionality

Both implementations provide the following basic functionalities:
- **Append Elements:** Add elements to the end of the list.
- **Remove Elements:** Remove elements from the list.
- **Display Elements:** Print the elements of the list.
- **Check Containment:** Check if an element exists in the list.
- **Equality Check:** Compare two lists for equality.
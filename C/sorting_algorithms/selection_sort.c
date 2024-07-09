#include <stdio.h>

// Function to perform selection sort
void selectionSort(int* arr, unsigned int size) {
    while (size > 1) {
        int idxMax = 0;
        // Find the index of the maximum element in the unsorted part
        for (unsigned int i = 1; i < size; i++) {
            if (arr[i] > arr[idxMax]) {
                idxMax = i;
            }
        }
        // Swap the maximum element with the last element in the unsorted part
        int tmp = arr[idxMax];
        arr[idxMax] = arr[size - 1];
        arr[size - 1] = tmp;
        // Reduce the size of the unsorted part
        size--;
    }
}

// Function to print the array
void printArray(int* arr, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test array
    int arr[] = {64, 25, 12, 22, 11};
    unsigned int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    // Sorting the array
    selectionSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}


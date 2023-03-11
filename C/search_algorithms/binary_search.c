#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dataio.h"

void bubbleSort(int *array, int size);
int intExist(int num, int *array, int size);
int realExist(double num, double *array, int size, double eps);

// bubblesort algorithm is extremely slow. 
// For a size > 10000 the execution may take a while
#define SIZE 10

int main(void){

    // Get an array of random integers and sort it
    int *arr1;
    arr1 = fillIntArray(SIZE);
    bubbleSort(arr1, SIZE);
    printIntArray(arr1, SIZE);

    int num1, idx;
    printf("Enter an integer: ");
    scanf("%d", &num1);
    idx = intExist(num1, arr1, SIZE);
    if (idx != -1){
        printf("Integer found at index %d\n", idx);
    }
    else{
        printf("Integer not found!\n");
    }
    free(arr1); // Deallocate memory


    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    // Get an array of random characters
    char *arr2 = fillCharArray(SIZE);
    // printCharArray(arr2);

    // Convert character to its decimal number representation in ASCII
    int ascii[SIZE];
    for (int i = 0; i < SIZE; i++){
        ascii[i] = (int) arr2[i];
    }

    // Sort the ASCII representation and the original character array
    bubbleSort(ascii, SIZE);
    for (int i = 0; i < SIZE; i++){
        arr2[i] = (char) ascii[i];
    }
    printCharArray(arr2);

    // Get from user the character they want to search for
    // and cast it to its ASCII representation
    char letter;
    printf("Enter a letter: ");
    scanf(" %c", &letter);
    int ascii_letter = (int) letter;

    // Search for the letter
    idx = intExist(ascii_letter, ascii, SIZE);
    if (idx != -1){
        printf("Letter found at index %d\n", idx);
    }
    else{
        printf("Letter not found!\n");
    }
    free(arr2); // Deallocate memory

    return 0;
}

int intExist(int num, int *array, int size){
    // Initialize search boundaries
    int idxStart = 0, idxEnd = size;

    // Initialize a counter to exit the while loop
    int counter = 0, found = 0;

    // Start in the middle of a sorted array
    int middle_element;
    middle_element = array[(idxStart + idxEnd) / 2];
    while (1){
        
        if (found && counter < size){
            // Normal exit when number is found
            return (idxStart + idxEnd) / 2;
        }
        else if (!found && counter >= size){
            // Normal exit when number is not found
            return -1;
        }
        
        if (num == middle_element){
            found = 1;
        }
        else if (middle_element > num){
            // Update upper boundary
            idxEnd = (idxStart + idxEnd) / 2;
            middle_element = array[(idxStart + idxEnd) / 2];
            counter++;
        }
        else {
            // Update lower boundary
            idxStart = (idxStart + idxEnd) / 2;
            middle_element = array[(idxStart + idxEnd) / 2];
            counter++;
        }
    }
}

int realExist(double num, double *array, int size, double eps){
    // Initialize search boundaries
    int idxStart = 0, idxEnd = size;

    // Initialize a counter to exit the while loop
    int counter = 0, found = 0;

    // Start in the middle of a sorted array
    int middle_element;
    middle_element = array[(idxStart + idxEnd) / 2];
    while (1){
        
        if (found && counter < size){
            // Normal exit when number is found
            return (idxStart + idxEnd) / 2;
        }
        else if (!found && counter >= size){
            // Normal exit when number is not found
            return -1;
        }
        
        if (fabs(num - middle_element) <= eps){
            found = 1;
        }
        else if (middle_element > num){
            // Update upper boundary
            idxEnd = (idxStart + idxEnd) / 2;
            middle_element = array[(idxStart + idxEnd) / 2];
            counter++;
        }
        else {
            // Update lower boundary
            idxStart = (idxStart + idxEnd) / 2;
            middle_element = array[(idxStart + idxEnd) / 2];
            counter++;
        }
    }
}


void bubbleSort(int *array, int size){
    int tmp;
    printf("Sorting...\n");
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (array[j] > array[j+1]){
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    printf("Done!\n");
    return;
}

/*
    COMMENTS:
    Binary search requires a sorted array in order to work.
    Here we used the bubblesort algorithm to perform a basic sorting and then apply
    the binary search algorithm on that sorted array.
    However, we could take further measures to optimize our code:
        1) Optimize the bubblesort algorithm => stop sorting if there is no swapping 
        2) Bubblesort already performs a serial search at runtime. We could search for the 
        number/character while sorting.
*/
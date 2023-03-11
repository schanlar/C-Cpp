#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dataio.h"


// Serial search functions
int intExist(int num, int *array, int size);
int realExist(double num, double *array, int size, double eps);
int charExist(char letter, char *string);


#define SIZE 10

int main(void){

    int *arr1 = fillIntArray(SIZE);
    double *arr2 = fillRealArray(SIZE);
    char *arr3 = fillCharArray(SIZE);
    int idx, num1;
    double num2;
    char letter;

    printf("Enter an integer: ");
    scanf(" %d", &num1);
    idx = intExist(num1, arr1, SIZE);
    if (idx != -1){
        printf("Integer found at index %d\n", idx);
    }
    else{
        printf("Integer not found!\n");
    }

    printf("Enter a real number: ");
    scanf(" %lf", &num2);
    idx = realExist(num2, arr2, SIZE, 1e-6);
    if (idx != -1){
        printf("Real found at index %d\n", idx);
    }
    else{
        printf("Real number not found!\n");
    }

    printf("Enter a letter: ");
    // letter = getchar();
    scanf(" %c", &letter);
    idx = charExist(letter, arr3);
    if (idx != -1){
        printf("Letter found at index %d\n", idx);
    }
    else{
        printf("Letter not found!\n");
    }

    printf("\n\nARRAY OF INTEGERS\n-----------------\n");
    printIntArray(arr1, SIZE);
    printf("\nARRAY OF REAL NUMBERS\n---------------------\n");
    printRealArray(arr2, SIZE);
    printf("\nARRAY OF CHARACTERS\n-------------------\n");
    printCharArray(arr3);

    free(arr1);
    free(arr2);
    free(arr3);
    
    return 0;
}



int intExist(int num, int *array, int size){
    for (int i = 0; i < size; i++){
        if (num == array[i]) return i;
    }
    return -1;
}

int realExist(double num, double *array, int size, double eps){
    for (int i = 0; i < size; i++){
        if (fabs(num - array[i]) <= eps) return i;
    }
    return -1;
}

int charExist(char letter, char *string){
    int i = 0;
    while (string[i] != '\0'){
        if (string[i] == letter) return i;
        i++;
    }
    return -1;
}
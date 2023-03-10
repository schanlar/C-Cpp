#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Functions to fill arrays with random data
// and display them
int *fillIntArray(int size);
void printIntArray(int *array, int size);

double *fillRealArray(int size);
void printRealArray(double *array, int size);

char *fillCharArray(int size);
void printCharArray(char *array);

// Serial search functions
int intExist(int num, int *array, int size);
int realExist(double num, double *array, int size, double eps);
int charExist(char letter, char *string);


#define SIZE 10

int main(void){

    int *arr1 = fillIntArray(SIZE);
    double *arr2 = fillRealArray(SIZE);
    char *arr3 = fillCharArray(SIZE);
    int idx;

    idx = intExist(8, arr1, SIZE);
    if (idx != -1){
        printf("Integer found at index %d\n", idx);
    }
    else{
        printf("Integer not found!\n");
    }

    idx = realExist(0.7, arr2, SIZE, 1e-6);
    if (idx != -1){
        printf("Real found at index %d\n", idx);
    }
    else{
        printf("Real number not found!\n");
    }

    idx = charExist('S', arr3);
    if (idx != -1){
        printf("Letter found at index %d\n", idx);
    }
    else{
        printf("Letter not found!\n");
    }

    printIntArray(arr1, SIZE);
    printf("~~~~~~~~~~~~~~~~~~~~~~\n");
    printRealArray(arr2, SIZE);
    printf("~~~~~~~~~~~~~~~~~~~~~~\n");
    printCharArray(arr3);

    free(arr1);
    free(arr2);
    free(arr3);
    
    return 0;
}



int *fillIntArray(int size){
    srand(time(NULL));
    int *array = (int *) malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++){
        array[i] = (rand() % 1000) + 1;
    }
    return array;
}

void printIntArray(int *array, int size){
    for (int i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }
    return;
}

double *fillRealArray(int size){
    srand(time(NULL));
    double *array = (double *) malloc(sizeof(double) * size);

    for (int i = 0; i < size; i++){
        array[i] = ((rand() % 10000) + 1) / 10.0;
    }
    return array;
}

void printRealArray(double *array, int size){
    for (int i = 0; i < size; i++){
        printf("%.3lf\n", array[i]);
    }
    return;
}

char *fillCharArray(int size){
    srand(time(NULL));
    char *array = (char *) malloc(sizeof(char) * (size + 1));

    for (int i = 0; i <= size; i++){
        int tmp;
        if (i == size) {
            array[i] = '\0';
        }
        else {
            tmp = rand() % 256;
            /* get only ASCII alphabet */
            if ((tmp >= 65 && tmp <= 90) || (tmp >= 97 && tmp <= 122)){
                array[i] = (char) tmp;
            }
            else {
                i--;
            }
        }   
    }
    return array;
}

void printCharArray(char *array){
    int i = 0;
    while (array[i] != '\0'){
        printf("%c\n", array[i]);
        i++;
    }
    return;
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
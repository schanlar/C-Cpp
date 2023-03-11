#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*  
Functions to fill arrays with random data
and display them
*/

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
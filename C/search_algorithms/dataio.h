#ifndef DATA_IO_H
#define DATA_IO_H

/*  
Functions to fill arrays with random data
and display them
*/

int *fillIntArray(int size);
void printIntArray(int *array, int size);

double *fillRealArray(int size);
void printRealArray(double *array, int size);

char *fillCharArray(int size);
void printCharArray(char *array);

#endif
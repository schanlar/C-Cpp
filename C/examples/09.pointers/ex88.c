/*
    Παράδειγμα 5:
    Να γραφεί ένα πρόγραμμα το οποίο, με χρήση δείκτη, να διαβάζει μια πραγματική τιμή 
    και να εμφανίζει την απόλυτη τιμή της.
*/

#include <stdio.h>

int main(void){
    double num;
    double *ptr = &num;
    printf("Enter a number: ");
    scanf("%lf", ptr);

    if (*ptr >= 0){
        printf("Absolute value: %lf\n", *ptr);
    }
    else {
        printf("Absolute value: %lf\n", -*ptr);
    }
}
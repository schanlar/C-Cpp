/*
    Παράδειγμα 1: 
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έναν ακέραιο και να εμφανίζει την απόλυτη τιμή του.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num >= 0) {
        printf("Absolute value: %d\n", num);
    } 
    else {
        printf("Absolute value: %d\n", -num);
    }

    // Or simply:
    // printf("Absolute value: %d\n", abs(num));
    return 0;
}
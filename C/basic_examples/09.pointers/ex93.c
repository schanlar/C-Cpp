/*
    Παράδειγμα 10:
    Να γραφεί ένα πρόγραμμα το οποίο με τη χρήση δεικτών να διαβάζει 
    τις τιμές δύο ακεραίων και να τις αντιμεταθέτει.
*/

#include <stdio.h>

int main(void){
    int a, b, tmp;
    int *ptr1 = &a, *ptr2 = &b;

    printf("Enter two integers separated by space: ");
    scanf("%d %d", ptr1, ptr2);

    printf("Before swap: (a, b) = (%d, %d)\n", a, b);

    tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;

    printf("After swap: (a, b) = (%d, %d)\n", a, b);

    return 0;
}
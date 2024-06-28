/*
    Παράδειγμα 4:
    Να γραφεί ένα πρόγραμµα το οποίο να δηλώνει δύο πίνακες 10 ακεραίων και να τους αναθέτει τυχαίες τιµές.
    Επισης, να δηλώσετε 2 δείκτες και µε χρήση αυτών το πρόγραµμα να αντιγράφει τις τιμές του δεύτερου πινακα
    στον πρώτο πίνακα και να εμφανίζει τα στοιχεια και των δύο πινακων.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void){
    srand(time(NULL));

    int arr1[SIZE] = {0}, arr2[SIZE] = {0};
    int *ptr1 = arr1, *ptr2 = arr2;

    for (int i = 0; i < SIZE; i++){
        arr1[i] = (rand() % 10) + 1;
        arr2[i] = (rand() % 10) + 1;
    }

    // Display original arrays
    printf("Before:\n");
    printf("----------\n");
    printf("arr1:\n");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr1[i]);
    }
    printf("\n\narr2:\n");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr2[i]);
    }
    printf("\n----------\n");

    for (int i = 0; i < SIZE; i++){
        // ptr1[i] = ptr2[i]; // the obvious solution
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    ptr1 = arr1; // reset pointer to original
    ptr2 = arr2;

    // Display final arrays
    printf("After:\n");
    printf("----------\n");
    printf("arr1:\n");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", *(ptr1 + i));
    }
    printf("\n\narr2:\n");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", *(ptr2 + i));
    }
    printf("\n----------\n");

    return 0;
}
/*
    Παράδειγμα 8:
    Να γραφεί ένα πρόγραμμα το οποίο να δηλώνει ένα πίνακα 10 ακεραίων,
    να θέτει τυχαίες τιμές από 0 μέχρι 20 στα στοιχεία του και να εμφανίζει 
    τον μέσο όρο των τιμών του πίνακα
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void){
    srand(time(NULL));   // Initialization, should only be called once.

    int arr[SIZE], sum = 0;
    for (int i = 0; i < SIZE; i++){
        arr[i] = (rand() % 20) + 1; // rand % 20 generates a pseudo-random number between 0 and 19
        sum += arr[i];
        // printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("Avg value: %.1f\n", (float) sum / SIZE);

    return 0;
}
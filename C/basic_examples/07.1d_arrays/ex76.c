/*
    Παράδειγμα 19:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τους πληθυσμούς 100 πόλεων 
    και να τους αποθηκεύει κατά την εισαγωγή τούς σε έναν πίνακα με αύξουσα σειρά. 
    Το πρόγραμμα να εμφανίζει τον ταξινομημένο πίνακα πριν τερματίσει.
*/

// Implementation of the bubble sort algorithm

#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

#define SIZE 100

int main(void){
    // srand(time(NULL)); // for debugging
    int num, tmp, population[SIZE] = {0};

    for (int i = 0; i < SIZE; i++){
        printf("Enter population of city: ");
        scanf("%d", &num);
        population[i] = num;
        // population[i] = rand() % 10 + 1; // for debugging

        for (int j = 0; j < SIZE - 1; j++){
            if (population[i] < population[j]){
                tmp = population[i];
                population[i] = population[j];
                population[j] = tmp;
            }
        }
    }

    for (int i = 0; i < SIZE; i++){
        printf("%d\n", population[i]);
    }

    return 0;
}
/*
    Παράδειγμα 18:
    Να γραφεί ένα πρόγραμμα το οποίο να δηλώνει δύο πίνακες 10 ακεραίων και να διαβάζει 
    τις τιμές των στοιχείων τούς. Στη συνέχεια, να ελέγχει αν υπάρχουν κοινά στοιχεία στους 
    δύο πίνακες και, αν ναι, να εμφανίζει την τιμή του κάθε κοινού στοιχείου και τη θέση του 
    στους δύο πίνακες. Αλλιώς, να εμφανίζει ένα μήνυμα ότι δεν υπάρχουν κοινά στοιχεία.
*/

#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
#include <stdbool.h>

int main(void){
    // srand(time(NULL)); // for debugging
    int arr1[10], arr2[10];
    bool found = false;

    // // For debugging
    // for (int i = 0; i < 10; i++){
    //     arr1[i] = rand() % 10;
    //     arr2[i] = rand() % 10;
    // }

    for (int i = 0; i < 10; i++){
        printf("Enter number (arr1): ");
        scanf("%d", &arr1[i]);
        printf("Enter number (arr2): ");
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (arr1[i] == arr2[j]) {
                found = true;
                 printf("The number %d appears in arr1 at index %d, and in arr2 at index %d\n", arr1[i], i, j);
            }
        }
    }

    if (!found) printf("There are no common elements\n");
    return 0;
}
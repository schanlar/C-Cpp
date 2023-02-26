/*
    Παράδειγμα 4:
    Να γραφεί ένα πρόγραμμα τπ οποίο να δημιουργεί έναν τετραγωνικό 5 x 5 πίνακα,
    ο οποίος να είναι «άνω τριγωνικός» και τα στοιχεία του να έχουν τυχαίες ακέραιες 
    τιμές που να ανήκουν στο διαστημα [-3, 3]. Στη συνέχεια, το πρόγραμμα να εμφανίζει 
    την οριζουσα του πίνακα και τα στοιχεία του, υπο τη μορφή πίνακα 5 x 5 της γραμμικής άλγεβρας.

    Σημείωση: 
    «Άνω τριγωνικός» είναι κάθε τετραγωνικός πίνακας του οποίου όλα τα στοιχεία κάτω από την 
    κύρια διαγώνιο είναι ίσα με μηδέν. Σε κάθε τριγωνικό πίνακα η ορίζουσά του ισούται με το 
    γινόμενο των στοιχείων της κύριας διαγωνίού του.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));

    int arr[5][5] = {0}, det = 1;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i == j || i < j){
                // Formula to generate random numbers within a specific range:
                // number = (rand() % (upper - lower + 1)) + lower
                arr[i][j] = (rand() % 7) - 3;
            }

            if (i == j) det *= arr[i][j];
        }
    }

    // Print out determinant
    printf("Det = %d\n", det);
    // Print out matrix
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}


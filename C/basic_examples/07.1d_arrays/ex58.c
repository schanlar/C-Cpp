/*
    Παράδειγμα 1:
    Να γραφεί ένα πρόγραμμα το οποίο να δηλώνει έναν πίνακα 5 ακεραίων και να δίνει 
    τις τιμές 10, 20, 30, 40, 50 στα στοιχεία του. Στη συνέχεια το πρόγραμμα να εμφανίζει 
    τα στοιχεία του πίνακα που έχουν τιμή μεγαλύτερη από 20.
*/

#include <stdio.h>

int main(void){
    int array[5] = {10,20,30,40,50};

    for (int i = 0; i < 5; i++){
        if (array[i] > 20){
            printf("array[%d] = %d\n", i, array[i]);
        }
    }
    return 0;
}
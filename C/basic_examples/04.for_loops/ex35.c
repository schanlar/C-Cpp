/*
    Παράδειγμα 1: 
    Να γραφεί ένα πρόγραμμα το οποίο να εμφανίζει τους ακεραίους με αντίστροφη σειρά, από το 10 μέχρι και το 1.
*/

#include <stdio.h>

int main(void){
    for (int i = 10; i > 0; i--){
        printf("%d\n", i);
    }
    return 0;
}
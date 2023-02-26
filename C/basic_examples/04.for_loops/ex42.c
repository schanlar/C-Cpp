/*
    Παράδειγμα 8:
    Να γραφεί ένα πρόγραμμα το οποίο να εμφανίζει το άθροισμα όλων των ακέραιων αριθμών από το 1 έως και το 200.
*/

#include <stdio.h>

int main(void) {
    int sum = 0;
    for (int i = 1; i <= 200; i++) {
        sum += i;
    }
    printf("The sum of all integers in [1,200] is %d\n", sum);
    return 0;
}
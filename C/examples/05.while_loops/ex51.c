/*
    Παράδειγμα 1:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει συνεχώς έναν ακέραιο και να τον 
    εμφανίζει στην οθόνη μέχρι ο χρήστης να εισάγει 0 (το οποίο δεν θα πρέπει να το εμφανίζει).
*/

#include <stdio.h>

int main(void){
    int num;
    while (1) {
        printf("Enter an integer, or press 0 to terminate: ");
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        else {
            printf("%d\n", num);
        }
    }
    return 0;
}
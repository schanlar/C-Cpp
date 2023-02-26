/*
    Παράδειγμα 10:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έναν ακέραιο και με χρήση του τελεστή "? :", 
    να εμφανίζει ένα μήνυμα για το αν είναι θετικός ή αρνητικός. Αν είναι 0, να εμφανίζει zero.
*/

#include <stdio.h>

int main(void){
    int num;
     printf("Enter an integer: ");
     scanf("%d", &num);

    (num > 0) ? printf("Positive\n") : (num < 0) ? printf("Negative\n") : printf("Zero\n");

    return 0;
}
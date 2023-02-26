/*
    Παράδειγμα 9: Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έναν πραγματικό 
    και έναν ακέραιο αριθμό χωρισμένους με κενό και να εμφανίζει το υπόλοιπο της
    διαίρεσής τους. Για παράδειγμα, αν ο χρήστης εισάγει τους αριθμούς 7.29 και 
    4 το πρόγραμμα να εμφανίζει 3.24.
*/

#include <stdio.h>

int main(void){
    float a, rem;
    int b, res;
    printf("Enter a real number and an integer separated by space: ");
    scanf("%f %d", &a, &b);
    res = a / b;
    rem = a - (res * b);
    printf("Remainder: %.2f\n", rem);

    return 0;
}

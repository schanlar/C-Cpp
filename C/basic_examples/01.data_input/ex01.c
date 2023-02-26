/*
    Παράδειγμα 1: Να γράφει ένα πρόγραμμα το οποίο θα διαβάζει έναν ακέραιο και 
    έναν πραγματικό αριθμό χωρισμένους με κενό, και θα εμφανίζει το τριπλάσιο 
    του αθροίσματος τους.
*/

#include <stdio.h>

int main(void){
    int a;
    double b;
    // Promt user to enter two numers
    printf("Enter an integer and a real number separated by a space: ");
    scanf("%d %lf", &a, &b);

    // Print out the result
    printf("The result is: %.2lf\n", 3*(a + b));
    return 0;
}
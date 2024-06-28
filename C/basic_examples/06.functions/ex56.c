/*
    Παράδειγμα 1:
    Δημιουργήστε μία συνάρτηση που να δέχεται σαν παράμετρο την ακτίνα ενός κύκλου 
    και να επιστρέφει το εμβαδό του.
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει την ακτίνα και να εμφανίζει το εμβαδό του κύκλου με χρήση της συνάρτησης.
*/

#include <stdio.h>

#define PI 3.14159

// Function prototype
float areaCircle(float r);

int main(void){
    float radius;
    printf("Enter radius: ");
    scanf("%f", &radius);
    printf("The area is: %.1f\n", areaCircle(radius));
    return 0;
}

float areaCircle(float r) {
    return PI * r * r;
}
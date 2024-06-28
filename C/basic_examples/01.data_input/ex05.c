/*
    Παράδειγμα 5: Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει την ακτίνα ενός 
    κύκλου και να εμφανίζει το εμβαδό και την περιφέρεια του κύκλου.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.1415

int main(void){
    float radius;
    printf("Enter radius: ");
    scanf("%f", &radius);

    printf("Area of circle: %.2f\n", PI * pow(radius, 2));
    printf("Circumference of circle: %.2f\n", 2 * PI * radius);
}
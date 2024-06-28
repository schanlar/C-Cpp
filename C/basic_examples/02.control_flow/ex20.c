/*
    Παράδειγμα 8:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τις τιμές τεσσάρων προϊόντων 
    και να εμφανίζει τη μεγαλύτερη τιμή.
*/

#include <stdio.h>

int main(void){
    float prod1, prod2, prod3, prod4, max;
    printf("Enter prices: ");
    scanf("%f %f %f %f", &prod1, &prod2, &prod3, &prod4);

    max = prod1;
    if (prod2 > max) {
        max = prod2;
    }
    if (prod3 > max) {
        max = prod3;
    }
    if (prod4 > max) {
        max = prod4;
    }

    printf("Max price: %.2f\n", max);
    return 0;
}
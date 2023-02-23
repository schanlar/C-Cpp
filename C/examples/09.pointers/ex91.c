/*
    Παράδειγμα 8:
    Να γραφεί ένα πρόγραμμα το οποίο με τη χρήση δεικτών να διαβάζει τις τιμές 
    δύο προϊόντων και να εμφανίζει τη μεγαλύτερη τιμή.
*/

#include <stdio.h>

int main(void){

    float price1, price2;
    float *ptr1 = &price1, *ptr2 = &price2;

    printf("Enter product price: ");
    scanf("%f", ptr1);
    printf("Enter product price: ");
    scanf("%f", ptr2);

    if (*ptr1 > *ptr2){
        printf("Max: %f\n", *ptr1);
    }
    else {
        printf("Max: %f\n", *ptr2);
    }


    return 0;
}
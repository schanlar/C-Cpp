/*
    Παράδειγμα 3: Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει δύο ακεραίους 
    χωρισμένους με κενό και να εμφανίζει το άθροισμα, τη διαφορά, το γινόμενο, 
    το πηλίκο και το υπόλοιπο της διαίρεσής τους.
*/

#include <stdio.h>

int main(void){
    int a, b;
    // Promt user to enter two integers
    printf("Enter two integer numbers separated by a space: ");
    scanf("%d %d", &a, &b);
    printf("Sum: %d\n", (a+b));
    printf("Difference: %d\n", (a-b));
    printf("Product: %d\n", (a*b));
    printf("Division: %f\n", (float) a / b);
    printf("Modulo: %d\n", (a%b));

    return 0;
}
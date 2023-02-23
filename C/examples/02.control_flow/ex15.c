/*
    Παράδειγμα 3:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει δύο ακεραίους και να εμφανίζει 
    το αποτέλεσμα της σύγκρισής τούς χωρίς χρήση της εντολής else.
*/

#include <stdio.h>

int main(void){
    int a, b;
    printf("Enter two integers separated by space: ");
    scanf("%d %d", &a, &b);

    // Or use 3 separate if statements but in this case
    // all three conditions will be evaluated.
    if (a == b){
        printf("The numbers are equal!\n");
    }
    else if (a < b) {
        printf("%d is larger than %d\n", b, a);
    }
    else if (a > b) {
        printf("%d is larger than %d\n", a, b);
    }
    return 0;
}
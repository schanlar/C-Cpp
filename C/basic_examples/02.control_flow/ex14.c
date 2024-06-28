/*
    Παράδειγμα 2:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τους βαθμούς 
    δύο φοιτητών και να τους εμφανίζει με αυξούσα σειρά.
*/

#include <stdio.h>

int main(void){
    float grade1, grade2;
    printf("Enter two grades separated by space: ");
    scanf("%f %f", &grade1, &grade2);

    if (grade1 > grade2) {
        printf("%.2f %.2f\n", grade1, grade2);
    }
    else {
        printf("%.2f %.2f\n", grade2, grade1);
    }
    return 0;
}
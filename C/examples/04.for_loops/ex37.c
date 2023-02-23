/*
    Παράδειγμα 3:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τους βαθμούς 10 φοιτητών και 
    να εμφανίζει αυτούς που ανήκουν στο [5,10].
*/

#include <stdio.h>

int main(void){
    float grade;
    for (int i = 0; i < 10; i++){
        printf("Enter grade: ");
        scanf("%f", &grade);

        if (grade >= 5 && grade <= 10) {
            printf("%.2f\n", grade);
        }
    }
    return 0;
}
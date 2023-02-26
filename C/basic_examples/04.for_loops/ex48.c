/*
    Παράδειγμα 14:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έναν ακέραιο που να ανήκει στο [0, 170], 
    να υπολογίζει το παραγοντικό του και να το εμφανίζει.
*/

#include <stdio.h>


int main(void){
    int num;
    long double res = 1.0;
    do {
        printf("Enter an integer in [0, 170]: ");
        scanf("%d", &num);
    } while (num < 0 || num > 170);

    for (int i = 1; i <= num; i++) {
        res *= i;
    }
    printf("%d! = %.0Lf\n", num, res);
    return 0;
}
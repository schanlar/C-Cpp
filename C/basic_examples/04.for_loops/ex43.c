/*
    Παράδειγμα 9:
    Να γραφεί ένα πρόγραμμα το οποίο να εμφανίζει το γινόμενο όλων των περιττών αριθμών από το 1 έως το 20.
*/
#include <stdio.h>

int main(void){
    int res = 1;
    for (int i = 1; i <= 20; i++){ 
        // Alternative we could have increased the step by two, i.e. i = i + 2
        if (i % 2 != 0){
            res *= i;
        }
    }
    printf("The product of all odd numbers in [1,20] is: %d\n", res);
    return 0;
}
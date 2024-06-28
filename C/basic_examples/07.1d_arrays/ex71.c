/*
    Παράδειγμα 14:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τις θερμοκρασίες του μηνός Ιουλίου, 
    να τις αποθηκεύει σε έναν πίνακα και στη συνέχεια να εμφανίζει τις δύο μεγαλύτερες θερμοκρασίες.
*/

#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

#define SIZE 31

int main(void){
    // srand(time(NULL)); // for debugging

    float temp, julyTemps[SIZE], max1 = -100.0, max2 = -100.0;
    for (int i = 0; i < SIZE; i++){
        printf("Enter temperature for day %d\n", i);
        scanf("%f", &temp);
        // temp = rand() % 10; // for debugging
        julyTemps[i] = temp;

        if (temp > max1) {
            max2 = max1; // pass previous max temp to max2 before updating max1
                         // to current total max temp 
            max1 = temp;
        }
        else if (temp < max1 && temp > max2){
            max2 = temp;
        }
    }
    
    if (max2 == -100) {
        printf("In July we recorded a temperature of %.1f deg with no variatons!", max1);
        return 0;
    }
        
    printf("First max: %.1f deg\nSecond max: %.1f deg\n", max1, max2);
    return 0;
}
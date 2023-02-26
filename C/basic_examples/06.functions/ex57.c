/*
    Παράδειγμα 2:
    Δημιουργήστε δύο συναρτήσεις που να δέχονται σαν παράμετρο έναν ακέραιο η καθεμία 
    και να επιστρέφουν το τετράγωνο και τον κύβο του αριθμού, αντίστοιχα. 
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έναν ακέραιο και να εμφανίζει το άθροισμα 
    του τετραγώνου του και του κύβου του αριθμού με χρήση των συναρτήσεων.
*/

#include <stdio.h>

// Function prototype
int square(int x);
int cube(int x);

int main(void){
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("Square: %d\nCube: %d\n", square(num), cube(num));
    return 0;
}

int square(int x){
    return x * x;
}

int cube(int x){
    return x * x * x;
}
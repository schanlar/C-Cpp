/*
    Παράδειγμα 12: Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει ένα διψήφιο 
    θετικό ακέραιο και να εμφανίζει τον αντίστροφο του. Για παράδειγμα, αν ο 
    χρήστης εισάγει τη τιμή 72, το πρόγραμμα να εμφανίζει 27. Χρησιμοποιήστε 
    μία μόνο μεταβλητή. Κάντε το ίδιο και με έναν τριψήφιο αριθμό.
*/

#include <stdio.h>
#include <string.h>

int main(void){

    // // Solution for 2 digit number
    int num;
    printf("Enter a positive integer with 2 decimal digits: ");
    scanf("%d", &num);
    printf("%d%d\n", num%10, num/10);

    // // Solution for 3 digit number
    // int num;
    // printf("Enter a positive integer with 3 decimal digits: ");
    // scanf("%d", &num);
    // printf("%d%d%d\n", num%10, (num%100)/10, num/100);


    // // two-to-one solution using string arrays
    // // Up to 3 digits + null terminator
    // char str[4];
    // printf("Enter a positive integer up to 3 decimal digits: ");
    // scanf("%s", str);
    // for (int i = strlen(str) - 1; i >= 0; i--){
    //     printf("%c", str[i]);
    // }
    // printf("\n");

    return 0;
}
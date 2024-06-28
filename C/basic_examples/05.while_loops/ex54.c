/*
    Παράδειγμα 4:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει συνεχώς έναν ακέραιο και να εμφανίζει το μήνυμα "Hello" 
    τόσες φορές όσες και η τιμή του ακεραίου. Η εισαγωγή ακεραίων να σταματάει αν ο χρήστης εισάγει αρνητικό αριθμό. 
    Επίσης, το πρόγραμμα πριν τερματίσει να εμφανίζει τον συνολικό αριθμό των "Hello" μηνυμάτων 
    που εμφανίστηκαν στην οθόνη.
*/

#include <stdio.h>

int main(void){
    int num, sum = 0;
    while (1) {
        printf("Enter a positive integer, or a negative to exit: ");
        scanf("%d", &num);

        if (num < 0) {
            break;
        }
        else {
            sum += num;
            for (int i = 0; i < num; i++) {
                printf("Hello\n");
            }
        }
    }
    printf("Total number: %d\n", sum);
    return 0;
}
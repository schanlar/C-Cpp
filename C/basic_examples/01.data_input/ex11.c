/*
    Παράδειγμα 11: Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έναν ακέραιο και
    να τον αναλύει σε 50-άδες, 20-άδες, 10-άδες και μονάδες. Για παράδειγμα, αν 
    ο χρήσης εισάγει τον αριθμό 285, το πρόγραμμα να εμφανίζει: 5*50, 1*20,
    1*10, 5*1.
*/

#include <stdio.h>

int main(void){
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("%d*50, %d*20, %d*10, %d*1\n", num/50, (num%50)/20, ((num%50)%20)/10, (((num%50)%20)%10)/1);
    return 0;
}
/*
    Παράδειγμα 9:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έναν ακέραιο και να εμφανίζει ένα μήνυµα
    για το αν είναι άρτιος ή περιττός.
*/

#include <stdio.h>

int main(void){
    int num;
    printf("Enter integer: ");
    scanf("%d", &num);

    if (num & 1){
		printf("The number %d is odd\n", num);
    }
	else {
		printf("The number %d is even\n", num);
    }

    // Another way:
    // if (num % 2 == 0) {
    //     printf("The number %d is even\n", num);
    // }
    // else {
    //     printf("The number %d is odd\n", num);
    // }
    return 0;
}

/*
    Σχόλια: 
    Για να διαπιστώσουµε αν ένας αριθµός είναι άρτιος ή περιττός ελέγχουµε το τελευταίο bit του αριθµού. 
    Av είναι 0, ο αριθµός είναι άρτιος.
*/
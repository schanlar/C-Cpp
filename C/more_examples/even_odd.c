/*
    Να γραφεί ένα πρόγραμμα που να γεμίζει ένα πίνακα δέκα θέσεων με τυχαίους θετικούς ακέραιους αριθμούς.
    Το πρόγραμμα να χωρίζει τους αριθμούς σε δύο πίνακες, έναν με όλους τους άρτιους και έναν με όλους
    τους περιττούς, τους οποίους θα εκτυπώνει. Για λόγους ελέγχου θα πρέπει κάθε φορά να δείχνετε ότι το 
    τελικό άθροισμα των στοιχείων του αρχικού πίνακα, με όλους τους τυχαίους αριθμούς, ισούται με το άθροισμα
    των μερικών αθροισμάτων των δύο επιμέρους πινάκων των άρτιων και περιττών αριθμών.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void){
    srand(time(NULL));

    int randomNums[SIZE], evenNums[SIZE] = {0}, oddNums[SIZE] = {0};
    int sumRandomNums = 0, sumEvenNums = 0, sumOddNums = 0, idxEven = 0, idxOdd = 0;

    for (int i = 0; i < SIZE; i++){
        randomNums[i] = (rand() % 10000) + 1;
        sumRandomNums += randomNums[i];
        if (randomNums[i] % 2 == 0){
            evenNums[idxEven] = randomNums[i];
            sumEvenNums += evenNums[idxEven];
            idxEven++;
        }
        else {
            oddNums[idxOdd] = randomNums[i];
            sumOddNums += oddNums[idxOdd];
            idxOdd++;
        }
    }
    for(int i = 0; i < 43; i++) printf("-");
    printf("\n");
    printf("Random numbers\tEven numbers\tOdd numbers\n");
    printf("**************\t************\t***********\n");
    for (int i = 0; i < SIZE; i++){
        printf("%14d\t%12d\t%11d\n", randomNums[i], evenNums[i], oddNums[i]);
    }
    printf("**************\t************\t***********\n");
    printf("%14d\t=%11d\t+%10d\n", sumRandomNums, sumEvenNums, sumOddNums);
    for(int i = 0; i < 43; i++) printf("-");
    printf("\n");


    return 0;
}
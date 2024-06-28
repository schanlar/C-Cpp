/*
    Παράδειγμα 20:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τούς ακεραίους κωδικούς 50 προϊόντων
    και να τους αποθηκεύσει σε έναν πίνακα. Το πρόγραμμα πριν αποθηκεύσει κάποιον κωδικό 
    πρέπει να ελέγχει αν ήδη υπάρχει και μόνο αν δεν υπάρχει να τον αποθηκεύει στον πίνακα.
    Δηλαδή, όλα τα στοιχεία του πίνακα πρέπει να είναι διαφορετικά μεταξύ τους.
*/

#include <stdio.h>
#include <stdbool.h>


#define SIZE 50

int main(void){
    int num, barcodes[SIZE] = {0};
    bool codeExists;

    for (int i = 0; i < SIZE; i++){
        enterCode:
            codeExists = false;
            printf("Enter product code: ");
            scanf("%d", &num);
        
            for (int j = 0; j < SIZE; j++){
                if (barcodes[j] == num){
                    printf("Product code already exists\n");
                    codeExists = true;
                    break;
                }
            }

        if (!codeExists) {
            barcodes[i] = num;
        }
        else {
            goto enterCode;
        }
    }

    for (int i = 0; i < SIZE; i++){
        printf("%d\n", barcodes[i]);
    }

    return 0;
}
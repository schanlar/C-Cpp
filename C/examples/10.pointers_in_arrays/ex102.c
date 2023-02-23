/*
    Παράδειγμα 7: 
    Να συμπληρώσετε το παρακάτω πρόγραµµα χρησιμοποιώντας τη µεταβλητή num για να διαβάσετε τους 
    ακεραίους κωδικούς 100 προϊόντων και τους δείκτες ptr1 και ptr2 για να τους αποθηκεύσετε στον πίνακα arr.
    'Ενας κωδικός να αποθηκεύεται στον πίνακα μόνο αν δεν έχει ήδη αποθηκευτεί. 
    Το πρόγραµµα να εμφανίζει τους κωδικούς πριν τερµατίσει.


    #include <stdio.h>
    #define SIZE 100
    int main(){

        int *ptr1, *ptr2;
        int num, arr[SIZE];
    ...
    }
*/

#include <stdio.h>
#define SIZE 100
int main(){
    int *ptr1, *ptr2;
    int num, arr[SIZE];

    ptr1 = &num;
    ptr2 = arr;

    for (int i = 0; i < SIZE; i++){
        enterCode:
            printf("Enter product code: ");
            scanf("%d", &num);
            for (int j =0; j < SIZE; j++){
                if (num == arr[j]){
                    printf("Product code already exists\n");
                    goto enterCode;
                }
            }
        *ptr2 = *ptr1;
        ptr2++;
    }
    ptr2 = arr; // reset pointer to original 

    for (int i = 0; i < SIZE; i++){
        printf("%d\n", *(ptr2 + i));
    }

}
/*
    Παράδειγμα 2:
    Να συμπληρώσετε το παρακάτω πρόγραµμα χρησιµοποιώντας τον δείκτη ptr για να διαβάσετε
    και να αποθηκεύσετε τους βαθμούς 50 φοιτητών στον πίνακα arr και να εμφανίσετε τις τιµές
    του πίνακα με αντίστροφη σειρά.


    #include <stdio.h>
    #define SIZE 50
    int main()
    {
    float arr[SIZE], *ptr; 
    ...
    }
*/

    #include <stdio.h>

    #define SIZE 10

    int main(){
        float arr[SIZE], *ptr; 
        ptr = arr;

        for (int i = 0; i < SIZE; i++){
            printf("Enter a number: ");
            scanf("%f", &ptr[i]);
        }

        for (int i = SIZE - 1; i >= 0; i--){
            printf("%f\n", ptr[i]);
        }

    }
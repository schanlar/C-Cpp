/*
    Παράδειγμα 1: 
    Ποιά είναι η έξοδος του παρακάτω προγράμματος;
*/

#include <stdio.h>
int main()
{
int *ptr;
int i, arr[5] = {10, 20, 30, 40, 50};
ptr = arr + 2;

// Notice that each element of the integer array occupies 4 bytes
for(i = 0; i < 5; i++) printf("Addr = %p  Val = %d\n", &ptr[i], ptr[i]);

// Also notice that the address of the array referes to the address of its first element
// printf("%p\n", &arr);
return 0;
}

/*
    Απάντηση: 
    Με την εντολή ptr = arr+2, o ptr δείχνει στο τρίτο στοιχείο του πίνακα arr, δηλαδή στο arr[2]. 
    Άρα, χρησιμοποιώντας τον δείκτη ptr σαν πίνακα, το ptr [0] αντιστοιχεί στο arr[2], 
    το ptr[1] στο arr[3] και το ptr[2] στο arr[4].

    Αφού ο πίνακας arr έχει πέντε στοιχεία, ποιες είναι οι τιμές των ptr[3] και ptr[4];

    Οι τιμές τους είναι οι τυχαίες τιµές που περιέχει η µνήµη στις δύο επόμενες θέσεις μνήµης, 
    µετά τη διεύθυνση μνήμης του στοιχείου arr[4]

    Επομένως, το πρόγραµμα εμφανίζει: 30 40 50 και δύο τυχαίες τιμές.
*/
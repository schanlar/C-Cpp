/*
    Παράδειγμα 9:
    Nα συμπληρώσετε το παρακάτω πρόγραµµα χρησιμοποιώντας τον δείκτη ptr και εναν 
    επαναληπτικό βρόχο για να μειώσετε τις τιµές των στοιχείων του πινακα arr κατά ένα.
    Το πρόγραµµα να εµφανίζει το αθροισμα τους πριν τερµατίσει.


    #include <stdio.h>
    int main(){

    int *ptr;
    int arr[5] = {11, 21, 31, 41, 51};

    ...

    return 0;
    }
*/

#include <stdio.h>
int main(){

int *ptr;
int arr[5] = {11, 21, 31, 41, 51}, sum = 0;

for (ptr = arr; ptr <= arr+4; ptr++){
    --*ptr; // or, equivalently: *ptr = *ptr - 1
    sum += *ptr;
    // printf("%d\n", *ptr);
}
printf("Sum = %d\n", sum);
return 0;
}

/*
    Σχόλια:
    Ο for βρόχος εκτελείται μέχρι ο ptr να δείξει και στο τελευταίο στοιχείο του πίνακα.

    Για παράδειγµα, στην πρώτη επανάληψη του βρόχου ο ptr με την εντολή ptr = arr δείχνει 
    στο πρώτο στοιχείο του πίνακα. Άρα, η τιµη του *ptr, είναι ίση µε την τιµή του arr [0] , δηλαδή 11.

    Η εντολή --*ptr; µειώνει κατά ένα το περιεχόµενο της διευθυνσης στην οποία δείχνει o ptr, άρα η τιµή 
    του arr[0] γίνεται 10. Παρομοίως, στις επόμενες επαναλήψεις, ελαττώνονται κατα ενα και οι τιµες, 
    των υπολοιπων στοιχείων του πίνακα. Άρα, οι τιµές τους γινονται 10, 20, 30, 40 και 50.

    H εντολή sum+= *ptr; προσθέτει κάθε φορα στη µεταβλητη Val το περιεχόμενο της διεύθυνσης στην οποία 
    δείχνει ο ptr. Επομενως η τιµη της val Θα γίνει ίση µε το άθροισµα των τιµών των στοιχείων του πινακα,
    και το πρόγραµμα εµφανίζει: Sum = 150
*/
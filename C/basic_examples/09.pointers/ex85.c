/*
    Παράδειγμα 2:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει δύο ακεραίους, να δηλώνει δύο δείκτες προς αυτούς 
    και να εμφανίζει τις διευθύνσεις των ακεραίων μεταβλητών, τα περιεχόμενα των δεικτών 
    και τις διευθύνσεις μνήμης των δεικτών.
*/

#include <stdio.h>

int main(void){

    int num1, num2;
    int *ptr1 = &num1, *ptr2 = &num2;

    printf("Enter two integers separated by space: ");
    scanf("%d %d", &num1, ptr2);

    printf("Address of integers: &num1 = %p, &num2 = %p\n", &num1, &num2);
    printf("Dereference pointers: num1 = %d, num2 = %d\n", *ptr1, *ptr2);
    printf("Address of pointers: &ptr1 = %p, &ptr2 = %p\n", &ptr1, &ptr2); 

    printf("%d\n", &num1 == ptr1);
    printf("%d\n", &num2 == ptr2);
    return 0;
}

/*
    Σχόλια:
    Οι δείκτες ptr1 και ptr2 είναι και αυτοί μεταβλητές, επομένως έχει δεσμευτεί και για αυτούς μνήμη. 
    Για να εμφανίσουμε τις διευθύνσεις μνήμης χρησιμοποιούμε τον τελεστή &,όπως και με τις υπόλοιπες μεταβλητές.
*/
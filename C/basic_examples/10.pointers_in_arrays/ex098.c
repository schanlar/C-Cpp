/*
    Παράδειγμα 3:
    Ποια είναι η έξοδος του παρακάτω προγράμματος;
*/

#include <stdio.h>

int main(){
	int *ptr1, *ptr2;
	int i = 10;

	ptr1 = &i;
	ptr2 = ptr1;

	*ptr1 = *ptr1 + *ptr2;
	*ptr2 = 2*(*ptr2);
	i += *ptr1;
	printf("Val = %d\n", *ptr2);
	return 0;
}

/*
    Απάντηση:
    Αφού ο ptr1 δείχνει στη διεύθυνση του i, το *ptr1 θα είναι ίσο µε την τιμή του i.
    Με την εντολή ptr2 = ptr1; ο ptr2 δείχνει εκεί που δείχνει ο ptr1, δηλαδή στη διεύθυνση της μεταβλητής i.
    Επομένως, το *ptr2 θα είναι ίσο µε την τιµή του i.

    Αφού και οι δύο δείκτες δείχνουν τη διεύθυνση του i, η εντολή *ptr1 = *ptr1 + *ptr2 ; ισοδυναμεί με i = i + i = 10 +10 = 20.
    Παρόµοια, η εντολή *ptr2 = 2 * (*ptr2); Ισοδυναμεί με i = 2 * i = 2 * 20 = 40, ενώ η εντολή i += *ptr1; με i = i+i = 40+40 = 80.

    Αφού ο ptr2 εξακολουθεί να δείχνει στη διεύθυνση του i, το πρόγραμμα εμφανίζει Val = 80.
*/
/*
    Παράδειγμα 3:
    Ο σκοπός του παρακάτω προγράμματος είναι να διαβάσει έναν πραγματικό αριθμό 
    με χρήση δείκτη και να τον εμφανίσει. Υπάρχει λάθος στον κώδικα;
*/

#include <stdio.h>
int main()
{
	double *ptr; // example of wild pointer. Not to be confused with a dangling pointer.
	double i;
	
	scanf("%lf", ptr);
	printf("Val = %lf\n", *ptr); // Bus error: 10 => tries to access an invalid address
	return 0;
}

/*
    Απάντηση:
    Το λάθος είναι ότι ο ptr δεν δείχνει τη διεύθυνση της μεταβλητής i, πριν χρησιμοποιηθεί στη scanf().
    Άρα, για να εκτελεστεί το πρόγραμμα σωστά πρέπει να προστεθεί η εντολή ptr = &i πριν από τη scanf().
*/
/*
    Παράδειγμα 5:
    Υπάρχει προγραμµατιστικό λάθος στο παρακάτω πρόγραμµα; Αν όχι, ποια είναι η έξοδος του προγράµµατος;
*/

#include <stdio.h>
int main()
{
	int i, arr[5] = {10, 20, 30, 40, 50};

	for(i = 0; i < 5; i++)
		printf("%d\n", i[arr]);

	printf("%d\n", 2[arr]-3[arr]);
	return 0;
}

/*
    Απάντηση:
    Το φυσιολογικό είναι να απαντήσετε ότι η έκφραση i [arr] είναι λανθασμένη και η σωστή είναι η arr[i], 
    αφού η µεταβλητή arr είναι αυτή που έχει δηλωθεί σαν πίνακας και όχι η i. 
    Για τον ίδιο λόγο, οι εκφράσεις 2[arr] και 3[arr] φαίνονται επίσης λανθασμένες.

    Ωστόσο, ο μεταγλωττιστής µεταφράζει το i[arr] σε *(i + arr), το οποίο είναι ισοδύναµο µε *(arr + i),
    το οποίο με τη σειρά του είναι ισοδύναμο µε arr[i]. Για παράδειγμα, η τιµή του 2[arr] είναι ίση µε το arr[2].

    Άρα, believe it or not, το πρόγραµµα εκτελείται κανονικά και εμφανίζει τις τιμές των στοιχείων του πίνακα,
    καθώς και τη διαφορά των arr [2] και arr [3] , η οποία είναι -10.

    Προφανώς και συστηνουμε να µην χρησιµοποιήσετε ποτε αυτη την «ανάπoδη» σύνταξη. 
    Απλώς αυτό τα πρόγραμµα απεικονιζει τη στενη σχεση πινακα και δείκτη µε έναν πραγµατικά ιδιόµορφο τρόπο.
*/
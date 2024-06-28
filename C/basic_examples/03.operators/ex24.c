/*
    Παράδειγμα 1:
    Ποια είναι η έξοδος του παρακάτω προγράμματος;
*/


#include <stdio.h> 
int main(void)
{
	int a = 2, b = 2, c = 2;
	printf("%d\n", a == b == c);
	return 0;
}

/*
    Απάντηση: 
    Πρώτα γίνεται ο έλεγχος της έκφρασης (α == b) . Αφού τα α και b είναι ίσα  η τιμή της είναι 1. 
    Αρα, η έκφραση (α == b == c) είνα ισοδύναμη με (1 == c) . Το αποτέλεσμα αυτής της σύγκρισης είναι 0, 
    γιατί το c είναι 2.

    Επομένως, το πρόγραμμα εμφανίζει 0. Αν η τιμή του c ήταν 1, το πρόγραμμα θα εμφάνιζε 1.
*/
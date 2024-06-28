/*
    Παράδειγμα 11: Ποια είναι η έξοδος τον παρακάτω προγράμματος;
*/

#include <stdio.h> 
int main ()
{
	int a = 1; 
	switch (a)
	{
	    case 1:
			printf("One\n"); 
		    return 0;

		case 2:
			printf("Two\n");
		    break;
	}
	printf("End\n");
	return 0;
}

/*
    Απάντηση:
    Η εντολή return, τερματίζει όχι μόνο την εκτέλεση της  switch εντολής, αλλά και 
    την εκτέλεση της συνάρτησης στην οποία ανήκει.

    Αφού η τιμή της μεταβλητής a είναι 1, το πρόγραμμα θα εμφανίσει One  και στη συνέχεια η εντολή return 
    τερματίζει το πρόγραμμα. Άρα, το End δεν θα εμφανιστεί.
*/
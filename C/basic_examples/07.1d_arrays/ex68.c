/*
    Παράδειγμα 11:
    Το παρακάτω πρόγραμμα διαβάζει 10 ακεραίους, τους αποθηκεύει σε έναν πίνακα και 
    στη συνέχεια αποθηκεύει στον πίνακα freq το πλήθος των εμφανίσεων του κάθε αριθμού. 
    Υπάρχουν λάθη στο κώδικα;
*/

#include <stdio.h>
#define size 10 // Capitalized letters 
int main(void)
{
	int i, num, arr[SIZE], freq[SIZE]; // SIZE here is undefined since C is case sensitive

	for (i = 0; i < SIZE; i++){
		scanf("%d", &arr[i]); 
    }

	for (i = 0; i < SIZE; i++)
	{
		num = arr[i];
		freq[num]++; // Buffer overflow if user enters an integer >= SIZE
                    // Also, freq array has not been initialized so here we increment a random value by one
	}

	printf("\nNumber occurrences\n");

	for(i = 0; i < SIZE; i++) {
		printf("Num %d appears %d times\n", arr[i], freq[i]);
    }
	return 0;
}

/*
    Απάντηση:
    Το πρώτο λάθος είναι ότι τα στοιχεία του πίνακα freq δεν έχουν  αρχικοποιηθεί με μηδέν, 
    οπότε η εντολή freq[num]++ απλά αυξάνει την τυχαία τιμή του στοιχείου freq[num] κατά ένα.

    Ωστόσο, το σοβαρό λάθος εμφανίζεται σε περίπτωση που ο χρήστης εισάγει κάποιον αριθμό μεγαλύτερο 
    ή ίσο της διάστασης του πίνακα freq, δηλαδή του 10.

    Για παράδειγμα, αν ο χρήστης εισάγει τον αριθμό 50, τότε, όταν γίνει num = 50 η εντολή freq[50]++ θα αλλάξει 
    το περιεχόμενο μιας θέσης μνήμης εκτός των επιτρεπόμενων ορίων του πίνακα, με απρόβλεπτες συνέπειες για το πρόγραμμα.
*/
/*
    Παράδειγμα 9:
    Θεωρήστε ότι το test.txt ειναι ένα αρχείο κειμένου.
    Ποια είναι η έξοδος του παρακάτω προγράμματος;
*/

#include <stdio.h>

int main(){

	FILE *fp;
	char ch;
	
	if((fp = fopen("test.txt", "r")) != NULL)
	{
		while(ch = getc(fp) != EOF)
			putc(ch,stdout);
		fclose(fp);
	}
	return 0;
}

/*
    Απάντηση:
    Αν η while εντολή είχε γραφτεί σωστά, το πρόγραμμα θα εμφάνιζε τους χαρακτήρες του αρχείου.
    Η σωστή σύνταξη είναι:

    while((ch = getc(fp)) != EOF)

    Οι εσωτερικές παρενθέσεις χρειάζονται για λόγους προτεραιότητας. Τώρα που λείπουν, η έκφραση
    getc(fp) != EOF είναι η πρώτη που εκτελείται και η τιμή της είναι πάντα 1,
    όσο δεν έχουμε φτάσει στο τέλος του αρχείου.
    Επομένως, η τιμή της ch γίνεται 1 και το πρόγραμμα εμφανίζει κάθε φορά τον χαρακτήρα που έχει
    αυτη την ASCII τιμή. Οταν η getc() επιστρέψει EOF , η τιμή της έκφρασης και της ch γίνεται 0
    και ο βρόχος τερματίζει.
*/
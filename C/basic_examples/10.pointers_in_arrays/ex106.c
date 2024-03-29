/*
    Παράδειγμα 11:
    Ποια ειναι η εξοδος του παρακατω προγράμματος;
*/

#include <stdio.h>
int main(){

	int a[] = {0, 0, 1, 2, 3}, b[] = {0, 0, 4, 5, 6};
	int *ptr1 = a, *ptr2 = b;

	while(!*ptr1++ && !*ptr2++);
	// printf("%d %d\n", ptr1-a, ptr2-b);
    printf("%d %d\n", ptr1 - a, ptr2 - b); // ptr1 points 3 positions after a => ptr1 - a = 3
                                           // ptr2 points 2 positions after b => ptr2 - b = 2
	return 0;
}

/*
    Απάντηση: 
    Ειπαμε να τελείωσουµε αυτή την ενότητα µε µία αρκετά δύσκολη άσκηση.
    Ας αναλύσουμε τη συνθήκη του βρόχου για να δούµε πότε θα τερματιστεί η εκτελεση του.

    Καταρχας προσέξτε ότι η εκφραση !*ptr1++ πρωτα αντιστρεφει το περιεχόμενο του δεικτη ptr1 
    και µετά αυξάνει την τιµή του δείκτη!

    Για παραδειγμα, στην πρώτη επανάληψη του βρόχου, αφού ο ptr1 δείχνει στο πρώτο στοιχείο του πίνακα a, 
    η τιµή του *ptr1 είναι ίση με a[0], δηλαδή 0. Αυτή η τιµη αντιστρεφεται µε τον ! τελεστή και γίνεται 1. 
    Στη συνέχεια, αυξάνεται η τιμή του ptr1 και δείχνει στο επόµενο στοιχείο του πίνακα a.

    Αντίστοιχα, η τιµή της έκφρασης !*ptr2++ είναι επίσης 1. Άρα, και οι δύο όροι είναι αληθείς, οπότε συνεχίζεται
    η εκτέλεση του βρόχου.

    Παρόμοια με πριν, στη δεύτερη επανάληψη, οι τιµές των !*ptr++ και !*ptr2++ είναι επίσης 1.

    Στην τρίτη επανάληψη, αφού ο ptr1 δείχνει στο τρίτο στοιχείο του πίνακα, η τιµή του !*ptr1++ είναι 0 και µε την 
    αύξηση ο ptr1 δείχνει στο τέταρτο στοιχείο.

    Προσοχή τώρα, γιατί εδώ βρίσκεται το κλειδί της απάντησης: Θυµηθείτε ότι αν ο όρος που ελέγχεται σε µία έκφραση 
    µε τον τελεστή είναι ψευδής, τότε οι υπόλοιποι όροι δεν ελέγχονται και η τιμή της έκφρασης γίνεται 0 (false + anything = false). 
    Άρα, η τιµή της έκφρασης στη συνθήκη της while γίνεται 0 και η εκτέλεση του βρόχου τερµατίζεται. Επίσης, αφού ο 
    όρος ! *ptr2++ δεν ελέγχεται, η τιµή του ptr2 δεν αυξάνεται.

    Εποµένως, αφού ο ptr1 δείχνει στο τέταρτο στοιχείο και ο ptr2 στο τρίτο στοιχείο, το πρόγραµµα εµφανίζει: 3 2

    Και για να «το χάσετε» εντελώς, ποια θα είναι η έξοδος του προγράµματος αν αντικαταστήσουμε 
    τον τελεστή && µε τον τελεστη || δηλαδη, αν γραψουµε:

        while (!*ptr1++ || !*ptr2++);

    Η απάντηση είναι: 5 3

    Αυτό συμβαίνει γιατί αν σε μία συνθήκη "condition1 || condition2" η πρώτη συνθήκη είναι αληθής, τότε η δεύτερη 
    συνθήκη ΔΕΝ εξετάζεται (για λόγους επίδοσης) καθώς "true || anything" θα είναι πάντα αληθές.
    Έτσι, με την ίδια λογική με πριν, ο βρόγχος θα τερματιστεί όταν ο ptr1 δείχνει εκτός της λίστας a (θέση a[5])
    και άρα θα δείχνει 5 θέσεις μακριά από το πρώτο στοιχείο του πίνακα a. 
    Αντίστοιχα, ο ptr2 θα δείχνει στην θέση b[3], δηλαδή 3 θέσεις μακριά από το πρώτο στοιχείο του πίνακα b.
    Τελικά, το πρόγραμμα θα τυπώνει: 5 3 
    (η έκφραση ptr1 - a ισοδυναμεί με ptr1 - &a[0] = &a[5] - &a[0] και αντίστοιχα
    για τον πίνακα b: ptr2 - b = ptr2 - &b[0] = &b[3] - &b[0])
*/
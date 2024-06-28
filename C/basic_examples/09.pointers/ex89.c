/*
    Παράδειγμα 6:
    Ποια είναι η έξοδος του παρακάτω προγράμματος;
*/


#include <stdio.h>

int main()
{
	int i = 0, *ptr = &i;
	
	*ptr = *ptr ? 10 : 20;
	printf("Val = %d\n", i);
	return 0;
}

/*
    Απάντηση:
    Αφού ο ptr δείχνει στη διεύθυνση του i με έκφραση:

    *ptr = *ptr ? 10 : 20; είναι ισοδύναμη με i = i ? 10 : 20;

    Αφού η τιμή του i είναι 0(ψευδής), το αποτέλεσμα της έκφρασης είναι 20. 
    Άρα, η τιμή του i γίνεται 20 και το πρόγραμμα εμφανίζει: Val = 20.
*/
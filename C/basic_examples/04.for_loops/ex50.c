/*
    Παράδειγμα 16:
    Ποια είναι η έξοδος του παρακάτω προγράμματος;
*/

#include <stdio.h> 
int main(void)
{
	int i;
	for(i = 0;  i ? 0 : i+1; i++){
		printf("%d\n", i);
    }
	return 0;
}

/*
    Απάντηση:
    Στην πρώτη επανάληψη του βρόχου, αφού η τιμή του i είναι 0, η τιμή της συνθήκης ί ? 0 :  i + 1 είναι i + 1 = 1.
     Άρα, ο βρόχος εκτελείται και το πρόγραμμα εμφανίζει 0.

    Στη δεύτερη επανάληψη του βρόχου, η τιμή του i γίνεται 1, άρα η τιμή της συνθήκης i ? 0 : i+1 είναι 0 
    και ο βρόχος τερματίζεται.
*/
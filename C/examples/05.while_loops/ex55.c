/*
    Παράδειγμα 5:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έναν ακέραιο και να εμφανίζει από πόσα ψηφία αποτελείται, 
    καθώς και το άθροισμα των ψηφίων του (π.χ. αν ο αριθμός είναι ο 1234, τα πρόγραμμα πρέπει να εμφανίζει 
    4 και 1+2+3+4 = 10).
*/

#include <stdio.h>

int main(void ){
	int num, sum, dig; 
	sum = dig = 0;
	printf ("Enter number: ");
	scanf("%d", &num);

	if (num < 0){
	    num = -num; // make it positive
    }
	else if (num == 0){	
		dig = 1; // Check the case where user entered 0 
    }

	while (num > 0)
	{
		sum += num % 10;
		num = num / 10;
		dig++;
	}
	printf("%d digits and their sum is %d\n", dig, sum);
	return 0;
}
/*
    Παράδειγμα 11: 
    Να γραφεί ένα πρόγραμµα το οποίο να διαβάζει εναν ακέραιο και τη θέση ενός bit 
    στον αριθμό και να εµφανίζει την τιµή του.
*/

#include <stdio.h>
int main(void)
{
	unsigned int num, pos;
	printf("Enter number: "); 
	scanf("%d",&num);
	printf("Enter bit position [1-32]:");
	scanf("%d", &pos);
	if(pos >= 1 && pos <= 32){
		printf("The value of bit%d is %d\n", pos,  (num>>(pos-1))&1);
    }
	else {
		printf("Bit position should be in [1-32]\n");
    }
	return 0;
}
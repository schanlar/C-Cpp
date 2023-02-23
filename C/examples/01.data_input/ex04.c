/*
    Παράδειγμα 4: Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει 3 βαθμούς 
    χωριμένους με κόμμα και να εμφανίζει το μέσο όρο τους.
*/


#include <stdio.h>

int main(void)
{
    float a, b, c;
    printf("Enter 3 grades separated by coma: ");
    scanf("%f,%f,%f", &a, &b, &c);
    printf("Mean grade: %.2f\n", (a+b+c)/3.0);
    return 0;
}
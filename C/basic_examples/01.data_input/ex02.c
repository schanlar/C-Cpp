/*
    Παράδειγμα 2: Ποια είναι η έξοδος του παρακάτω προγράμματος αν ο χρήστης 
    εισάγει τον αριθμό 1.23456789;
*/

#include <stdio.h> 
int main()
{
    float a;
    printf("Enter number: ");
    scanf("%f", &a);
    printf("%f\n", a);
    return 0;
}

/*
    The data type "float" is of single precision. This means it can hold
    information up to 6 decimal digits. So, the output will be: 
    1.234568, where the last digit was rounded up.
*/
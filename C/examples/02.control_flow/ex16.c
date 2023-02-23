/*
    Παράδειγμα 4:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει δύο πραγματικούς (π.χ. a και b) 
    χωρισμένους με κενό και να εμφανίζει τη λύση της εξίσωσης a * x + b = 0.
*/

#include <stdio.h>

int main(void){
    float a, b;
    printf("Enter two real numbers separated by space: ");
    scanf("%f %f", &a, &b);

    if (a == 0){
        printf("DIVISION ERROR: first number cannot be zero\n");
        return -1;
    }

    printf("The solution is: %f\n", (-b / a));
    return 0;
}
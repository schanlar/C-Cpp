/*
    Παράδειγμα 10: Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει δύο 
    πραγματικούς χωρισμένους με κενό και να εμφανίζει το άθροισμα των ακέραιων 
    και των δεκαδικών τμημάτων τους. Για παράδειγμα, αν ο χρήστης εισάγει τις 
    τιμές 1.23 και 9.56, το πρόγραμμα πρέπει να εμφανίζει 10 και 0.79.
*/

#include <stdio.h>

int main(void){
    float a, b;
    printf("Enter two real numbers separated by space: ");
    scanf("%f %f", &a, &b);
    
    printf("%d\n", (int) a + (int) b);
    printf("%.2f\n", (a - (int) a) + (b - (int) b));

    return 0;
}
/*
    Παράδειγμα 7: Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει δύο ακεραίους 
    χωρισμένους με κενό και να αντιμεταθέτει τις τιμές τους.
*/

#include <stdio.h>

int main(void){
    int a, b, tmp;
    printf("Enter two integers separated by space: ");
    scanf("%d %d", &a, &b);

    printf("Before swap: (%d, %d)\n", a, b);
    // Swap numbers
    tmp = a;
    a = b; 
    b = tmp;
    printf("After swap: (%d, %d)\n", a, b);

    return 0; 
}
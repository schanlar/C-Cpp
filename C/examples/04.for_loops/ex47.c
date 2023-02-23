/*
    Παράδειγμα 13:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει δύο ακεραίους και να εμφανίζει το άθροισμα 
    των μεταξύ τους ακέραιων. Για παράδειγμα, αν ο χρήστης εισάγει τις τιμές 3 και 8 το πρόγραμμα 
    να εμφανίζει 4 + 5 + 6 + 7 = 22.
*/

#include <stdio.h>

int main(void){
    int a, b, sum = 0;
    printf("Enter two integers separated by space: ");
    scanf("%d %d", &a, &b);

    // Account for the case the user provides a larger integer first
    if (a < b) {
        for (int i = a+1; i < b; i++){
            sum += i;
        }
    }
    else if (a > b){
        for (int i = a-1; i > b; i--){
            sum += i;
        }
    }
    else {
        printf("There are no integers between %d and %d\n", a, b);
        return 0;
    }

    printf("The sum is: %d\n", sum);
    return 0;
}
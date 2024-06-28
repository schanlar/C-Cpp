/*
    Παράδειγμα 7:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έναν ακέραιο και εάν αυτός ανήκει στο [10, 20] 
    να εμφανίζει πέντε φορές το τετράγωνο του αριθμού, αλλιώς να εμφανίζει δέκα φορές τη λέξη "One".
*/

#include <stdio.h>
#include <math.h>

int main(void){
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num >= 10 && num <= 20) {
        for (int i = 0; i < 5; i++){
            printf("%.0f\n", pow(num, 2));
        }
    }
    else {
        for (int i = 0; i < 10; i++){
            printf("One\n");
        }
    }
    return 0;
}
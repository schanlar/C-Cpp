/*
    Παράδειγμα 6: Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει έναν πραγματικό 
    και να εμφανίζει τον προηγούμενο και τον επόμενο ακέραιο.
*/

#include <stdio.h>

int main(void){
    float num;
    printf("Enter a real number: ");
    scanf("%f", &num);
    
    printf("%d %d\n", (int) num - 1, (int) num + 1);
    return 0;
}
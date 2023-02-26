/*
    Παράδειγμα 6: 
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τον βαθμό ενός μαθητή και να εμφανίζει τον χαρακτηρισμό 
    που αντιστοιχεί στον βαθμό του ως εξής:

    α)(18-20]: Excellent 
    β)(16-18]: Very Good 
    γ)(13-16]: Good 
    δ)[10-13]: Dangerous Zone 
    ε)[0-10) : Need Help
*/

#include <stdio.h>

int main(void){
    float grade;
    printf("Enter grade: ");
    scanf("%f", &grade);

    if (grade >= 18 && grade <= 20){
        printf("Excellent\n");
    }
    else if (grade >= 16 && grade < 18) {
        printf("Very Good\n");
    }
    else if (grade >= 13 && grade < 16) {
        printf("Good\n");
    }
    else if (grade >= 10 && grade < 13) {
        printf("Dangerous Zone\n");
    }
    else if (grade >= 0 && grade < 10) {
        printf("Need Help\n");
    }
    else {
        printf("ERROR: Invalid input; grade must be between 0 and 20\n");
        return -1;
    }
    return 0;
}
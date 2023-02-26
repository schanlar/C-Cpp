/*
    Παράδειγμα 13:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τους βαθμούς 100 φοιτητών και να αποθηκεύει 
    σε διαδοχικές θέσεις ενός πίνακα τους βαθμούς που ανήκουν στο [5,10] και σε έναν δεύτερο πίνακα 
    τους βαθμούς που ανήκουν στο [0,5). Η εισαγωγή βαθμών να τερματίζει αν ο χρήστης εισάγει την τιμή -1. 
    Το πρόγραμμα να εμφανίζει τον μέσο όρο των βαθμών των φοιτητών που πέρασαν και απέτυχαν στο μάθημα, αντίστοιχα.
*/

#include <stdio.h>

#define SIZE 100

int main(void){
    float grade, failGrades[SIZE], passGrades[SIZE], sumFail = 0.0, sumPass = 0.0;
    int studentsFail = 0, studentsPass = 0, bars = 25;

    for (int i = 0; i < SIZE; i++){
        initialize:
            printf("Enter a grade, or enter -1 to exit: ");
            scanf("%f", &grade);
            if (grade == -1) {
                if (i == 0) {
                    printf("No grades entered\nExiting...\n");
                    return 0;
                }
                break;
            }
            else if (grade >= 0 && grade < 5) {
                failGrades[i] = grade;
                sumFail += grade;
                studentsFail++;
            }
            else if (grade >= 5 && grade <= 10) {
                passGrades[i] = grade;
                sumPass += grade;
                studentsPass++;
            }
            else{
                printf("Invalid input! Try again\n");
                goto initialize;
            }
    }

    // int bars = 25;
    for (int i = 0; i < bars + 1; i++) printf("-");
    if (studentsFail != 0){
        printf("\nStudents failed: %d\n", studentsFail);
        printf("Avg fail grade: %.1f\n", sumFail / studentsFail);
    }
    else {
        printf("\nNo student failed\n");
    }

    for (int i = 0; i < bars + 1; i++) printf("-");
    if (studentsPass != 0){
        printf("\nStudents passed: %d\n", studentsPass);
        printf("Avg pass grade: %.1f\n", sumPass / studentsPass);
    }
    else {
        printf("\nNo student passed\n");
    }
    for (int i = 0; i < bars + 1; i++) printf("-");
    printf("\n");


    return 0;
}
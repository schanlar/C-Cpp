/*
    Παράδειγμα 5:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει και να αποθηκεύει τους βαθμούς 100 φοιτητών
    σε 10 μαθήματα σε έναν πίνακα 100 x 10 και να εμφανίζει τον μέσο όρο, τον μικρότερο και 
    τον μεγαλύτερο βαθμό κάθε φοιτητή. Επίσης, να εμφανίζει τους φοιτητές που έχουν τον καλύτερο 
    και τον χειρότερο μέσο όρο. Αν βρεθούν δύο φοιτητές με τον ίδιο καλύτερο ή χειρότερο μέσο όρο 
    να εμφανίζει τον πρώτο που θα βρει. Το πρόγραμμα να υποχρεώνει τον χρήστη να εισάγει βαθμό στο [0, 10].
*/

#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

#define STUDENTS_SIZE 100
#define COURSES_SIZE 10

int main(void){
    // srand(time(NULL)); // for debugging

    float grade, catalog[STUDENTS_SIZE][COURSES_SIZE] = {0};
    float studentMin, studentMax, studentSum, studentAvgs[STUDENTS_SIZE] = {0};
    float overallMin = 100.0, overallMax = -100.0;

    for (int s = 0; s < STUDENTS_SIZE; s++){
        studentMin = 100.0; // reset for each student
        studentMax = -100.0; // reset for each student
        studentSum = 0.0; // reset for each student
        for (int c = 0; c < COURSES_SIZE; c++){
            do {
                printf("Enter grade [0, 10]: ");
                scanf("%f", &grade);
                // grade = (rand() % 10) + 1; // for debugging
            } while(grade < 0 || grade > 10);

            catalog[s][c] = grade; // populate array with valid grade
            studentSum += catalog[s][c];

            if (catalog[s][c] < studentMin) {
                studentMin = catalog[s][c];
            }

            if (catalog[s][c] > studentMax) {
                studentMax = catalog[s][c];
            }
        }

        studentAvgs[s] = studentSum / COURSES_SIZE;
        printf("----------------------------\n");
        printf("Student #%d\n", s+1); // Be carefull how we label each student
        printf("Min grade: %.1f\n", studentMin);
        printf("Max grade: %.1f\n", studentMax);
        printf("Avg grade: %.1f\n", studentAvgs[s]);
    }

    int posMax, posMin;
    for (int i = 0; i < STUDENTS_SIZE; i++){
        if (studentAvgs[i] < overallMin) {
            overallMin = studentAvgs[i];
            posMin = i;
        }

        if (studentAvgs[i] > overallMax) {
            overallMax = studentAvgs[i];
            posMax = i;
        }
    }
    printf("----------------------------\n");
    printf("Best avg grade: %.1f by student #%d\n", overallMax, posMax+1); // +1 because we labeled student with 
                                                                           // a starting index of 1 instead of 0
    printf("Worst avg grade: %.1f by student #%d\n", overallMin, posMin+1);

    // // for debugging
    // printf("----------------------------\n");
    // for (int s = 0; s < STUDENTS_SIZE; s++){
    //     for (int c = 0; c < COURSES_SIZE; c++){
    //         printf("%5.1f ", catalog[s][c]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
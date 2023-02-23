/*
    Παράδειγμα 10:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τους βαθμούς 100 φοιτητών και να τους αποθηκεύει 
    σε έναν πίνακα. Στη συνέχεια, να εμφανίζει τον μέσο όρο, τον μεγαλύτερο και τον μικρότερο βαθμό 
    καθώς και ποιοι φοιτητές τους έχουν.(Σημ. αν υπάρχουν παραπάνω από ένας φοιτητές με τον ίδιο μεγαλύτερο 
    ή μικρότερο βαθμό να εμφανίζεται ο πρώτος που θα βρεθεί).
    Το πρόγραμμα να υποχρεώνει τον χρήστη να εισάγει έναν βαθμό στο [0,10].
*/

#include <stdio.h>

#define SIZE 10

int main(void){
    
    float grade, studentGrades[SIZE], minGrade = 100.0, maxGrade = -100.0, sumGrade = 0.0;
    int maxPos, minPos;

    for (int i = 0; i <SIZE; i++){
        do {
            printf("Enter a grade: ");
            scanf("%f", &grade);
        } while (grade < 0 || grade > 10);

        // Append grade to array
        studentGrades[i] == grade;
        sumGrade += grade;

        if (grade < minGrade) {
            minGrade = grade;
            minPos = i; // Store the position of the min grade
        }

        if (grade > maxGrade) {
            maxGrade = grade;
            maxPos = i; // Store the position of the max grade
        }

        // Check for max/min grade at the end of the array initialization
        // to avoid a second for-loop
        // if (i == SIZE - 1) {
        //     printf("First student with min grade: student at index %d\n", minPos);
        //     printf("First student with max grade: student at index %d\n", maxPos);
        // }
    }
    printf("------\n");
    printf("Min: %.1f\nMax: %.1f\nAvg: %.1f\n", minGrade, maxGrade, sumGrade / SIZE);
    printf("First student with min grade: student at index %d\n", minPos);
    printf("First student with max grade: student at index %d\n", maxPos);
    return 0;
}

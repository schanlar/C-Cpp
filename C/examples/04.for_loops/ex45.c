/*
    Παράδειγμα 11:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τη βαθμολογία 100 φοιτητών σε ένα μάθημα 
    και πριν τερματίσει να εμφανίζει τον μέσο όρο των επιτυχόντων και αποτυχόντων 
    (σημ. επιτυχόντες θεωρούνται οι φοιτητές με βαθμό >= 5). Αν ο βαθμός που θα εισάγει ο χρήστης 
    δεν ανήκει στο [0,10] να μην λαμβάνεται υπόψη και ο χρήστης να ενημερώνεται για το λάθος του ώστε 
    να εισάγει αποδεκτή τιμή. Επίσης, η εισαγωγή βαθμών να τερματίζει αν ο χρήστης εισάγει την τιμή -1 σαν βαθμό.
*/

#include <stdio.h>

int main(void){
    int studentsPassed = 0, studentsFailed = 0;
    float meanPassed = 0.0, meanFailed = 0.0, sumPassed = 0.0, sumFailed = 0.0;
    for (int i = 0; i < 10; i++){
        float grade = 0;
        while (1) {
            printf("Enter grade in [1,10]: ");
            scanf("%f", &grade);

            if (grade == -1) {
                goto findMean; // only case where goto is still usefull: to break out of nested loops
            }
            else if (grade < 0 || grade > 10){
                printf("You entered an invalid grade. Try again:\n");
            }
            else {
                if (grade >= 5){
                    studentsPassed += 1;
                    sumPassed += grade;
                }
                else {
                    studentsFailed += 1;
                    sumFailed += grade;
                }
                break; // make sure we break out of the infinite loop
            }
        }
    }

    // location tag
    findMean:
        if (studentsPassed != 0){
            meanPassed = sumPassed / studentsPassed;
        }

        if (studentsFailed != 0){
            meanFailed = sumFailed / studentsFailed;
        }

        printf("Students passed: %d; Mean grade: %.1f\n", studentsPassed, meanPassed);
        printf("Students failed: %d; Mean grade: %.1f\n", studentsFailed, meanFailed);
        
    return 0;
}
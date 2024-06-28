/*
    Παράδειγμα 15:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τον αριθμό των φοιτητών μίας τάξης και στη συνέχεια 
    να διαβάζει τον τελικό βαθμό του κάθε φοιτητή. Το πρόγραμμα να εμφανίζει τον μέσο όρο των βαθμών, 
    το μικρότερο και το μεγαλύτερο βαθμό, καθώς και πόσοι φοιτητές έχουν τον ίδιο μεγαλύτερο βαθμό.
*/

#include <stdio.h>

int main(void){

    int numberOfStudents, maxGradeStudents = 0;
    float finalGrade, avgGrade, sumGrade = 0.0, minGrade = 100.0, maxGrade = -100.0;

    do {
        printf("Enter total number of students: ");
        scanf("%d", &numberOfStudents);

        if (numberOfStudents == 0) {
            printf("Exiting...\n");
            return 0;
        }
    } while (numberOfStudents < 0);

    for (int i = 0; i < numberOfStudents; i++) {
        do {
            printf("Enter final grade of student [0, 10]: ");
            scanf("%f", &finalGrade);
        } while (finalGrade < 0 || finalGrade > 10);
        
        

        if (finalGrade < minGrade) {
            minGrade = finalGrade;
        }
        

        if (finalGrade > maxGrade) {
            maxGrade = finalGrade;
            maxGradeStudents = 1; // (Re)-initialization of number of students with max grade
        }
        else if (finalGrade == maxGrade){
            maxGradeStudents += 1;
        }

        sumGrade += finalGrade;
    }
    
    avgGrade = sumGrade / numberOfStudents;

    printf("Average grade: %.1f\nMin grade: %.1f\nMax grade: %.1f\n", avgGrade, minGrade, maxGrade);
    printf("Number of students with grade %.1f: %d\n", maxGrade, maxGradeStudents);


    return 0;
}
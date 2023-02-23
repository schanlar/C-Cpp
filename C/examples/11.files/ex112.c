/*
    Παράδειγμα 6:
    Θεωρείστε ότι κάθε γραμμή του αρχείου κειμένου students.txt περιέχει ονόματα φοιτητών και 
    τους βαθμούς τους σε δύο μαθήματα με την ακόλουθη μορφή:

        Κώστας		Λυγνός		7		8.5
        Γιάννης		Αναστασίου	5.5		6.5

    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει κάθε γραμμή του αρχείου students.txt και να 
    αποθηκεύει σε ένα δεύτερο αρχείο suc.txt τα στοιχεία των φοιτητών που έχουν μέσο όρο 
    μεγαλύτερο ή ίσο του 5, ενώ σε ένα τρίτο αρχείο fail.txt τα στοιχεία των φοιτητών με μέσο 
    όρο μικρότερο του 5. Το πρόγραμμα να εμφανίζει τον αριθμό των επιτυχόντων και αποτυχόντων 
    φοιτητών, πριν τερματίσει.
*/

#include <stdio.h>
#define MAX_SIZE 20

int main(void){
    float grade1, grade2, avgGrade;
    char firstName[MAX_SIZE], lastName[MAX_SIZE];
    int readLines, studentsPassed = 0, studentsFailed = 0;

    FILE *inFile = NULL;
    FILE *sucFile = NULL;
    FILE *failFile = NULL;
    inFile = fopen("students.txt", "r");
    sucFile = fopen("suc.txt", "w");
    failFile = fopen("fail.txt", "w");
    if (inFile == NULL){
        printf("ERROR: could not open file students.txt\n");
        return -1;
    }
    if (sucFile == NULL){
        printf("ERROR: could not create file suc.txt\n");
        return -1;
    }
    if (failFile == NULL){
        printf("ERROR: could not create file fail.txt\n");
        return -1;
    }

    while (!feof(inFile)){
        /*
            Comment: The fscanf() function returns the number of fields that
            it successfully converted and assigned, or EOF if an input failure
            occurs before any conversion.
        */
        readLines = fscanf(inFile, "%s\t%s\t%f\t%f", firstName, lastName, &grade1, &grade2);
        if (readLines == 4){
            avgGrade = (grade1 + grade2) / 2.0;
            if (avgGrade >= 5.0){
                // printf("%s %s passed with an average grade of %.1f\n", firstName, lastName, avgGrade);
                fprintf(sucFile, "%s\t%s\t%.1f\n", firstName, lastName, avgGrade);
                studentsPassed++;
            }
            else {
                // printf("%s %s failed with an average grade of %.1f\n", firstName, lastName, avgGrade);
                fprintf(failFile, "%s\t%s\t%.1f\n", firstName, lastName, avgGrade);
                studentsFailed++;
            }
        }
    }
    fclose(inFile);
    fclose(sucFile);
    fclose(failFile);

    printf("Students passed: %d\n", studentsPassed);
    printf("Students failed: %d\n", studentsFailed);

    return 0;
}
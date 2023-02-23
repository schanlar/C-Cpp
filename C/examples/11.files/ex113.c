/*
    Παράδειγμα 7:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει τα ονόματα δύο αρχείων 
    και να εμφανίζει την πρώτη κοινή γραμμή τους.
    Θεωρείστε ότι κάθε γραμμή του αρχείου έχει λιγότερους από 100 χαρακτήρες.
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main(void){

    char filename1[MAX_SIZE], filename2[MAX_SIZE], line1[MAX_SIZE], line2[MAX_SIZE];
    int found = 0;

    FILE *ptrFile1 = NULL;
    printf("Enter file name: ");
    scanf(" %s", filename1);
    ptrFile1 = fopen(filename1, "r");
    if (ptrFile1 == NULL){
        printf("ERROR: could not open file \"%s\"\n", filename1);
        return -1;
    }
    
    FILE *ptrFile2 = NULL;
    printf("Enter file name: ");
    scanf(" %s", filename2);
    ptrFile2 = fopen(filename2, "r");
    if (ptrFile2 == NULL){
        printf("ERROR: could not open file \"%s\"\n", filename2);
        return -1;
    }

    while (1){
        if (fgets(line1, MAX_SIZE, ptrFile1) == NULL || fgets(line2, MAX_SIZE, ptrFile2) == NULL){
            break;
        }
        if (strcmp(line1, line2) == 0){
            found = 1;
            break;
        }
    }


    fclose(ptrFile1);
    fclose(ptrFile2);
    if (!found){
        printf("The two files have no common lines\n");
    }
    else {
        printf("Common line: %s\n", line1);
    }
    return 0;
}
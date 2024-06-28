/*
    Παράδειγμα 1:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει συνεχώς τιμές προϊόντων και να γράφει 
    σε ένα αρχείο κειμένου αυτές που είναι μεγαλύτερες από 10€ και μικρότερες από 20€. 
    Αν ο χρήστης εισάγει την τιμή -1, η εισαγωγή των τιμών να τελειώνει.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
char* concat(const char* s1, const char* s2);


int main(void){
    float price;
    char *mainPath = "/Users/schanlar/Desktop/Stuff/coding_sandbox/C/basics/examples/11.files/";
    char *fileName = "catalog.txt";
    char *filePath = concat(mainPath, fileName); // or find another way using strcat

    FILE* ptrFile = NULL;
    ptrFile = fopen(filePath, "w");
    if (ptrFile == NULL){
        printf("ERROR: could not open file \"%s\" in %s", fileName, mainPath);
        return -1;
    }

    do{
        printf("Enter price or -1 to exit: ");
        scanf("%f", &price);

        if (price > 10 && price < 20) {
            fprintf(ptrFile, "%f\n", price);
        }
    } while (price != -1);
    fclose(ptrFile);
    free(filePath); // Deallocate memory
    return 0;
}

char* concat(const char* s1, const char* s2) {
    char* newString = (char*) malloc(sizeof(s1) + sizeof(s2));
    int i;
    for (i = 0; i < strlen(s1); i++) {
        newString[i] = s1[i];
    }
    
    for (int j = 0; j <= strlen(s2); j++) {
        newString[i] = s2[j];
        i++;
    }
    return newString;
}
/*
    Παράδειγμα 5:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει συνεχώς τις τιμές και τους 
    αντίστοιχους κωδικούς (λιγότεροι από 20 χαρακτήρες) προϊόντων και να 
    αποθηκεύει τα δεδομένα σε ένα αρχείο κειμένου ως εξής:

        C101 17.5
        C102 32.8
        ...

    Αν ο χρήστης εισάγει τη τιμή -1 ως τιμή προϊόντος, η εισαγωγή των προϊόντων να τερματίζει.
    Στη συνέχεια, το πρόγραμμα να διαβάζει τον κωδικό ενός προϊόντος και να ψάχνει το αρχείο 
    για να βρει και να εμφανίσει τη τιμή του.
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

int main(void){

    char productCode[MAX_SIZE], searchCode[MAX_SIZE];
    char* fileName = "catalog.txt";
    float productPrice;
    int  codeFound = 0;

    FILE* outFile = NULL;
    outFile = fopen(fileName, "w");
    if (outFile == NULL){
        printf("ERROR: could not create the file \"%s\"\n", fileName);
        return -1;
    }

    while (1) {
        printf("Enter product code and price separated by space: ");
        scanf(" %s %f", productCode, &productPrice);
        if (productPrice == -1){
            break;
        }
        else {
            fprintf(outFile, "%s %.1f\n", productCode, productPrice);
        }
    }
    fclose(outFile);

    FILE* inFile = NULL;
    inFile = fopen(fileName, "r");
    if (inFile == NULL){
        printf("ERROR: could not open the file \"%s\"\n", fileName);
        return -1;
    }

    printf("Search product code: ");
    scanf(" %s", searchCode);
    while (!feof(inFile)){
        fscanf(inFile, "%s %f", productCode, &productPrice);
        if (strcmp(productCode, searchCode) == 0){
            codeFound = 1;
            break;
        }
    }
    if (!codeFound){
        printf("The product is not listed\n");
    }
    else {
        printf("Product code: %s\nProduct price: %.1f\n", productCode, productPrice);
    }

    fclose(inFile);
    return 0;
}
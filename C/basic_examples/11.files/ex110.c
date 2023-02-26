/*
    Παράδειγμα 4:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει το όνομα ενός αρχείου για εγγραφή.
    Αν το αρχείο δεν υπάρχει, να το δημιουργεί και να γράφει τη λέξη "One" σε αυτό.
    Αν υπάρχει, το πρόγραμμα να ρωτάει το χρήτη αν επιθυμεί να συνεχίσει την υπεργγραφή του αρχείου και, 
    αν απαντήσει θετικά, να γράψει τη λέξη "One"σε αυτό. Αν απαντήσει αρνητικά, να μπορεί να επιλέξει ένα 
    άλλο όνομα αρχείου, με σκοπό να επαναληφθεί η παραπάνω διαδικασία.
*/

#include <stdio.h>
#include <unistd.h> // this is a standard header for Unix-like systems, and is not available on Windows

int main(int argc, char *argv[]){

    if (argc != 2) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename\n", argv[0] );
        return -1;
    }

    char answer;
    char *file = argv[1];
    FILE *ptrFile = NULL;
   
    int fileExists;
    checkFile:
        fileExists = access(file, F_OK); // = 0 if file exists, otherwise = -1
        // Check documentation: https://pubs.opengroup.org/onlinepubs/009695299/functions/access.html
    
    if (fileExists == 0) {
        while (1) {
            printf("This file already exists! Do you want to overwrite it? [y/n] ");
            scanf(" %c", &answer);
            /*
                Comment: 
                scanf() takes the input that matches the format string, 
                returning the number of characters consumed. 
                Any character that doesn't match the format causes it to 
                stop scanning and leaves the invalid character still in the buffer.
                The space before %c accounts for leading/trailing space, and prevents
                strange behaviour.
            */
            if (answer == 'y') {
                ptrFile = fopen(file, "w");
                if (ptrFile == NULL){
                    printf("ERROR: could not open the file\n");
                    return -1;
                }
                fprintf(ptrFile, "%s\n", "One");
                fclose(ptrFile);
                return 0;
            }
            else if (answer == 'n') {
                while (1) {
                    printf("Do you want to enter another file? [y/n] ");
                    scanf(" %c", &answer);
            
                    if (answer == 'n'){
                        printf("Exiting\n");
                        return 0;
                    }
                    else if (answer == 'y'){
                        printf("Enter file name: ");
                        scanf(" %s", file);
                        goto checkFile;
                    }
                }
            }
        }
    }
    else {
        ptrFile = fopen(file, "w");
        if (ptrFile == NULL) {
            printf("ERROR: could not create file %s\n", file);
            return -1;
        }
        fprintf(ptrFile, "%s\n", "One");
        fclose(ptrFile);
        return 0;
    }
}
/*
    Παράδειγμα 2:
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει συνεχώς αλφαριθμητικά (έως 100 χαρακτήρες το καθένα) 
    και να προσθέτει σε ένα αρχείο κειμένου που θα εισάγει ο χρήστης αυτά που έχουν λιγότερους από 
    10 χαρακτήρες και αρχίζουν με 'a'. Αν ο χρήστης εισάγει το "final", η εισαγωγή των αλφαριθμητικών 
    να τερματίζει και το πρόγραμμα να εμφανίζει πόσα αλφαριθμητικά γράφτηκαν στο αρχείο.
*/

#include <stdio.h>
#include <string.h>

#define SIZE 100

// Function prototype
void stripNewLine(char *str);

int main(int argc, char* argv[]){

    if (argc != 2) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename\n", argv[0] );
        return -1;
    }

    char word[SIZE];
    int counter = 0;
    FILE* ptrFile = NULL;
    ptrFile = fopen(argv[1], "w");

    if (ptrFile == NULL) {
        printf("ERROR: could not open file\n");
        return -1;
    }

    while (1){
        printf("Enter word: ");
        fgets(word, SIZE, stdin);
        stripNewLine(word);

        if (strcmp(word, "final") == 0){
            printf("%d words added to file\n", counter);
            break;
        }
        
        if (strlen(word) < 10 && word[0] == 'a'){
            fprintf(ptrFile, "%s\n", word);
            counter++;
        }
    }
    fclose(ptrFile);
    return 0;
}

void stripNewLine(char *str){
    /*
        Removes the newline character from the end of a string
        entered using fgets.
    */
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == '\n'){
            str[i] = '\0';
            return;
        }
    }
}
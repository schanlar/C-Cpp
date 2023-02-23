/*
    Παράδειγμα 8:
    Να γραφεί πρόγραμμα το οποίο να διαβάζει το όνομα ενός αρχείου 
    και να εμφανίζει το περιεχόμενο της δεύτερης γραμμής του.
*/

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function prototype
void stripNewLine(char *str);

int main(void){

    char line[MAX_LINE_LENGTH], filename[MAX_LINE_LENGTH];
    int counter = 0;
    FILE *ptrFile = NULL;

    printf("Enter file name: ");
    scanf(" %s", filename);

    ptrFile = fopen(filename, "r");
    if (ptrFile == NULL) {
        printf("ERROR: could not open file \"%s\"\n", filename);
        return -1;
    }

    while (1){
        counter++;
        if (fgets(line, MAX_LINE_LENGTH, ptrFile) != NULL){
            if (counter == 2){
                stripNewLine(line);
                printf("%s\n", line);
                break;
            }
        }
        else{
            break;
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
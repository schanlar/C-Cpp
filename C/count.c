/*
    Write a program that takes a file as an argument and counts the total number of lines.
    Lines are defined as ending with a newline character.
    Program usage should be
        count filename
    and the output should be the line count.
*/

#include <stdio.h>
#include <string.h>

#define LINE_SIZE_MAX 1024

int main(int argc, char** argv){
    if (argc != 2){
        printf("ERROR: input should be of the form: \"count filename\"\n");
        return -1;
    }
    int counter = 0;
    char fileName[64], line[LINE_SIZE_MAX];
    strcpy(fileName, argv[1]);
    FILE *file = NULL;
    file = fopen(fileName, "r");
    if (file == NULL){
        printf("ERROR: could not open file \"%s\"\n", fileName);
        return -1;
    }
    /*
        fgets(...): it stops when either (LINE_SIZE_MAX-1) characters are read,
        the newline character is read, or the end-of-file is reached,
        whichever comes first.
        If the End-of-File is encountered and no characters have been read,
        the contents of str remain unchanged and a null pointer is returned.
    */
    while (fgets(line, LINE_SIZE_MAX, file) != NULL){
        counter++;
    }
    fclose(file);
    printf("Number of lines: %d\n", counter);
    return 0;
}
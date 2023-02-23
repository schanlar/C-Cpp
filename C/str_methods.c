#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// int len(const char* string){
//     int i = 0;
//     while (1) {
//         if (string[i] == '\0') {
//             break;
//         }
//         i++;
//     }
//     return i;
// }

size_t len(const char *str){
    size_t length = 0;
    for(int i = 0; str[i] != '\0'; i++){
        length++;
    }
    return length;
}


void stripNewLine(char *str){
    /*
        Removes the newline from the end of a string
        entered using fgets.
    */
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == '\n'){
            str[i] = '\0';
            return;
        }
    }
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


char *capitalize (const char *input) {
    /*
        Converts the first character to upper case.
    */
  char *output = (char *) malloc (sizeof (input));

  for (int i = 0; i <= strlen(input); i++) {
      int ascii = (int) input[0];
      if (ascii >= 97 && ascii <= 122) {
	    ascii = ascii - 32;
      }

      if (i == 0) {
	    output[i] = (char) ascii;
      }
      else if (i == strlen(input)) {
    	  // Add null terminator
    	  output[i] = '\0';
      }
      else {
	    output[i] = input[i];
      }
  }
    return output;
}


int count(const char* input, char key) {
    /*
        Returns the number of times a specified character
        occurs in a string.
    */
    int counter = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == key) {
            counter++;
        }
    }
    return counter;
}


bool endswith(const char* input, char key) {
    /*
        Returns TRUE if the the string ends with the specified value.
    */
    int endIdx = strlen(input) - 1;
    if (input[endIdx] == '\n') {
        // fgets was used and a newline character was added
        // at the end of the string -> decrement index by one
        endIdx--;
    }
    
    if (input[endIdx] == key) {
        return true;
    }
    else {
        return false;
    }
}


int find(const char* input, char key) {
    /*
        Searches the string for a specified value and returns the position (index)
        of where it was found.
    */
    bool found = false;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == key) {
            found = true;
            return i;
        }
    }
    if (!found) {
        printf("Error: substring not found\n");
        return -1;
    }
}


bool isempty(const char* input) {
    /*
        Returns TRUE if string is empty.
    */
    if (input[0] == '\n' || input[0] == '\0') {
        return true;
    }
    return false;
}


bool islowercase(const char* input) {
    /*
        Returns TRUE if all characters in string are lower case.
    */
    int endIdx = strlen(input) - 1;
    if (input[endIdx] == '\n') {
        endIdx--;
    }
    for (int i = 0; i <= endIdx; i++) {
        int ascii = (int) input[i];
        if (ascii >= 97 && ascii <= 122) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}


bool isuppercase(const char* input) {
    /*
        Returns TRUE if all characters in string are upper case.
    */
    int endIdx = strlen(input) - 1;
    if (input[0] == '\n' || input[0] == '\0') {
        return false;
    }
    else if (input[endIdx] == '\n') {
        endIdx--;
    }
    for (int i = 0; i <= endIdx; i++) {
        int ascii = (int) input[i];
        if (ascii >= 65 && ascii <= 90) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}


bool iswhitespace(const char* input) {
    /*
        Returns TRUE if all characters is the string are whitespaces.
    */
    int endIdx = strlen(input) - 1;
    if (input[0] == '\n' || input[0] == '\0') {
        return false;
    }
    else if (input[endIdx] == '\n') {
        endIdx--;
    }
    
    for (int i = 0; i <= endIdx; i++) {
        int ascii = (int) input[i];
        if (ascii != 32) {
            return false;
        }
    }
    return true;
}


char* lower(const char* input) {
    /*
        Converts a string into lower case.
    */
    
    // Allocate memory for the output string
    char* output = (char*) malloc(sizeof(input)); // Lowercase string
    
    // Iterate over all letters of input string
    for (int i = 0; i <= strlen(input); i++) {
        int ascii = (int) input[i]; // Cast letter to its decimal representation
        
        // Check if letter is uppercase, in which case convert it to lowercase
        if (ascii >= 65 && ascii <= 90) {
            ascii = ascii + 32;
        }
        
        // Append letters to the output string
        if (i < strlen(input)) {
            output[i] = (char) ascii;
        }
        else if (i == strlen(input)) {
            output[i] = '\0'; // Add the null terminator at the end 
        }
    }
    return output;
}


char* replace(const char* input, char oldKey, char newKey) {
    /*
        Returns a string where a specified value is replaced with a specified value.
    */
    char* output = (char*) malloc(sizeof(input));
    for (int i = 0; i <= strlen(input); i++) {
        if (input[i] == oldKey) {
            output[i] = newKey;
        }
        else {
            output[i] = input[i];
        }
    }
    return output;
}


bool startswith(const char* input, char key) {
    /*
        Returns TRUE if the the string starts with the specified value.
    */
    if (input[0] == key) {
        return true;
    }
    else {
        return false;
    }
}


char* swapcase(const char* input) {
    /*
        Swap cases, lower case becomes upper case and vice versa.
    */
    char* output = (char*) malloc(sizeof(input));
    for (int i = 0; i <= strlen(input); i++) {
        int ascii = (int) input[i];
        if (ascii >= 97 && ascii <= 122) {
            ascii = ascii - 32;
            output[i] = (char) ascii;
        }
        else if (ascii >= 65 && ascii <= 90) {
            ascii = ascii + 32;
            output[i] = (char) ascii;
        }
        else {
            output[i] = input[i];
        }
    }
    return output;
}


char* upper(const char* input) {
    /*
        Converts a string into upper case.
    */
    
    // Allocate memory for the output string
    char* output = (char*) malloc(sizeof(input)); // Uppercase string
    
    // Iterate over all letters of input string
    for (int i = 0; i <= strlen(input); i++) {
        int ascii = (int) input[i]; // Cast letter to its decimal representation
        
        // Check if letter is lowercase, in which case convert it to uppercase
        if (ascii >= 97 && ascii <= 122) {
            ascii = ascii - 32;
        }
        
        // Append letters to the output string
        if (i < strlen(input)) {
            output[i] = (char) ascii;
        }
        else if (i == strlen(input)) {
            output[i] = '\0'; // Add the null terminator at the end 
        }
    }
    return output;
}



/*
    This will work for string arrays, e.g. str[size],
    but not for string literals, e.g. char* str = "example",
    since the latter cannot be modified. The reason behind this
    is that string literals are stored in the read-only section
    of the memory, while string arrays are stored in stack.

    void replace(char* string, char oldKey, char newKey){
        for (int i = 0; i < len(string); i++){
            if (string[i] == oldKey) {
                string[i] = newKey;
            }
        }
        return;
    }
*/
/*
* Ο αλγόριθμος κρυπτογράφησης του Καίσαρα (Caesar Cipher) αντικαθιστά κάθε γράμμα της αλφαβήτου με ένα 
* άλλο γράμμα της αλφαβήτου το οποίο βρίσκεται κάποιες θέσεις πιο κάτω. 
* Π.χ. δοθέντος του αλφαριθμητικού "ΑΒΓ" και του κλειδιού 3, αυτό μετατρέπεται στο "ΔΕΖ" ("Α"+3 = "Δ").
* Γράψτε ένα πρόγραμμα το οποίο θα κρυπτογραφεί ένα αλφαριθμητικό με βάση ένα ακέραιο κλειδί (int key)
* και θα εμφανίζει το κρυπτογραφημένο αλφαριθμητικό.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 255

int main()
{
    char sentence[SIZE];
    printf("Enter a sentence you want to cipher: ");
    fgets(sentence, SIZE, stdin);
    
    // We could implement some constraints or handle
    // corner cases to avoid landing on non-printable characters
    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    system("clear"); // For Windows use system("cls");
    
    // Cipher text
    char cipheredSentence[SIZE];
    for (int i = 0; i < strlen(sentence); i++){
        int ascii = (int) sentence[i];
        ascii += key;
        cipheredSentence[i] = (char) ascii;
    }
    printf("Ciphered sentence: %s\n", cipheredSentence);
    
    // De-cipher text
    char originalSentence[SIZE];
    for (int i = 0; i < strlen(cipheredSentence); i++){
        int ascii = (int) cipheredSentence[i];
        ascii -= key;
        originalSentence[i] = (char) ascii;
    }
    printf("Original sentence: %s\n", originalSentence);
    
    // // Check if de-ciphered text is the same as the original
    // printf("%d\n", strcmp(originalSentence, sentence));
    
    return 0;
}
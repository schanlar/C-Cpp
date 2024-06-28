/*
    Παράδειγμα 4: 
    Ποια είναι η έξοδος του παρακάτω προγράμματος;
*/


#include <stdio.h> 
int main(void)
{
  int i;
    for(i = 12; i > 2; i-=5)
      printf("%d ",  i);
      printf("\nEnd = %d\n", i);
    return 0;
}

/*
    Απάντηση: 
    Αφού η for εντολή δεν έχει άγκιστρα,ο μεταγλωττιστής θεωρεί ότι το σώμα του βρόχου αποτελείται από μία μόνο εντολή, 
    δηλαδή από τη πρώτη printf(), παρά την παραπλανητική στοίχισή της, εκτελείται μόνο μία φορά, μετά το τέλος του for βρόχου. 
    Ας αναλύσουμε τις επαναλήψεις του for βρόχου:

    1η επανάληψη. Η τιμή του i γίνεται 12, άρα η συνθήκη i > 2 (12 > 2) είναι αληθής, επομένως το πρόγραμμα εμφανίζει 12.

    2η επανάληψη. Με την εντολή i-=5 ( i =  i - 5) το i γίνεται 7, άρα η συνθήκη i > 2 (7 > 2) είναι αληθής και το πρόγραμμα 
    εμφανίζει 7.

    3η επανάληψη. Με την εντολή i-=5 (i =  i - 5) το i γίνεται 2, άρα η συνθήκη i > 2 (2 > 2) δεν είναι αληθής και η εκτέλεση 
    του βρόχου τερματίζεται.

    Στη συνέχεια, η δεύτερη printf() εμφανίζει την τιμή του ί. Αρα, η έξοδος του προγράμματος είναι:
    
        12 7 
        End = 2
*/
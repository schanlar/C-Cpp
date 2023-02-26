/*
    Να γραφεί ένα πρόγραμμα που να διαβάζει σε έναν πίνακα από ένα αρχείο δεδομένων διάφορες τιμές χρόνου
    και σε έναν άλλον διάφορες τιμές θερμοκρασίας που λαμβάνονται σε κάποιο πείραμα γραμμικής αύξησης
    της θερμοκρασίας.
    Το αρχείο περιλάμβάνει μία επικεφαλίδα μίας γραμμής που περιγράφει την κάθε στήλη των δεδομένων.
    Χρησιμοποιώντας τα δεδομένα που είναι αποθηκευμένα στους δύο πίνακες, να υπολογίστε και να εκτυπώσετε
    τους συντελεστές της ευθείας ελαχίστων τετραγώνων που εκφράζει τη μεταβολή της θερμοκρασίας με τον χρόνο.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define FILENAME_SIZE 255

// Function prototype
int charcount(FILE* const fin );
void least_squares_coeff(const double* time, const double* temps,
    long int size, double* a_coeff_address, double* b_coeff_address
);

int main(int argc, char** argv){
    // Check the correct usage of executable
    if (argc != 2){
        printf("ERROR: usage: %s filename\n", argv[0]);
        return -1;
    }
    // Open dataset
    char fileName[FILENAME_SIZE];
    strcpy(fileName, argv[1]);
    FILE *dataFile = NULL;
    dataFile = fopen(fileName, "r");
    if (dataFile == NULL){
        printf("ERROR: could not open file \"%s\"\n", fileName);
        return -1;
    }

    // Skip header line by determining the number of 
    // characters it contains (i.e. size)
    int headerChars;
    headerChars = charcount(dataFile);
    fseek(dataFile, sizeof(char)*headerChars, SEEK_SET);

    // Arrays to store time/temperature measurements
    // Size of arrays will be dynamically allocated based on
    // size of dataset
    double *time = (double *) malloc(sizeof(double));
    double *temperature = (double *) malloc(sizeof(double));
    int numLines, idx = 0, numberOfElements = 0;
    double val1, val2;
    
    while(1){
        numLines = fscanf(dataFile, "%lf %lf", &val1, &val2);
        if (numLines == 2){
            numberOfElements++;
            time = (double*) realloc(time, sizeof(*time) * numberOfElements);
            temperature = (double*) realloc(temperature, sizeof(*temperature) * numberOfElements);
            time[idx] = val1;
            temperature[idx] = val2;
            printf("Time: %.1lf s Temperature: %.1lf C\n", time[idx], temperature[idx]);
            idx++;
        }
        else{
            break;
        }
    }
    
    // Least square coefficients: y = ax + b
    double a, b;
    least_squares_coeff(time, temperature, numberOfElements, &a, &b);
    printf("Least square linear fit: %.3lf x %c %.3lf\n", a, (b > 0)?'+':'-', (b > 0)?b:fabs(b));

    // Close dataset and deallocate memory
    fclose(dataFile);
    free(time);
    free(temperature);
    return 0;
}

int charcount(FILE* const fin )
{
    int c, count = 0;
    while(1)
    {
        c = fgetc( fin );
        if( c == EOF || c == '\n' )
            break;
        ++count;
    }
    return count;
}

void least_squares_coeff(const double* time, const double* temps,
    long int size, double* a_coeff_address, double* b_coeff_address)
{
    double sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumXY = 0.0, a, b;

    for (long int i = 0; i < size; i++) {
        sumXY += time[i] * temps[i];
        sumX += time[i];
        sumY += temps[i];
        sumX2 += time[i] * time[i];
    }
    a = ((size * sumXY) - (sumX * sumY)) / ((size * sumX2) - (sumX * sumX));
    b = (1 / (float) size) * (sumY - (a * sumX));

    *a_coeff_address = a;
    *b_coeff_address = b;
    return;
}
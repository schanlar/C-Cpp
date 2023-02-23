/*
    Να γραφεί ένα πρόγραμμα που να διαβάζει από το πληκτρολόγιο σε έναν πίνακα πέντε τιμές χρόνου
    και σε έναν άλλον πέντε τιμές θερμοκρασίας που λαμβάνονται σε κάποιο πείραμα γραμμικής αύξησης
    της θερμοκρασίας. Χρησιμοποιώντας τα δεδομένα που είναι αποθηκευμένα στους δύο πίνακες, να
    υπολογίστε και να εκτυπώσετε τους συντελεστές της ευθείας ελαχίστων τετραγώνων που εκφράζει
    τη μεταβολή της θερμοκρασίας με τον χρόνο.
*/

#include <stdio.h>
#include <math.h>

#define SIZE 5

int main(void){

    float time[SIZE], temperature[SIZE];
    double sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumXY = 0.0, a, b;

    printf("Enter 5 values for x (time)\n");
    for (int i = 0; i < 28; i++) printf("*");
    printf("\n");
    for (int i = 0; i < SIZE; i++){
        scanf("%f", &time[i]);
    }
    printf("\n");
    printf("Enter 5 values for y (temperature)\n");
    for (int i = 0; i < 35; i++) printf("*");
    printf("\n");
    for (int i = 0; i < SIZE; i++){
        scanf("%f", &temperature[i]);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        sumXY += time[i] * temperature[i];
        sumX += time[i];
        sumY += temperature[i];
        sumX2 += pow(time[i], 2);
    }

    a = ((SIZE * sumXY) - (sumX * sumY)) / ((SIZE * sumX2) - pow(sumX, 2));
    b = (1 / (float) SIZE) * (sumY - (a * sumX));
    printf("Least square linear fit: %.3lf x %c %.3lf\n", a, (b > 0)?'+':'-', (b > 0)?b:fabs(b));

    return 0;
}
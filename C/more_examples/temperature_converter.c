/*
    * In this challenge, write a program that takes in three arguments, a start temperature (in Celsius),
    an end temperature (in Celsius), and a step size.

    * Print out a table that goes from the start temperature to the end temperature, in steps of the 
    step size; you do not actually need to print the final end temperature if the step size does not exactly match. 
    
    * You should perform input validation: do not accept start temperatures less than a lower limit 
    (which your code should specify as a constant) or higher than an upper limit (which your code should also 
    specify).
    
    * You should not allow a step size greater than the difference in temperatures.
*/

#include <stdio.h>
#include <math.h>

#define CELSIUS_LOWER_LIMIT -273.15
#define CELSIUS_UPPER_LIMIT 50000.0

double C2F(double temp);

int main(void){

    double minTempCelsius, maxTempCelsius;
    int step, maxStepSize;

    do {
        printf("Enter a lower limit (limit >= -273.15 C): ");
        scanf("%lf", &minTempCelsius);
    } while (minTempCelsius < CELSIUS_LOWER_LIMIT);
    do {
        printf("Enter an upper limit (limit <= 50,000 C): ");
        scanf("%lf", &maxTempCelsius);
    } while (maxTempCelsius > CELSIUS_UPPER_LIMIT);
    maxStepSize = fabs(maxTempCelsius - minTempCelsius);
    do {
        printf("Enter a step in (0, 10]: ");
        scanf("%d", &step);
    } while (step <= 0 || step > 10 || step > maxStepSize);

    printf("%s\t\t%s", "Celsius", "Fahrenheit\n");
    printf("----------\t-------------\n");
    printf("%lf\t%lf\n", minTempCelsius, C2F(minTempCelsius));
    while (1){
        minTempCelsius += step;
        if (minTempCelsius > maxTempCelsius) {
            break;
        }
        printf("%lf\t%lf\n", minTempCelsius, C2F(minTempCelsius));
    }

    return 0;
}


/* Celsius to Fahrenheit converter */
double C2F(double temp){
    return (temp * 9.0 / 5.0) + 32.0;
}
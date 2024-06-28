/*
    Free fall onto the surface of a neutron star
*/

#include <stdio.h>
#include <math.h>

#define MSUN 1.9891e30
#define KM 1e3
#define MILLISEC 1e-3
#define G 6.67384e-11

typedef struct lander{
    double acceleration;
    double velocity;
    double position;
} LANDER;


int main(void){
    double starMass = 2 * MSUN;
    double starRadius = 12 * KM;
    double timeStep = 5e-6;
    double time = 0.0;
    int istep = 0;

    LANDER lander;
    FILE *outFile = NULL;
    outFile = fopen("out.data", "w");
    if (outFile == NULL){
        printf("ERROR: could not create file \"out.dat\"\n");
        return -1;
    }

    // Initialize position at 120 km above surface
    lander.velocity = 0.0;
    lander.position = 10 * starRadius;
    lander.acceleration = - G * starMass / pow(lander.position, 2);

    printf("pos = %4.3e vel = %4.3e acc = %4.3e\n",
        lander.position / starRadius, lander.velocity, lander.acceleration
    );

    while (fabs(lander.position) > starRadius && istep < 1000){
        lander.acceleration = - G * starMass / pow(lander.position, 2);
        lander.velocity += lander.acceleration * timeStep;
        lander.position += lander.velocity * timeStep;
        time += timeStep;
        istep++;

        printf("time = %3.2e (ms), pos = %3.2e (R), vel = %3.2e (m/s), acc = %3.2e (m/s^2)\n",
            time / MILLISEC, lander.position / starRadius, lander.velocity, lander.acceleration
        );

        fprintf(outFile, "%3.2e %3.2e %3.2e %3.2e\n",
            time / MILLISEC, lander.position / starRadius, lander.velocity, lander.acceleration
        );
    }
    fclose(outFile);
    return 0;
}
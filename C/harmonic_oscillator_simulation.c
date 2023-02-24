#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define springConstant 1 // Hooke's law: F = -kx
#define dampingCoefficient 0.1 // Set to > 0 for damped harmonic oscillator

// Basic properties of a massive object
typedef struct BALL{
    double mass;
    double position;
    double velocity;
    double acceleration;
} BALL;

void printBlanks(int num){
    for (int i = 0; i < num + 39; i++) printf(" ");
}

int main(void){

    // Declare and initialize
    double springForce, dampingForce;
    double timeStep = 0.1;
    BALL ball;
    ball.mass = 0.1;
    ball.velocity = 0;
    ball.acceleration = 0;
    ball.position = -40;

    // Run as long the displacement (or velocity) are "significant"
    // Larger values will terminate the simulation earlier
    // Smaller values will terminate the simulation later on
    while (fabs(ball.position) > 1.0 || fabs(ball.velocity) > 1.0){
        dampingForce = -ball.velocity * dampingCoefficient; // damping force is linearly dependent upon the velocity
        springForce = -springConstant * ball.position + dampingForce; // the damping force term is to create a damped oscillator
                                                                      // the oscillation will be subjected to exponential decay 
                                                                      // which depends upon the damping coefficient
        ball.acceleration = springForce / ball.mass; // a = F / m
        ball.velocity += ball.acceleration * timeStep; // u = at
        ball.position += ball.velocity * timeStep; // x = ut
        printBlanks(ball.position);
        printf("o\n");
        usleep(50000);
    }


    return 0;
}
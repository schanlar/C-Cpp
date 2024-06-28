#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRIES_MAX 10

int main(void){
    srand(time(NULL)); // seed
    int randomNumber = (rand() % 100) + 1; // random integer in [1,100]
    int guessNumber, score = 10, foundNumber = 0;

    for (int i = 0; i < TRIES_MAX; i++){
        do{
            printf("Guess a number in [1,100]: ");
            scanf("%d", &guessNumber);
        } while (guessNumber < 1 || guessNumber > 100);

        if (guessNumber > randomNumber) {
            printf("Guess lower!\n");
            score--;
        }
        else if (guessNumber < randomNumber) {
            printf("Guess higher!\n");
            score--;
        }
        else {
            foundNumber = 1;
            break;
        }
    }

    if (foundNumber) {
        printf("You won with a score of %d!\nThe number was: %d\n", score, randomNumber);
    }
    else {
        printf("You lost!\nThe number was: %d\n", randomNumber);
    }
    return 0;
}
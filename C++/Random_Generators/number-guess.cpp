/*
The user tries to guess a random number between 1 and 100
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

  int randomNumber;
  int guessNumber;
  int tries = 0;
  bool running = true; // flag variable

  srand(time(0));
  randomNumber = 1 + (rand() % 100);

  while (running) {
    cout << "Guess a number: " << endl;
    cin >> guessNumber;

    if (guessNumber == randomNumber){
      cout << "You guessed it! :)" << endl;
      cout << "See you next time!" << endl;
      tries++;
      running = false;
    }else if (guessNumber < randomNumber) {
      cout << "You have to go higher!" << endl;
      tries++;
    }else {
      cout << "You have to go lower!" << endl;
      tries++;
    }

  }

  cout << "#########################" << endl;
  cout << "Total number of tries: " << tries << endl;


  return 0;
}

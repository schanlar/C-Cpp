/*
Simulate a coin toss: a value of zero represents heads whilst a value of
one represents tails.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

  int randomNumber;
  int counterZeros = 0;
  int counterOnes = 0;

  // Use the time function as a seed for the random number generator
  srand(time(0));

  for (int i = 0; i < 100; i++) {
    randomNumber = rand()%2; // Modulo 2 ensures that we will get back
                             // only numbers between 0 and 1
    cout << randomNumber;

    if (randomNumber == 0) {
      cout << "--> Heads!" << endl;
      counterZeros++;
    }else{
      cout << "--> Tails!" << endl;
      counterOnes++;
    }
  }

  cout << "Total number of Heads: " << counterZeros << endl;
  cout << "Total number of Tails: " << counterOnes << endl;

  return 0;
}

#include <iostream>

using namespace std;


//Function prototype
int factorialCalculator(int x);


int main() {
  int number;

  cout << "Provide a number: " << endl;
  cin >> number;

  cout << number << "! = " << factorialCalculator(number) << endl;
  return 0;
}


int factorialCalculator(int x){
  // This is going to be a recursive function
  // For this reason, we have to make a base-case that will allow us
  // to exit the recursive function.

  if (x == 1){
    //When this condition is fulfilled, we will break out of the recursive
    //calling of our function
    return 1;
  }else {
    return x * factorialCalculator(x - 1); //recursion
  }

}
